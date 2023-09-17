import json

from os import path, remove

from conan import ConanFile
from conan.errors import ConanInvalidConfiguration
from conan.tools.cmake import CMake, CMakeToolchain, CMakeDeps, cmake_layout


class CommonLibSF(ConanFile):
    name = "commonlibsf"

    def set_version(self):
        self.version = json.load(open("./vcpkg.json", encoding="utf-8"))["version-date"]

    # Optional metadata
    license = "GPL-3.0-or-later"
    author = "Starfield Reverse Engineering"
    url = "https://github.com/Starfield-Reverse-Engineering/CommonLibSF"
    description = "A collaborative reverse-engineered library for Starfield"
    topics = ("Starfield", "Reverse Engineering", "C++")

    # Binary configuration
    settings = "os", "compiler", "build_type", "arch"
    options = {
        "xbyak": [True, False],
        "profile": ["dmn", "rmn", "dcn", "rcn", "dmm", "rmm", "dcm", "rcm"],
    }
    default_options = {"xbyak": False, "profile": "rmn"}

    # Sources are located in the same place as this recipe, copy them to the recipe
    exports_sources = (
        "CMakeLists.txt",
        "CMakePresets.json",
        "cmake/**",
        "src/**",
        "include/**",
        ".clang-format",
    )

    requires = "spdlog/1.12.0", "xbyak/6.73"

    def layout(self):
        build_type = "debug" if str(self.options.profile)[0] == "d" else "release"  # type: ignore
        compiler = "msvc" if str(self.options.profile)[1] == "m" else "clang-cl"  # type: ignore
        buildgen = "ninja" if str(self.options.profile)[2] == "n" else "msvc"  # type: ignore
        print(f"-------------------------------BUILDGEN: {buildgen}")
        cmake_layout(
            self,
            build_folder=f"out/build/build-{build_type}-{compiler}-{buildgen}-conan",
        )

    def generate(self):
        deps = CMakeDeps(self)
        deps.generate()
        buildgen = "Ninja" if str(self.options.profile)[2] == "n" else "MSVC"  # type: ignore
        tc = CMakeToolchain(self, generator=buildgen)  # type: ignore
        tc.generate()

        # Project requires using existing CMake presets, remove the generated user presets file.
        user_presets = path.join(self.source_folder, "CMakeUserPresets.json")  # type: ignore
        if path.exists(user_presets):
            remove(user_presets)

    def configure(self):
        if self.settings.os != "Windows":  # type: ignore
            raise ConanInvalidConfiguration("Windows is the only supported OS")
        if self.settings.compiler != "msvc" and self.settings.compiler != "clang":  # type: ignore
            raise ConanInvalidConfiguration(
                "Unsupported compiler provided, only MSVC and clang-cl are supported"
            )
        if self.settings.arch != "x86_64":  # type: ignore
            raise ConanInvalidConfiguration("x86_64 is the only supported architecture")

    def build(self):
        defs = {"SFSE_SUPPORT_XBYAK": "ON" if self.options.xbyak else "OFF", "CMAKE_PREFIX_PATH": path.join(self.build_folder, "generators")}  # type: ignore
        def_args = " ".join(['-D{}="{}"'.format(k, v) for k, v in defs.items()])
        build_type = "debug" if str(self.options.profile)[0] == "d" else "release"  # type: ignore
        compiler = "msvc" if str(self.options.profile)[1] == "m" else "clang-cl"  # type: ignore
        buildgen = "ninja" if str(self.options.profile)[2] == "n" else "msvc"  # type: ignore
        self.run(
            f"cmake -S {self.source_folder} -B {self.build_folder} --preset=build-{build_type}-{compiler}-{buildgen}-conan {def_args}"
        )
        self.run(
            f"cd ../../.. && cmake --build {self.build_folder} --preset={build_type}-{compiler}-{buildgen}-conan"
        )

    def package_info(self):
        self.cpp_info.libs = ["commonlibsf"]

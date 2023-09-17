import json

from os import path, remove

from conan import ConanFile
from conan.errors import ConanInvalidConfiguration
from conan.tools.cmake import CMake, CMakeToolchain, CMakeDeps, cmake_layout

cwd = path.dirname(path.abspath(__file__))


class CommonLibSF(ConanFile):
    name = "commonlibsf"

    def set_version(self):
        self.version = json.load(open(path.join(cwd, "vcpkg.json"), encoding="utf-8"))[
            "version-date"
        ]

    # Optional metadata
    license = "GPL-3.0-or-later"
    author = "Starfield Reverse Engineering"
    url = "https://github.com/Starfield-Reverse-Engineering/CommonLibSF"
    description = "A collaborative reverse-engineered library for Starfield"
    topics = ("Starfield", "Reverse Engineering", "C++")

    # Binary configuration
    settings = "os", "compiler", "build_type", "arch"
    options = {"xbyak": [True, False]}
    default_options = {"xbyak": False}

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
        cmake_layout(self)

    def generate(self):
        tc = CMakeToolchain(self, generator="Ninja")  # type: ignore
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

    def package_info(self):
        self.cpp_info.libs = ["commonlibsf"]

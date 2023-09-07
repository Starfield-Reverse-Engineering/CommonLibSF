# CommonLibSF

A collaborative reverse-engineered library for Starfield.

[![C++23](https://img.shields.io/static/v1?label=standard&message=c%2B%2B23&color=blue&logo=c%2B%2B&&logoColor=red&style=flat)](https://en.cppreference.com/w/cpp/compiler_support)
![Platform](https://img.shields.io/static/v1?label=platform&message=windows&color=dimgray&style=flat&logo=windows)
[![Game version](https://img.shields.io/badge/game%20version-1.7.23-orange)](#use)

## Build Dependencies

- [CMake 3.26+](https://cmake.org/)
  - Add this to your PATH
- [PowerShell](https://github.com/PowerShell/PowerShell/releases/tag/v7.3.6)
- [Vcpkg](https://github.com/microsoft/vcpkg)
  - Add the environment variable VCPKG_ROOT with the value as the path to the folder containing vcpkg
- [Visual Studio Community 2022](https://visualstudio.microsoft.com/)
  - Desktop development with C++

## Get started

### use example plugin template

(TODO)

### git submodule & linking in CMake

```ps
git submodule add https://github.com/Starfield-Reverse-Engineering/CommonLibSF.git extern/CommonLibSF
git submodule update -f --init
```

TODO: vcpkg registry

You should have the following in CMakeLists.txt to compile and link successfully:

```cmake
add_subdirectory(extern/CommonLibSF)
target_link_libraries(
	${PROJECT_NAME}
	PRIVATE
        CommonLibSF::CommonLibSF
)
```

## End User Dependencies

[Starfield Script Extender](https://www.nexusmods.com/starfield/mods/106)

## Notes

CommonLib is incompatible with SFSE and is intended to replace it as a static dependency. However, you will still need the runtime component.

## License

[GPL-3.0-or-later](COPYING) WITH [Modding Exception AND GPL-3.0 Linking Exception (with Corresponding Source)](EXCEPTIONS).

Specifically, the **Modded Code** is Starfield (and its variants) and **Modding Libraries** include [SFSE](https://sfse.silverlock.org/) ([GitHub link](https://github.com/ianpatt/sfse)).

# CommonLibSF

## A collaborative reverse-engineered library for Starfield.

[![C++23](https://img.shields.io/static/v1?label=standard&message=c%2B%2B23&color=blue&logo=c%2B%2B&&logoColor=red&style=flat)](https://en.cppreference.com/w/cpp/compiler_support)
![Platform](https://img.shields.io/static/v1?label=platform&message=windows&color=dimgray&style=flat&logo=windows)
[![Game version](https://img.shields.io/badge/game%20version-1.7.23-orange)](#Developing-with-CommonLibSF)
[![VCPKG_VER](https://img.shields.io/static/v1?label=vcpkg%20registry&message=2023-09-08&color=green&style=flat)](https://github.com/Starfield-Reverse-Engineering/Starfield-RE-vcpkg)
[![Main CI](https://img.shields.io/github/actions/workflow/status/Starfield-Reverse-Engineering/CommonLibSF/main_ci.yml)][CI]

## Build Dependencies

- [CMake 3.26+](https://cmake.org/)
  - Add this to your PATH
- [vcpkg](https://github.com/microsoft/vcpkg)
  - Add the environment variable `VCPKG_ROOT` with the value as the path to the folder containing vcpkg
- [Visual Studio 2022](https://visualstudio.microsoft.com/) with "Desktop development with C++"
  - clang-cl toolset and build support if using `clang-cl` configuration
- [PowerShell](https://github.com/PowerShell/PowerShell/releases)

## Developing with CommonLibSF

### Using the example plugin

(TODO)

### Including CommonLibSF in your project

Add the following to your `vcpkg-configuration`:

```json
"registries": [
  {
    "kind": "git",
    "repository": "https://github.com/Starfield-Reverse-Engineering/Starfield-RE-vcpkg",
    "baseline": "<SHA of latest commit to the above repository>",
    "packages": [
      "commonlibsf"
    ]
  }
]
```

And the following to your `CMakeLists.txt`:

```cmake
find_package(CommonLibSF CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME}
        PRIVATE
        CommonLibSF::CommonLibSF)
```

## End-User Dependencies

[Starfield Script Extender](https://www.nexusmods.com/starfield/mods/106)

## Notes

CommonLibSF is incompatible with SFSE and is intended to replace it as a static dependency&mdash;the runtime component is still required.

## License

[GPL-3.0-or-later][LICENSE] WITH [Modding Exception AND GPL-3.0 Linking Exception (with Corresponding Source)](EXCEPTIONS).

Specifically, the **Modded Code** is Starfield (and its variants) and **Modding Libraries** include [SFSE](https://sfse.silverlock.org/) ([GitHub link](https://github.com/ianpatt/sfse)).

For additional information on GPL licenses, see the [FSF FAQ](https://www.gnu.org/licenses/gpl-faq.en.html)

## Credits

This work is based on [CommonLibSSE][CommonlibSSE] created by [Ryan-rsm-McKenzie](https://github.com/Ryan-rsm-McKenzie) under an [MIT License][CommonLib_MIT]. Without him putting that together, much of the joint Bethesda RE scene would be drastically different. The MIT License is kept for historical purposes only and the [GPL](#License) governs this work. To the extent that you want the [MIT licensed code][CommonLib_MIT], please reference [CommonlibSSE and its forks][CommonlibSSE].

[CommonLib_MIT]: /CommonLibSF/LICENSES/COMMONLIB
[LICENSE]: COPYING
[CommonlibSSE]: https://github.com/Ryan-rsm-McKenzie/CommonLibSSE
[CI]: /CommonLibSF/actions/workflows/main_ci.yml

# CommonLibSF

## A collaborative reverse-engineered library for Starfield.

[![C++23](https://img.shields.io/static/v1?label=standard&message=c%2B%2B23&color=blue&logo=c%2B%2B&&logoColor=red&style=flat)](https://en.cppreference.com/w/cpp/compiler_support)
![Platform](https://img.shields.io/static/v1?label=platform&message=windows&color=dimgray&style=flat&logo=windows)
[![Game version](https://img.shields.io/badge/game%20version-1.7.29-orange)](#Developing-with-CommonLibSF)
[![VCPKG_VER](https://img.shields.io/static/v1?label=vcpkg%20registry&message=2023-09-17.3&color=green&style=flat)](https://github.com/Starfield-Reverse-Engineering/Starfield-RE-vcpkg)
[![Main CI](https://img.shields.io/github/actions/workflow/status/Starfield-Reverse-Engineering/CommonLibSF/main_ci.yml)](https://github.com/Starfield-Reverse-Engineering/CommonLibSF/actions/workflows/main_ci.yml)

## Build Dependencies

- [CMake v3.26+](https://cmake.org/) or [XMake v2.8.2+](https://github.com/xmake-io/xmake/releases)
  - Add this to your PATH
- [vcpkg](https://github.com/microsoft/vcpkg)
  - Add the environment variable `VCPKG_ROOT` with the value as the path to the folder containing vcpkg
- [Visual Studio 2022](https://visualstudio.microsoft.com/) with "Desktop development with C++"
  - clang-cl toolset and build support if using `clang-cl` configuration
- [PowerShell](https://github.com/PowerShell/PowerShell/releases)

## Developing with CommonLibSF

### Using the CommonLibSF plugin templates

You can choose from the following community plugin templates to speed up the setup process:

- [CLibSFPluginTemplate](https://github.com/Starfield-Reverse-Engineering/CLibSFPluginTemplate)
  - Uses **CMake**. Consumes CommonLibSF as a [vcpkg port package](https://github.com/Starfield-Reverse-Engineering/Starfield-RE-vcpkg).
- [SF_PluginTemplate](https://github.com/gottyduke/SF_PluginTemplate)
  - Uses **CMake**. Consumes CommonLibSF as a git submodule or local fork.
- [commonlibsf-template-xmake](https://github.com/Starfield-Reverse-Engineering/commonlibsf-template-xmake)
  - Uses **XMake**. Consumes CommonLibSF as an [xrepo package](https://github.com/Starfield-Reverse-Engineering/commonlibsf-xrepo).

### Including CommonLibSF in your project

#### vcpkg

[Instructions for consuming CommonLibSF using vcpkg are provided at our vcpkg registry repo.](https://github.com/Starfield-Reverse-Engineering/Starfield-RE-vcpkg)

#### xrepo

> Thanks to Qudix for maintaining the custom xmake repo!

Add the following to your `xmake.lua`:

```lua
-- add commonlibsf-xrepo repository
add_repositories("re https://github.com/Starfield-Reverse-Engineering/commonlibsf-xrepo")

-- require package dependencies
add_requires("commonlibsf")

target("name")
...
    -- bind packages to the target
    add_packages("commonlibsf")
```

#### git submodule

To consume CommonLibSF as a submodule, `cd` into your project directory and run:

```ps
git submodule add https://github.com/Starfield-Reverse-Engineering/CommonLibSF extern/CommonLibSF
git submodule update -f --init
```

Then add the following to your `CMakeLists.txt`:

```cmake
add_subdirectory(extern/CommonLibSF)
target_link_libraries(
  ${PROJECT_NAME}
  PRIVATE
  CommonLibSF::CommonLibSF
)
```

**NOTE**: You may also use the [custom `add_commonlibsf_plugin` command](https://github.com/Starfield-Reverse-Engineering/CommonLibSF/wiki/Miscellanous-Explanatory-Stuff#custom-cmake-command) instead of `target_link_libraries`.

## End-User Dependencies

[Starfield Script Extender](https://www.nexusmods.com/starfield/mods/106)

## Notes

CommonLibSF is incompatible with SFSE and is intended to replace it as a static dependency&mdash;the runtime component is still required.

## License

[GPL-3.0-or-later][LICENSE] WITH [Modding Exception AND GPL-3.0 Linking Exception (with Corresponding Source)](EXCEPTIONS).

Specifically, the **Modded Code** is Starfield (and its variants) and **Modding Libraries** include [SFSE](https://sfse.silverlock.org/) ([GitHub link](https://github.com/ianpatt/sfse)).

It is recommended to read the [FSF FAQ](https://www.gnu.org/licenses/gpl-faq.en.html) for a full explanation on what this license requires.

The main requirement of this license is: if you link your mod against CommonLibSF, and you distribute the binaries for that mod, you must also distribute the source code under the same license as CommonLibSF along with the source code for any other libraries you link against, with the exception of the Modded Code and Modding Libraries defined above.

## Contributors

<!--CONTRIBUTORS_BEGIN--><table><tr>
  <td align="center">
    <a href="https://github.com/ThirdEyeSqueegee" title="Angad">
      <img src="https://avatars.githubusercontent.com/u/66992519?v=4" width="50;" alt="Angad"/>
    </a>
  </td>
  <td align="center">
    <a href="https://github.com/gottyduke" title="DK">
      <img src="https://avatars.githubusercontent.com/u/35783662?v=4" width="50;" alt="DK"/>
    </a>
  </td>
  <td align="center">
    <a href="https://github.com/alandtse" title="Alan Tse">
      <img src="https://avatars.githubusercontent.com/u/7086117?v=4" width="50;" alt="Alan Tse"/>
    </a>
  </td>
  <td align="center">
    <a href="https://github.com/FlayaN" title="FlayaN">
      <img src="https://avatars.githubusercontent.com/u/964655?v=4" width="50;" alt="FlayaN"/>
    </a>
  </td>
  <td align="center">
    <a href="https://github.com/powerof3" title="powerof3">
      <img src="https://avatars.githubusercontent.com/u/32599957?v=4" width="50;" alt="powerof3"/>
    </a>
  </td>
</tr></table><!--CONTRIBUTORS_END-->

## Credits

This work is based on [CommonLibSSE][CLibSSE] created by [Ryan-rsm-McKenzie](https://github.com/Ryan-rsm-McKenzie) under an [MIT License][CommonLib_MIT]. Without him putting that together, much of the joint Bethesda RE scene would be drastically different. The MIT License is kept for historical purposes only and the [GPL](#License) governs this work. To the extent that you want the [MIT licensed code][CommonLib_MIT], please reference [CommonLibSSE and its forks][CLibSSE].

[CommonLib_MIT]: /CommonLibSF/LICENSES/COMMONLIB
[LICENSE]: COPYING
[CLibSSE]: https://github.com/Ryan-rsm-McKenzie/CommonLibSSE

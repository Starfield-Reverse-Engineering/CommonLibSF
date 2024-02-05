# CommonLibSF

## A collaborative reverse-engineered library for Starfield

[![C++23](https://img.shields.io/static/v1?label=standard&message=c%2B%2B23&color=blue&logo=c%2B%2B&&logoColor=red&style=flat)](https://en.cppreference.com/w/cpp/compiler_support)
![Platform](https://img.shields.io/static/v1?label=platform&message=windows&color=dimgray&style=flat&logo=windows)
[![Game version](https://img.shields.io/badge/game%20version-1.8.86-orange)](#Developing-with-CommonLibSF)
[![VCPKG_VER](https://img.shields.io/static/v1?label=vcpkg%20registry&message=2024-02-03&color=green&style=flat)](https://github.com/Starfield-Reverse-Engineering/Starfield-RE-vcpkg)
[![Main CI](https://img.shields.io/github/actions/workflow/status/Starfield-Reverse-Engineering/CommonLibSF/main_ci.yml)](https://github.com/Starfield-Reverse-Engineering/CommonLibSF/actions/workflows/main_ci.yml)

## Build Dependencies

- [CMake v3.26+](https://cmake.org/) or [XMake v2.8.2+](https://github.com/xmake-io/xmake/releases)
  - Add this to your `PATH`
- [vcpkg](https://github.com/microsoft/vcpkg) (optional, non-vcpkg build presets are provided which use [CPM.cmake](https://github.com/cpm-cmake/CPM.cmake) instead)
  - Create a Windows environment variable called `VCPKG_ROOT` with the value as the path to your vcpkg install directory
- [Visual Studio 2022](https://visualstudio.microsoft.com/) with "Desktop development with C++" workload
  - clang-cl toolset and build support if using `clang-cl` configurations
- [PowerShell](https://github.com/PowerShell/PowerShell/releases)

## Developing with CommonLibSF

### Using the CommonLibSF plugin templates

- [CLibSFPluginTemplate](https://github.com/Starfield-Reverse-Engineering/CLibSFPluginTemplate)
  - Uses **CMake**. Consumes CommonLibSF as a [CPM](https://github.com/cpm-cmake/CPM.cmake) package, a git submodule, or a local fork.
- [SF_PluginTemplate](https://github.com/gottyduke/SF_PluginTemplate)
  - Uses **CMake**. Consumes CommonLibSF as a git submodule or a local fork.
- [commonlibsf-template-xmake](https://github.com/Starfield-Reverse-Engineering/commonlibsf-template-xmake)
  - Uses **XMake**. Consumes CommonLibSF as an [xrepo package](https://github.com/Starfield-Reverse-Engineering/commonlibsf-xrepo), a git submodule, or a local fork.

### Please see the [Using CommonLibSF wiki page](https://github.com/Starfield-Reverse-Engineering/CommonLibSF/wiki/Using-CommonLibSF) for more information about using CommonLibSF.

## End-User Dependencies

- [Starfield Script Extender](https://www.nexusmods.com/starfield/mods/106)
- [Address Library for SFSE Plugins](https://www.nexusmods.com/starfield/mods/3256)

## Notes

CommonLibSF is intended to replace SFSE as a static dependency. However, the runtime component of SFSE is still required.

You may download the PDB for the latest build of CommonLibSF via the [Update PDB](https://github.com/Starfield-Reverse-Engineering/CommonLibSF/actions/workflows/update_pdb.yml) workflow. This is useful for importing the latest type information into IDA using the "import PDB" feature.

## License

[GPL-3.0-or-later][LICENSE] WITH [Modding Exception AND GPL-3.0 Linking Exception (with Corresponding Source)](EXCEPTIONS).

Specifically, the **Modded Code** is Starfield (and its variants) and **Modding Libraries** include [SFSE](https://sfse.silverlock.org/) ([GitHub link](https://github.com/ianpatt/sfse)).

It is recommended to read the [FSF FAQ](https://www.gnu.org/licenses/gpl-faq.en.html) for a full explanation on what this license requires.

The main requirement of this license is: if you link your mod against CommonLibSF, and you distribute the binaries for that mod, you must also distribute the source code under the same license as CommonLibSF along with the source code for any other libraries you link against, with the exception of the Modded Code and Modding Libraries defined above.

## Contributors

<!--CONTRIBUTORS_BEGIN--><table><tr>
  <td align="center">
    <a href="https://github.com/gottyduke" title="DK">
      <img src="https://avatars.githubusercontent.com/u/35783662?v=4" width="50;" alt="DK"/>
    </a>
  </td>
  <td align="center">
    <a href="https://github.com/ThirdEyeSqueegee" title="Angad">
      <img src="https://avatars.githubusercontent.com/u/66992519?v=4" width="50;" alt="Angad"/>
    </a>
  </td>
  <td align="center">
    <a href="https://github.com/powerof3" title="powerof3">
      <img src="https://avatars.githubusercontent.com/u/32599957?v=4" width="50;" alt="powerof3"/>
    </a>
  </td>
  <td align="center">
    <a href="https://github.com/Qudix" title="Qudix">
      <img src="https://avatars.githubusercontent.com/u/17361645?v=4" width="50;" alt="Qudix"/>
    </a>
  </td>
  <td align="center">
    <a href="https://github.com/nikitalita" title="nikitalita">
      <img src="https://avatars.githubusercontent.com/u/69168929?v=4" width="50;" alt="nikitalita"/>
    </a>
  </td>
  <td align="center">
    <a href="https://github.com/TommInfinite" title="TommInfinite">
      <img src="https://avatars.githubusercontent.com/u/81481291?v=4" width="50;" alt="TommInfinite"/>
    </a>
  </td>
  <td align="center">
    <a href="https://github.com/shad0wshayd3" title="shad0wshayd3">
      <img src="https://avatars.githubusercontent.com/u/2724172?v=4" width="50;" alt="shad0wshayd3"/>
    </a>
  </td>
  <td align="center">
    <a href="https://github.com/shadeMe" title="Madeesh Kannan">
      <img src="https://avatars.githubusercontent.com/u/214450?v=4" width="50;" alt="Madeesh Kannan"/>
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
    <a href="https://github.com/ianpatt" title="Ian Patterson">
      <img src="https://avatars.githubusercontent.com/u/292795?v=4" width="50;" alt="Ian Patterson"/>
    </a>
  </td>
  <td align="center">
    <a href="https://github.com/Bobbyclue" title="Bobbyclue">
      <img src="https://avatars.githubusercontent.com/u/97621924?v=4" width="50;" alt="Bobbyclue"/>
    </a>
  </td>
  <td align="center">
    <a href="https://github.com/gazzamc" title="Gary McGovern">
      <img src="https://avatars.githubusercontent.com/u/7975925?v=4" width="50;" alt="Gary McGovern"/>
    </a>
  </td>
  <td align="center">
    <a href="https://github.com/lStewieAl" title="lStewieAl">
      <img src="https://avatars.githubusercontent.com/u/16544747?v=4" width="50;" alt="lStewieAl"/>
    </a>
  </td>
</tr></table><!--CONTRIBUTORS_END-->

## Credits

This work is based on [CommonLibSSE][CLibSSE] created by [Ryan-rsm-McKenzie](https://github.com/Ryan-rsm-McKenzie) under an [MIT License][CommonLib_MIT]. Without him putting that together, much of the joint Bethesda RE scene would be drastically different. The MIT License is kept for historical purposes only and the [GPL](#License) governs this work. To the extent that you want the [MIT licensed code][CommonLib_MIT], please reference [CommonLibSSE and its forks][CLibSSE].

[CommonLib_MIT]: /CommonLibSF/LICENSES/COMMONLIB
[LICENSE]: COPYING
[CLibSSE]: https://github.com/Ryan-rsm-McKenzie/CommonLibSSE

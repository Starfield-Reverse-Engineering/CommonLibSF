# CommonLibSF

## A collaborative reverse-engineered library for Starfield

[![C++23](https://img.shields.io/static/v1?label=standard&message=c%2B%2B23&color=blue&logo=c%2B%2B&&logoColor=red&style=flat)](https://en.cppreference.com/w/cpp/compiler_support)
![Platform](https://img.shields.io/static/v1?label=platform&message=windows&color=dimgray&style=flat&logo=windows)
[![Game version](https://img.shields.io/badge/game%20version-1.14.70-orange)](#Developing-with-CommonLibSF)
[![Main CI](https://img.shields.io/github/actions/workflow/status/Starfield-Reverse-Engineering/CommonLibSF/main_ci.yml)](https://github.com/Starfield-Reverse-Engineering/CommonLibSF/actions/workflows/main_ci.yml)

## Requirements

- [CMake v3.30+](https://cmake.org/) or [XMake v2.8.2+](https://github.com/xmake-io/xmake/releases)
  - Add this to your `PATH`
- [vcpkg](https://github.com/microsoft/vcpkg)
  - Create a Windows environment variable called `VCPKG_ROOT` with the value as the path to your vcpkg install directory
- [Visual Studio 2022 Build Tools](https://visualstudio.microsoft.com/downloads)
  - [LLVM](https://releases.llvm.org/) if using `clang-cl` presets
- [PowerShell](https://github.com/PowerShell/PowerShell/releases)

## Developing with CommonLibSF

### Using the CommonLibSF plugin templates

- [CLibSFPluginTemplate](https://github.com/Starfield-Reverse-Engineering/CLibSFPluginTemplate)
  - Uses **CMake**. Consumes CommonLibSF as [vcpkg port](https://github.com/Starfield-Reverse-Engineering/CommonLibSF-vcpkg).
- [commonlibsf-template-xmake](https://github.com/Starfield-Reverse-Engineering/commonlibsf-template-xmake)
  - Uses **XMake**. Consumes CommonLibSF as an [xrepo package](https://github.com/Starfield-Reverse-Engineering/commonlibsf-xrepo), a git submodule, or a local fork.

### Please see the [Using CommonLibSF wiki page](https://github.com/Starfield-Reverse-Engineering/CommonLibSF/wiki/Using-CommonLibSF) for more information about using CommonLibSF.

## End-User Requirements

- [Starfield Script Extender](https://www.nexusmods.com/starfield/mods/106)
- [Address Library for SFSE Plugins](https://www.nexusmods.com/starfield/mods/3256)

## Notes

CommonLibSF is intended to replace SFSE as a static dependency. However, the runtime component of SFSE is still required.

You may download the PDB for the latest build of CommonLibSF via the [Update PDB](https://github.com/Starfield-Reverse-Engineering/CommonLibSF/actions/workflows/update_pdb.yml) workflow. This is useful for importing the latest type information into IDA using the "Import PDB" feature.

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
    <a href="https://github.com/powerof3" title="powerof3">
      <img src="https://avatars.githubusercontent.com/u/32599957?v=4" width="50;" alt="powerof3"/>
    </a>
  </td>
  <td align="center">
    <a href="https://github.com/qudix" title="qudix">
      <img src="https://avatars.githubusercontent.com/u/17361645?v=4" width="50;" alt="qudix"/>
    </a>
  </td>
  <td align="center">
    <a href="https://github.com/shad0wshayd3" title="shad0wshayd3">
      <img src="https://avatars.githubusercontent.com/u/2724172?v=4" width="50;" alt="shad0wshayd3"/>
    </a>
  </td>
  <td align="center">
    <a href="https://github.com/nikitalita" title="Nikita">
      <img src="https://avatars.githubusercontent.com/u/69168929?v=4" width="50;" alt="Nikita"/>
    </a>
  </td>
  <td align="center">
    <a href="https://github.com/TommInfinite" title="TommInfinite">
      <img src="https://avatars.githubusercontent.com/u/81481291?v=4" width="50;" alt="TommInfinite"/>
    </a>
  </td>
  <td align="center">
    <a href="https://github.com/Deweh" title="V">
      <img src="https://avatars.githubusercontent.com/u/76853940?v=4" width="50;" alt="V"/>
    </a>
  </td>
  <td align="center">
    <a href="https://github.com/BrodyHiggerson" title="BrodyHiggerson">
      <img src="https://avatars.githubusercontent.com/u/7245990?v=4" width="50;" alt="BrodyHiggerson"/>
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
    <a href="https://github.com/FlayaN" title="Flayan">
      <img src="https://avatars.githubusercontent.com/u/964655?v=4" width="50;" alt="Flayan"/>
    </a>
  </td>
  <td align="center">
    <a href="https://github.com/ianpatt" title="Ian Patterson">
      <img src="https://avatars.githubusercontent.com/u/292795?v=4" width="50;" alt="Ian Patterson"/>
    </a>
  </td>
  <td align="center">
    <a href="https://github.com/Meridiano" title="Meridiano">
      <img src="https://avatars.githubusercontent.com/u/25160065?v=4" width="50;" alt="Meridiano"/>
    </a>
  </td>
  <td align="center">
    <a href="https://github.com/Bobbyclue" title="Bobbyclue">
      <img src="https://avatars.githubusercontent.com/u/97621924?v=4" width="50;" alt="Bobbyclue"/>
    </a>
  </td>
  <td align="center">
    <a href="https://github.com/epinter" title="Emerson Pinter">
      <img src="https://avatars.githubusercontent.com/u/1561280?v=4" width="50;" alt="Emerson Pinter"/>
    </a>
  </td>
  <td align="center">
    <a href="https://github.com/gazzamc" title="Gary McGovern">
      <img src="https://avatars.githubusercontent.com/u/7975925?v=4" width="50;" alt="Gary McGovern"/>
    </a>
  </td>
  <td align="center">
    <a href="https://github.com/Zzyxz" title="Zzyxz">
      <img src="https://avatars.githubusercontent.com/u/33715692?v=4" width="50;" alt="Zzyxz"/>
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

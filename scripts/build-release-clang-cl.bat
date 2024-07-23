echo off
cmake -B "%~dp0/../build/build-release-clang-cl-ninja" -S "%~dp0/.." --preset=build-release-clang-cl-ninja
cmake --build "%~dp0/../build/build-release-clang-cl-ninja" --config Release

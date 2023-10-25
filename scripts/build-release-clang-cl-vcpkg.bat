echo off
cmake -B "%~dp0/../build/build-release-clang-cl-ninja-vcpkg" -S "%~dp0/../CommonLibSF" --preset=build-release-clang-cl-ninja-vcpkg
cmake --build "%~dp0/../build/build-release-clang-cl-ninja-vcpkg" --config Release

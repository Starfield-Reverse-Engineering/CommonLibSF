echo off
cmake -B "%~dp0/../build/build-release-msvc-ninja-vcpkg" -S "%~dp0/../CommonLibSF" --preset=build-release-msvc-ninja-vcpkg
cmake --build "%~dp0/../build/build-release-msvc-ninja-vcpkg" --config Release

echo off
cmake -B "%~dp0/../build/build-debug-msvc-msvc-vcpkg" -S "%~dp0/../CommonLibSF" --preset=build-debug-msvc-msvc-vcpkg

echo off
cmake -B "%~dp0/../build/build-debug-msvc-ninja-vcpkg" -S "%~dp0/../CommonLibSF" --preset=build-debug-msvc-ninja-vcpkg
cmake --build "%~dp0/../build/build-debug-msvc-ninja-vcpkg" --config Debug

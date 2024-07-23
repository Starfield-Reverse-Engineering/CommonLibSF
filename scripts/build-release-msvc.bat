echo off
cmake -B "%~dp0/../build/build-release-msvc-ninja" -S "%~dp0/.." --preset=build-release-msvc-ninja
cmake --build "%~dp0/../build/build-release-msvc-ninja" --config Release

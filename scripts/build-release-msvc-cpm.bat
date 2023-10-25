echo off
cmake -B "%~dp0/../build/build-release-msvc-ninja-cpm" -S "%~dp0/../CommonLibSF" --preset=build-release-msvc-ninja-cpm
cmake --build "%~dp0/../build/build-release-msvc-ninja-cpm" --config Release

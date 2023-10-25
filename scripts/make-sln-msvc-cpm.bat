echo off
cmake -B "%~dp0/../build/build-debug-msvc-msvc-cpm" -S "%~dp0/../CommonLibSF" --preset=build-debug-msvc-msvc-cpm

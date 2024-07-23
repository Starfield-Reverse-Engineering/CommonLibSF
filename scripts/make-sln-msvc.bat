echo off
cmake -B "%~dp0/../build/build-debug-msvc-msvc" -S "%~dp0/../CommonLibSF" --preset=build-debug-msvc-msvc

echo off
cmake -B "%~dp0/../build/build-debug-msvc-msvc" -S "%~dp0/.." --preset=build-debug-msvc-msvc

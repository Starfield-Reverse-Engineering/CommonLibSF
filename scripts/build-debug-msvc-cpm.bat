echo off
cmake -B "%~dp0/../build/build-debug-msvc-ninja-cpm" -S "%~dp0/../CommonLibSF" --preset=build-debug-msvc-ninja-cpm
cmake --build "%~dp0/../build/build-debug-msvc-ninja-cpm" --config Debug

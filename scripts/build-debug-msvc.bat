echo off
cmake -B "%~dp0/../build/build-debug-msvc-ninja" -S "%~dp0/../CommonLibSF" --preset=build-debug-msvc-ninja
cmake --build "%~dp0/../build/build-debug-msvc-ninja" --config Debug

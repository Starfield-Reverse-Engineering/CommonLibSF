echo off
cmake -B "%~dp0/../build/build-debug-clang-cl-msvc-cpm" -S "%~dp0/../CommonLibSF" --preset=build-debug-clang-cl-msvc-cpm

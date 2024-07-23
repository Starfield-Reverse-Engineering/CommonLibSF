echo off
cmake -B "%~dp0/../build/build-debug-clang-cl-msvc" -S "%~dp0/../CommonLibSF" --preset=build-debug-clang-cl-msvc

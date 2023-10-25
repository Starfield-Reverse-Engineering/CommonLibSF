echo off
cmake -B "%~dp0/../build/build-debug-clang-cl-ninja-cpm" -S "%~dp0/../CommonLibSF" --preset=build-debug-clang-cl-ninja-cpm
cmake --build "%~dp0/../build/build-debug-clang-cl-ninja-cpm" --config Debug

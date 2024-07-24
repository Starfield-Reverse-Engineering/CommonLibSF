echo off
cmake -B "%~dp0/../build/build-debug-clang-cl-ninja" -S "%~dp0/.." --preset=build-debug-clang-cl-ninja
cmake --build "%~dp0/../build/build-debug-clang-cl-ninja" --config Debug

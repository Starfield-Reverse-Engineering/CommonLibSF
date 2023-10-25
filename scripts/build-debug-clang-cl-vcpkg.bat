echo off
cmake -B "%~dp0/../build/build-debug-clang-cl-ninja-vcpkg" -S "%~dp0/../CommonLibSF" --preset=build-debug-clang-cl-ninja-vcpkg
cmake --build "%~dp0/../build/build-debug-clang-cl-ninja-vcpkg" --config Debug

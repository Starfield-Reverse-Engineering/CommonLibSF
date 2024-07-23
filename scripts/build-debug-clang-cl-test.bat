echo off
cmake -B "%~dp0/../build/build-debug-clang-cl-ninja-test" -S "%~dp0/.." --preset=build-debug-clang-cl-ninja -DSFSE_BUILD_TESTS=true
cmake --build "%~dp0/../build/build-debug-clang-cl-ninja-test" --config Debug

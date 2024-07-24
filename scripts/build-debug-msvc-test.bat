echo off
cmake -B "%~dp0/../build/build-debug-msvc-ninja-test" -S "%~dp0/.." --preset=build-debug-msvc-ninja -DSFSE_BUILD_TESTS=true
cmake --build "%~dp0/../build/build-debug-msvc-ninja-test" --config Debug

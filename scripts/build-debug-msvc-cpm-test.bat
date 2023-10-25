echo off
cmake -B "%~dp0/../build/build-debug-msvc-ninja-cpm-test" -S "%~dp0/../CommonLibSF" --preset=build-debug-msvc-ninja-cpm -DSFSE_BUILD_TESTS=true
cmake --build "%~dp0/../build/build-debug-msvc-ninja-cpm-test" --config Debug

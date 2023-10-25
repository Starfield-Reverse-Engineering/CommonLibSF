echo off
cmake -B "%~dp0/../build/build-release-msvc-ninja-cpm-test" -S "%~dp0/../CommonLibSF" --preset=build-release-msvc-ninja-cpm -DSFSE_BUILD_TESTS=true
cmake --build "%~dp0/../build/build-release-msvc-ninja-cpm-test" --config Release

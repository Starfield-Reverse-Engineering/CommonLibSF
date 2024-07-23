echo off
cmake -B "%~dp0/../build/build-release-msvc-ninja-test" -S "%~dp0/.." --preset=build-release-msvc-ninja -DSFSE_BUILD_TESTS=true
cmake --build "%~dp0/../build/build-release-msvc-ninja-test" --config Release

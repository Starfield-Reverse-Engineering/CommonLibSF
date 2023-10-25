echo off
cmake -B "%~dp0/../build/build-release-clang-cl-ninja-cpm-test" -S "%~dp0/../CommonLibSF" --preset=build-release-clang-cl-ninja-cpm -DSFSE_BUILD_TESTS=true
cmake --build "%~dp0/../build/build-release-clang-cl-ninja-cpm-test" --config Release

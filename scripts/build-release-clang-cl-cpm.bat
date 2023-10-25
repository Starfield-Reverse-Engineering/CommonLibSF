echo off
cmake -B "%~dp0/../build/build-release-clang-cl-ninja-cpm" -S "%~dp0/../CommonLibSF" --preset=build-release-clang-cl-ninja-cpm
cmake --build "%~dp0/../build/build-release-clang-cl-ninja-cpm" --config Release

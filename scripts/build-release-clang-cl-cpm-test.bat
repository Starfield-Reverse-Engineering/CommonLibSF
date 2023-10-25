echo off
rd /s /q "build"
cmake -B "%~dp0/../build" -S "%~dp0/../CommonLibSF" --preset=build-release-clang-cl-ninja-cpm -DSFSE_ENABLE_TESTS
cmake --build "%~dp0/../build" --config Release

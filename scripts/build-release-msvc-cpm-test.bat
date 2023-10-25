echo off
rd /s /q "build"
cmake -B "%~dp0/../build" -S "%~dp0/../CommonLibSF" --preset=build-release-msvc-ninja-cpm -DSFSE_BUILD_TESTS=true
cmake --build "%~dp0/../build" --config Release

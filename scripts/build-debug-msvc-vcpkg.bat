echo off
rd /s /q "%~dp0/../build"
cmake -B "%~dp0/../build" -S "%~dp0/../CommonLibSF" --preset=build-release-msvc-ninja-vcpkg
cmake --build "%~dp0/../build" --config Debug

echo off
rd /s /q "%~dp0/../build"
cmake -B "%~dp0/../build" -S "%~dp0/../CommonLibSF" --preset=build-debug-msvc-msvc-cpm

echo off
rd /s /q "build"
cmake -B "%~dp0/build" -S "%~dp0/CommonLibSF" --preset=build-release-clang-cl-ninja
cmake --build "%~dp0/build" --config Release

echo off
rd /s /q "build"
cmake -B "%~dp0/build" -S "%~dp0/CommonLibSF" --preset=build-debug-clang-cl-msvc

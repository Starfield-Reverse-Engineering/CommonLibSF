echo off
rd /s /q "build"
cmake -B "%cd%/build" -S "%cd%/CommonLibSF" --preset=build-debug-msvc-msvc

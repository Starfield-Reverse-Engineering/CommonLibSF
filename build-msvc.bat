echo off
rd /s /q "build"
cmake -B "%cd%/build" -S "%cd%/CommonLibSF" --preset=build-release-msvc-ninja
cmake --build "%cd%/build" --config Release

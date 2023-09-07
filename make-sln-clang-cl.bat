echo off
rd /s /q "build"
cmake -B "%cd%/build" -S "%cd%/CommonLibSF" --preset=solution-clang-cl
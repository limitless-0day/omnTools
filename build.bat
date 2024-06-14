@echo off
rd /S /Q build > nul
rd /S /Q bin > nul
mkdir bin > nul
cmake -B build
cmake --build build
if %ERRORLEVEL% NEQ 0 (
	pause > nul
	exit
)
copy build\Debug\omnTools.exe bin > nul
cd bin
ren omnTools.exe omn.exe > nul
cd ..

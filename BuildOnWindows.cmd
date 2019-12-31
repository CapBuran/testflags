SET REP=%CD%
if not exist "%REP%\bin" MKDIR "%REP%\bin"
CD "%REP%\bin"

if exist "C:\Program Files (x86)\CMake\bin\cmake.exe" set CMAKE_EXE="C:\Program Files (x86)\CMake\bin\cmake.exe"
if exist "C:\Program Files\CMake\bin\cmake.exe" set CMAKE_EXE="C:\Program Files\CMake\bin\cmake.exe"

::if not exist "%REP%\build" MKDIR "%REP%\build"
::SET RUNTIME_OUTPUT_DIRECTORY="%REP%\build"

::%CMAKE_EXE% -A x64 "%REP%"
%CMAKE_EXE% -A x64 "%REP%" > "%REP%\cmake.log" 2>&1
%CMAKE_EXE% --build . --config debug  > "%REP%\build_debug.log" 2>&1
%CMAKE_EXE% --build . --config release  > "%REP%\build_release.log" 2>&1

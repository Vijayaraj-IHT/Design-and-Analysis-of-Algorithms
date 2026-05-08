@echo off
setlocal

set ROOT=%~dp0
set BUILD_DIR=%ROOT%build

if not exist "%BUILD_DIR%" mkdir "%BUILD_DIR%"

cmake -S "%ROOT%" -B "%BUILD_DIR%" -DCMAKE_BUILD_TYPE=Release
cmake --build "%BUILD_DIR%" --config Release

echo.
echo Build finished. Executables are in:
%BUILD_DIR%\EX*/
endlocal


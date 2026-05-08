@echo off
setlocal

set ROOT=%~dp0
set BUILD_DIR=%ROOT%build

REM Run built executables if they exist.
for /D %%d in ("%BUILD_DIR%"\EX*) do (
  for %%f in ("%%d"\*.exe) do (
    echo Running: %%~nxf
    "%%f"
    echo.
  )
)

endlocal


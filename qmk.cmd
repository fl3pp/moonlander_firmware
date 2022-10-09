@echo off

set MSYSTEM=MINGW64
set MSYS2_PATH_TYPE=inherit

"%QMK_HOME%\usr\bin\bash.exe" -l -i %*

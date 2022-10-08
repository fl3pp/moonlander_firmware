@echo off

set MSYSTEM=MINGW64
set MSYS2_PATH_TYPE=inherit

"C:\Program Files\QMK_MSYS\usr\bin\bash.exe" -l -i %*

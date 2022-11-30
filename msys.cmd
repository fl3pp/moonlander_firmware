@echo off

set MSYSTEM=MINGW64
set MSYS2_PATH_TYPE=inherit

"%QMK_HOME%\usr\bin\bash.exe" --login -i -c "cd '%cd%'; if [ ! -z '%*' ]; then eval '%*'; else $SHELL; fi; "

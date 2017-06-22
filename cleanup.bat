
REM Remove Temp Visual Studio Files
REM *******************************

del	/s 	*.aps
del	/s 	*.clw
del	/s 	*.ncb
del	/s 	*.opt
del	/s 	*.plg
del	/s 	*.pdb
REM del	/s 	*.user
del	/s 	*.vsp
del	/s 	*.sdf
REM del	/s 	/A -H *.suo
del	/s 	/A -H *.db
del /s  /A -H *.lastbuildstate
del /s  .tlog
del /s  .sbr
del /s  .log




del	    /s /Q Debug\\*.*
rmdir 	/s /Q Debug
del   	/Q Release\\*.*
rmdir 	/Q Release

REM FOR /F "tokens=*" %%G IN ('DIR /B /AD /S *ipch*') DO RMDIR /S /Q "%%G"

REM FOR /F "tokens=*" %%G IN ('DIR /B /AD /S *obj*') DO RMDIR /S /Q "%%G"

REM FOR /F "tokens=*" %%G IN ('DIR /B /AD /S *bin*') DO RMDIR /S /Q "%%G"

FOR /F "tokens=*" %%G IN ('DIR /B /AD /S *Debug*') DO RMDIR /S /Q "%%G"

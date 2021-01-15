@ECHO OFF
cd .>BldOut.log
c:\Keil_v5\UV4\UV4.exe -b -j0 .\project\stm32f40x_8M\stm32f40x_8M.uvprojx -o ..\..\BldOut.log
set save_error=%errorlevel%
echo --------------------------------------------------
type BldOut.log
echo --------------------------------------------------
del BldOut.log
if %save_error% GTR 1 (
   echo exit with %save_error%
   exit /b %save_error%
)
COPY .\project\stm32f40x_8M\Objects\stm32f40x_8M.lib .\lib\
echo exit with %save_error%

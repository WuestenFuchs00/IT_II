@REM This batch show (1) how to determine the number of substrings in the string <var1>,
@REM that are separated by slash (/). And (2) how to get the last substring from <var1>.
@echo off

set var1=http://www.ais.mw.tum.de/fileadmin/w00bdq/www/Lehre/IT/PruefungIT_WS1415_Angabe.pdf
set var2=%var1%
set i=0

echo.var1: %var1%
echo.var2: %var2%

:loopprocess
for /F "tokens=1* delims=/" %%A in ( "%var1%" ) do (
  set /A i+=1
  set var1=%%B
  echo %var1%
  goto loopprocess
)

echo The string contains %i% tokens.

for /F "tokens=%i% delims=/" %%G in ( "%var2%" ) do set last=%%G

echo %last%

pause
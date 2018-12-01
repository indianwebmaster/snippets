@echo off
:Repeat
rem .... -w <time in millisecs> .... a quick way to sleep
ping 1.1.1.1 -n 1 -w 2000 > nul

ping -n 2 www.comcast.net > nul
if %ERRORLEVEL% neq 0 goto Failed
goto Passed
:Failed
echo Failed %DATE% - %TIME% >> pingtest_out.txt
goto Repeat
:Passed
echo Passed %DATE% - %TIME% >> pingtest_out.txt
goto Repeat
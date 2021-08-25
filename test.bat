@echo off
:_loop
set /a a+=1
.\CodingTest.exe %a%
if %a%==1000 goto _break
goto _loop
:_break
echo test ended
pause
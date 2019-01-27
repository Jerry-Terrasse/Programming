@echo off
:loop
cls
temp.exe > P.in
liu.exe < P.in > liu.out
P.exe < P.in > P.out
fc liu.out P.out
if not errorlevel 1 goto loop  
pause
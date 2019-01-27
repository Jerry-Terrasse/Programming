@echo off
for /l %%i in (8,1,10) do (
		data > a%%i.in
		a < a%%i.in > a%%i.out
		echo No.%%i Done
)

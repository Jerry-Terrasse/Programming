@echo off 
for /l %%i in (7,1,10) do (
		data > b%%i.in
		b  < b%%i.in > b%%i.out
		echo No.%%i Done
)

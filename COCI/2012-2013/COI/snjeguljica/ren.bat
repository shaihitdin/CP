echo off 
set filename=snjeguljica
for %%i in (1, 2, 3, 4, 5, 6, 7, 8, 9) do (
	Copy %filename%.in.%%i 0%%i
	Copy %filename%.out.%%i 0%%i.a
)
Copy %filename%.in.10 10
Copy %filename%.out.10 10.a
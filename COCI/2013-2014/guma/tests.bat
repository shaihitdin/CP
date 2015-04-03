del res.txt
echo off
for %%i in (1, 2, 3, 4, 5, 6, 7, 8, 9) do (
	Copy guma.in.%%i 0%%i
	Copy guma.out.%%i 0%%i.a
)
Copy guma.in.10 10
Copy guma.out.10 10.a

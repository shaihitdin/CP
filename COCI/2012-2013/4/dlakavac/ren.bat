set fn=dlakavac
for %%i in (1, 2, 3, 4, 5, 6, 7, 8, 9) do (
	Copy %fn%.in.%%i 0%%i
	Copy %fn%.out.%%i 0%%i.a
	del %fn%.in.%%i
	del	%fn%.out.%%i
)

for %%i in (10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20) do (
	Copy %fn%.in.%%i %%i
	Copy %fn%.out.%%i %%i.a
	del %fn%.in.%%i
	del	%fn%.out.%%i
)

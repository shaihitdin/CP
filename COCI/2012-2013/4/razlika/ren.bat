set fn=razlika
for %%i in (1, 2, 3, 4, 5, 6, 7, 8, 9) do (
	Copy %fn%.in.%%i 0%%i
	Copy %fn%.out.%%i 0%%i.a
	del %fn%.in.%%i
	del	%fn%.out.%%i
)

Copy %fn%.in.10 10
Copy %fn%.out.10 10.a
del %fn%.in.10
del	%fn%.out.10

set filename=snaga
for %%i in (1,2,3,4,5,6,7,8,9) do (
	ren %filename%.in.%%i 0%%i
	ren %filename%.out.%%i 0%%i.a
)
ren %filename%.in.10 10
ren %filename%.out.10 10.a
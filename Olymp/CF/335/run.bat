for /l %%i in (1,1,40) do (
	C_hack
	C
	C_someone
	fc out out2
	if errorlevel 1 (
		goto :break
	)
)
:break
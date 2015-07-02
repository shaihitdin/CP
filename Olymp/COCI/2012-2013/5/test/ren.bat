set fn=paleta

echo off

for /l %%i in (1,1,10) do (
	echo %%i
	ren %fn%.in.%%ia %%ia
	ren %fn%.out.%%ia %%ia.a
	ren %fn%.in.%%ib %%ib
	ren %fn%.out.%%ib %%ib.a
	ren %fn%.in.%%ic %%ic
	ren %fn%.out.%%ic %%ic.a
)
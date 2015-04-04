del res.txt
set filename=garland.
echo off 
for %%i in (??) do (
	Copy %%i %filename%in
	echo test %%i
	run -t 1s -m 64M a
	if errorlevel 1 (
		echo TL or RE
		echo TL or RE >> res.txt
	) else (    
	    fcmp %filename%in %filename%out %%i.a
		fcmp %filename%in %filename%out %%i.a >> res.txt
	)
	del %filename%in
	del %filename%out
)

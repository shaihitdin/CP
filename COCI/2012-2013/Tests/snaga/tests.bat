del res.txt
set filename=
echo off 
for %%i in (??) do (
	Copy %%i %filename%in
	echo test %%i
	a 300
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

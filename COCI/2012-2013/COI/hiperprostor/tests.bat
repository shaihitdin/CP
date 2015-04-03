del res.txt
set filename=
echo off 
for %%i in (??) do (
	Copy %%i %filename%in
	echo test %%i
	run -t 1500ms -m 32M -Xacp a
	if errorlevel 1 (
		echo TL or RE
		echo TL or RE >> res.txt
	) else (    
	    check %filename%in %filename%out %%i.a
		check %filename%in %filename%out %%i.a >> res.txt
	)
	del %filename%in
	del %filename%out
)

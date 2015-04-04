@echo off
set param=%1                

del %param% /s in
del %param% /s *.in
del %param% /s out
del %param% /s *.out
del %param% /s err
del %param% /s *.err
del %param% /s input.txt
del %param% /s output.txt	    

for %%i in (a, b, c, d, e, f, g, h) do (
	del %param% /s %%i.exe
)
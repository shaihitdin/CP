echo off
for %%i in (??) do (
Copy %%i in
run -t 2s -m 256M a
fcmp in out %%i.a >> res.txt
)

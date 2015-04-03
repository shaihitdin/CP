del res.txt
echo off
for %%i in (??) do (
Copy %%i in
run -t 1s -m 64M a
fcmp in out %%i.a >> res.txt
)

@echo off
for /L %%i in (1,1,50) do (
    (echo 2 && echo 10000 && echo 10000) | .\main.exe
)
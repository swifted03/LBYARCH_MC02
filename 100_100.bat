@echo off
for /L %%i in (1,1,50) do (
    (echo 2 && echo 100 && echo 100) | .\main.exe
)
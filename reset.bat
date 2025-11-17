@echo off

for %%F in (
    "10_10.txt"
    "10_10_C.txt"
    "100_100.txt"
    "100_100_C.txt"
    "1000_1000.txt"
    "1000_1000_C.txt"
    "5000_5000.txt"
    "5000_5000_C.txt"
) do (
    del /s /q "%%F" 2>nul
)


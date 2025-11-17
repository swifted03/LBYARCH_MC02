@echo off

for %%F in (
    "5_5.txt"
    "5_5_C.txt"
    "10_10.txt"
    "10_10_C.txt"
    "100_100.txt"
    "100_100_C.txt"
    "1000_1000.txt"
    "1000_1000_C.txt"
    "10000_10000.txt"
    "10000_10000_C.txt"
) do (
    del /s /q "%%F" 2>nul
)


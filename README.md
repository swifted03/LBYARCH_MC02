# LBYARCH_MC02

## Build Commands
```
nasm -f win64 imgCvtGrayInttoFloat.asm -o imgCvtGrayInttoFloat.o
```

```
gcc main.c imgCvtGrayInttoFloat.o -o main.exe
```

```
main.exe <row> <col>
```

## Inputs
- `row` (integer): number of rowss
- `col` (integer): number of columns

## Bat Files
```
10_10.bat
```
```
100_100.bat
```
```
1000_1000.bat
```
- executes main.exe 50 times and output execution time in .txt file
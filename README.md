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

## Execution Time
```
gcc average.c -o average.o
```
```
average.exe
```

| row | column | Average Execution (ns) |
|-----|--------|----------------------|
| 10 | 10 | 374.00 |
| 100 | 100 | 41390.00 |
| 1000 | 1000 | 3311408.00 |

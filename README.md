# LBYARCH_MC02

## Build Commands
```
nasm -f win64 imgCvtGrayInttoFloat.asm -o imgCvtGrayInttoFloat.o
```

```
gcc main.c imgCvtGrayInttoFloat.o -o main.exe
```

```
main.exe
```

## Inputs
- `row` (integer): number of rowss
- `col` (integer): number of columns

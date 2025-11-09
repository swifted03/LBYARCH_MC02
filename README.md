# LBYARCH_MC02

## Build Commands
```
# Assemble the ASM file
nasm -f win64 imgCvtGrayInttoFloat.asm -o imgCvtGrayInttoFloat.o
```

```
# Compiole and link with main.c
gcc main.c imgCvtGrayInttoFloat.o -o main.exe
```

```
# Run the program
main.exe
```

## Inputs
 - row (int)
 - col (int)

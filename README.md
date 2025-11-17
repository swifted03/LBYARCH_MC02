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
The user will be prompted to choose from two choices:
1. `1. Load from text file`: Asks for a filename. The file must be formatted as:
```
<row> <col>
<pixel1> <pixel2> ...
<pixelN> ...
```

2. `2. Generate random numbers`: Asks for `row` and `col` size.

After running, the program will print the execution time for both the Assembly and C functions, along with a "PASSED" correctness check.

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
```
5000_5000.bat
```
```
reset.bat
```
```
run.bat
```
- 10_10.bat, 100_100.bat...: executes main.exe 50 times and output execution time in .txt file
- run.bat: to run all .bat files to generate output
- reset.bat: to delete all generated output files

## Execution Time
```
gcc average.c -o average.exe
```
```
average.exe
```

| Row | Column | Count | Average Execution ASM (ns) | Average Execution C (ns) | Difference |
|-----|--------|-------|----------------------|-------------------|-----------|
| 10 | 10 | 50 | 366.00 | 330.00 | 1.11 |
| 100 | 100 | 50 | 28108.00 | 28718.00 | 0.98 |
| 1000 | 1000 | 50 | 1804776.00 | 1990732.00 | 0.91 |
| 5000 | 5000 | 50 | 42635154.00 | 47093764.00 | 0.91 |

- Values <1 indicate ASM is more efficient

## Program Output
<img width="597" height="962" alt="image" src="https://github.com/user-attachments/assets/3ae1f48e-f0c6-4cb8-930b-601ff51d3594" />

## Short Video Walkthrough
Here is a short [video](https://drive.google.com/file/d/1KW9bXQ4E4he8N3d05Sq98VKiRhDMRHak/view?usp=sharing) related to this program.

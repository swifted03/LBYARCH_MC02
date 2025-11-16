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
- executes main.exe 50 times and output execution time in .txt file

## Execution Time
```
gcc average.c -o average.exe
```
```
average.exe
```

| row | column | Count | Average Execution (ns) |
|-----|--------|-------|----------------------|
| 10 | 10 | 50 | 448.00 |
| 100 | 100 | 50 | 28150.00 |
| 1000 | 1000 | 50 | 2147872.00 |

## Program Output
<img width="597" height="962" alt="image" src="https://github.com/user-attachments/assets/3ae1f48e-f0c6-4cb8-930b-601ff51d3594" />

## Short Video Walkthrough
Here is a short [video](https://drive.google.com/file/d/1KW9bXQ4E4he8N3d05Sq98VKiRhDMRHak/view?usp=sharing) related to this program.

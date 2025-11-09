#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern float* imgCvtGrayInttoFloat(int* arr, int row, int col);

int main()
{

    int row, col;
    scanf("%d", &row);
    scanf("%d", &col);

    int* arr = malloc(row * col * sizeof(int));

    srand((unsigned)time(NULL));

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            arr[i * col + j] = (int)(rand() % 100);
            printf("%d\n", arr[i * col + j]); // for printing random int numbers
        }
    }

    return 0;
}
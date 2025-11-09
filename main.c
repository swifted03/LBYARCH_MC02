#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern float* imgCvtGrayInttoFloat(float* arr, int row, int col);

int main()
{

    int row, col;
    scanf("%d", &row);
    scanf("%d", &col);

    float* arr = malloc(row * col * sizeof(float));

    srand((unsigned)time(NULL));

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            arr[i * col + j] = (float)(rand() % 100);
            // printf("%.2f\n", arr[i * col + j]); // for printing random float numbers
        }
    }

    return 0;
}
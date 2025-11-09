#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void imgCvtGrayInttoFloat(int* input, float* output, int size);

long long timespec_to_ns(struct timespec t) {
    return (long long)t.tv_sec * 1000000000LL + t.tv_nsec;
}

int main()
{

    int row, col;
    scanf("%d", &row);
    scanf("%d", &col);

    int size = row * col;
    int* input = malloc(size * sizeof(int));
    float* output = malloc(size * sizeof(float));

    srand((unsigned)time(NULL));

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            input[i * col + j] = (int)(rand() % 10000) + 1;
            // printf("%d ", input[i * col + j]); // for printing random int numbers
        }
        // printf("\n");
    }

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    imgCvtGrayInttoFloat(input, output, size);
    clock_gettime(CLOCK_MONOTONIC, &end);

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            // printf("%f ", output[i * col + j]); // for printing random int numbers
        }
        // printf("\n");
    }
    
    long long start_ns = timespec_to_ns(start);
    long long end_ns = timespec_to_ns(end);

    long long elapsed_ns = end_ns - start_ns;

    printf("Execution time: %lld nanoseconds\n", elapsed_ns);

    return 0;
}
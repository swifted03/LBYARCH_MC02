#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void imgCvtGrayInttoFloat(int* input, float* output, int size);

long long timespec_to_ns(struct timespec t) {
    return (long long)t.tv_sec * 1000000000LL + t.tv_nsec;
}

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        return 1;
    }

    int row = atoi(argv[1]);
    int col = atoi(argv[2]);

    int size = row * col;
    int* input = malloc(size * sizeof(int));
    float* output = malloc(size * sizeof(float));

    srand((unsigned)time(NULL));

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            input[i * col + j] = (int)(rand() % 255) + 1;
            //printf("%d ", input[i * col + j]); // for printing random int numbers
        }
        //printf("\n");
    }

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    imgCvtGrayInttoFloat(input, output, size);
    clock_gettime(CLOCK_MONOTONIC, &end);

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            //printf("%f ", output[i * col + j]); // for printing random int numbers
        }
        //printf("\n");
    }
    
    long long start_ns = timespec_to_ns(start);
    long long end_ns = timespec_to_ns(end);

    long long elapsed_ns = end_ns - start_ns;

    char filename[25];
    snprintf(filename, sizeof(filename), "%d_%d.txt", row, col);

    FILE* fp = fopen(filename, "a");
    fprintf(fp, "%lld\n", elapsed_ns);
    fclose(fp);

    free(input);
    free(output);

    return 0;
}
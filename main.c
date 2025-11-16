#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern float* imgCvtGrayInttoFloat(int size, int* input, float* output);

float* imgCvtGrayInttoFloat_C(int size, int* input, float* output) {
    const float divisor = 255.0f; 
    
    for (int i = 0; i < size; i++) {
        output[i] = (float)input[i] / divisor;
    }
    return output;
}

long long timespec_to_ns(struct timespec t) {
    return (long long)t.tv_sec * 1000000000LL + t.tv_nsec;
}

int main(int argc, char* argv[])
{
    int row, col, size;
    int* input = NULL;
    float* output = NULL;
    float* output_c = NULL;
    int choice;

    srand((unsigned)time(NULL));

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            input[i * col + j] = (int)(rand() % 10000) + 1;
            //printf("%d ", input[i * col + j]); // for printing random int numbers
        }
        //printf("\n");
    }

    struct timespec start, end;
    long long elapsed_ns_asm, elapsed_ns_c;

    clock_gettime(CLOCK_MONOTONIC, &start);
    imgCvtGrayInttoFloat(size, input, output);
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed_ns_asm = timespec_to_ns(end) - timespec_to_ns(start);

    clock_gettime(CLOCK_MONOTONIC, &start);
    imgCvtGrayInttoFloat_C(size, input, output_c);
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed_ns_c = timespec_to_ns(end) - timespec_to_ns(start);

    printf("Output:\n");
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            printf("%.2f ", output[i * col + j]); // for printing random int numbers
        }
        printf("\n");
    }


    printf("--- Correctness Check ---\n");
    int check_index = 0;
    int int_val = input[check_index];
    float asm_result = output[check_index];
    float c_result = (float)int_val / 255.0f;
    printf("Pixel[0] (Input Int):    %d\n", int_val);
    printf("Pixel[0] (C Calculation): %.2f\n", c_result);
    printf("Pixel[0] (ASM Result):    %.2f\n", asm_result);
    if (asm_result - c_result < 0.001f) {
        printf("Result: \033[0;32mPASSED\033[0m\n");
    } else {
        printf("Result: \033[0;31mFAILED\033[0m\n");
    }
    printf("--------------------------\n");

    printf("\n--- Runtime Comparison (Size: %d x %d) ---\n", row, col);
    printf("Assembly (ASM): %lld ns\n", elapsed_ns_asm);
    printf("C Language (C): %lld ns\n", elapsed_ns_c);
    
    if (elapsed_ns_asm < elapsed_ns_c) {
        double difference = (double)elapsed_ns_c / (double)elapsed_ns_asm;
        printf("\nResult: \033[0;32mASM was %.2fx faster than C.\033[0m\n", difference);
    } else {
        double difference = (double)elapsed_ns_asm / (double)elapsed_ns_c;
        printf("\nResult: \033[0;31mC was %.2fx faster than ASM.\033[0m\n", difference);
    }
    printf("------------------------------------------\n");
    
    
    // --- Timing & File Output ---
    char filename[25];
    snprintf(filename, sizeof(filename), "%d_%d.txt", row, col);

    FILE* fp = fopen(filename, "a");
    fprintf(fp, "%lld\n", elapsed_ns_asm);
    fclose(fp);

    free(input);
    free(output);

    return 0;
}
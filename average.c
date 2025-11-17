#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double average;
    int count;
} AvgResult;

AvgResult compute_average(const char* filename) {
    double sum = 0.0;
    int count = 0;
    int value;

    FILE* file = fopen(filename, "r");

    while (fscanf(file, "%d", &value) == 1) {
        sum += value;
        count++;
    }

    fclose(file);

    AvgResult result;
    result.average = sum / count;
    result.count = count;
    return result;
}

int main() {
    const char* files[] = {"10_10.txt", "100_100.txt", "1000_1000.txt"};
    const char* c_files[] = {"10_10_C.txt", "100_100_C.txt", "1000_1000_C.txt"};
    const int rows[] = {10, 100, 1000};
    const int cols[] = {10, 100, 1000};
    const int num_files = 3;

    FILE* output = fopen("average.txt", "w");

    fprintf(output, "| row | column | Count | Average Execution ASM (ns) | Average Execution C (ns) | Difference |\n");
    fprintf(output, "|-----|--------|-------|----------------------|-------------------|-----------|\n");

    for (int i = 0; i < num_files; i++) {
        AvgResult res_asm = compute_average(files[i]);
        AvgResult res_c = compute_average(c_files[i]);
        
        double difference = 0.0;
        if (res_asm.average < res_c.average) {
            difference = (double)res_c.average / (double)res_asm.average;
        } else {
            difference = (double)res_asm.average / (double)res_c.average;
        }

        fprintf(output, "| %d | %d | %d | %.2f |\n", rows[i], cols[i], res_asm.count, res_asm.average, res_c.average, difference);
    }

    fclose(output);

    return 0;
}

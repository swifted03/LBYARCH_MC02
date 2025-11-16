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
    const int rows[] = {10, 100, 1000};
    const int cols[] = {10, 100, 1000};
    const int num_files = 3;

    FILE* output = fopen("average.txt", "w");

    fprintf(output, "| row | column | Count | Average Execution (ns) |\n");
    fprintf(output, "|-----|--------|-------|----------------------|\n");

    for (int i = 0; i < num_files; i++) {
        AvgResult res = compute_average(files[i]);
        fprintf(output, "| %d | %d | %d | %.2f |\n", rows[i], cols[i], res.count, res.average);
    }

    fclose(output);

    return 0;
}

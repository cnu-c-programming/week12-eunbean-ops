#include <stdio.h>

int main(int argc, const char* argv[]) {
    const char* filename = "numbers.txt";

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        return 0;
    }

    int sum = 0;
    int num;
    char invalid_str[256];

    while (1) {
        int result = fscanf(fp, "%d", &num);
        if (result == EOF) {
            break;
        }

        if (result == 1) {
            sum += num;
        }else {
            fscanf(fp, "%255s", invalid_str);
            fprintf(stderr, "error: invalid value '%s'\n", invalid_str);
        }
    }

    printf("sum: %d\n", sum);
    fclose(fp);
    return 0;
}

#include <stdio.h>

int main(int argc, const char* argv[]) {
    const char* filename = "numbers.txt";

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        return 0;
    }

    int sum = 0;
    int num;
    char invalid_str[64];

    while (1) {
        int result = fscanf(fp, "%d", &num);
        
        if (result == 1) {
            sum += num;
        } 
        else if (result == 0) {
            fscanf(fp, "%63s", invalid_str);
            fprintf(stderr, "invalid input %s\n", invalid_str);
        } 
        else {
            break;
        }
    }

    printf("sum: %d\n", sum);
    fclose(fp);
    return 0;
}

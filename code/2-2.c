#include <stdio.h>
#include <string.h>

typedef struct student {
    char name[64];
    int score;
} Student;

int main(int argc, const char* argv[]) {
    FILE* fp = fopen("student.txt", "r");
    int count = 0;
    Student students[64];

    while (!feof(fp)) {
        if (fscanf(fp, "%s %d", students[count].name, &students[count].score) == 2) {
            count++;
        }
    }

    int max = 0;
    float avg = 0;

    if (count > 0) {
        int total_sum = 0;
        max = students[0].score;

        for (int i = 0; i < count; i++) {
            total_sum += students[i].score;
            if (students[i].score > max) {
                max = students[i].score;
            }
        }
        avg = (float)total_sum / count;
    }

    printf("max: %d\n", max);
    printf("avg: %.2f\n", avg);

    fclose(fp);
    return 0;
}

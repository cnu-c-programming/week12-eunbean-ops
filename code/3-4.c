#include <stdio.h>

int main(int argc, const char* argv[]) {
    if (argc < 3)
        return 0;

    FILE* fp_src = fopen(argv[1], "r");
    if (fp_src == NULL) {
        perror("error: cannot open");
        return 1;
    }

    FILE* fp_dst = fopen(argv[2], "w");
    if (fp_dst == NULL) {
        perror("error: cannot open");
        fclose(fp_src);
        return 1;
    }

    int ch;
    while (1) {
        ch = fgetc(fp_src);
        
        if (ch == EOF) {
            if (ferror(fp_src)) {
                perror("error: cannot read");
                fclose(fp_src);
                fclose(fp_dst);
                return 1;
            }
            break;
        }

        if (fputc(ch, fp_dst) == EOF) {
            perror("error: cannot write");
            fclose(fp_src);
            fclose(fp_dst);
            return 1;
        }
    }

    fclose(fp_src);
    fclose(fp_dst);
    return 0;
}

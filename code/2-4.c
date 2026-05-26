#include <stdio.h>

int main(int argc, const char* argv[]) {
    if (argc < 2)
        return 0;

    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 0;
    }
    int alphabet_count[26] = {0}; 
    int ch;


    while ((ch = fgetc(fp)) != EOF) {
    
        if (ch >= 'a' && ch <= 'z') {
            alphabet_count[ch - 'a']++;
        }
    }

    for (int i = 0; i < 26; i++) {
        printf("%c: %d\n", 'a' + i, alphabet_count[i]);
    }

    fclose(fp);
}

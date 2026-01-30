#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int isKeyword(char buffer[]) {
    char *keywords[] = {"int", "float", "return", "if", "else", "while"};
    for(int i = 0; i < 6; ++i) {
        if(strcmp(keywords[i], buffer) == 0) return 1;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: ./lexer <filename>\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", argv[1]);
        return 1;
    }

    char ch, buf[32];
    while ((ch = fgetc(fp)) != EOF) {
        if (isspace(ch)) continue;

        if (isalpha(ch)) {
            int j = 0;
            buf[j++] = ch;
            while (isalnum(ch = fgetc(fp))) buf[j++] = ch;
            buf[j] = '\0';
            ungetc(ch, fp); // Push back the non-alphanumeric char
            if (isKeyword(buf)) printf("KEYWORD: %s\n", buf);
            else printf("IDENTIFIER: %s\n", buf);
        } 
        else if (isdigit(ch)) {
            printf("NUMBER: %c\n", ch);
        } 
        else {
            printf("OPERATOR/SYMBOL: %c\n", ch);
        }
    }

    fclose(fp);
    return 0;
}

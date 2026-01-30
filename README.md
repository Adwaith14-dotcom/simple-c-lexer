#include <stdio.h>
#include <ctype.h>
#include <string.h>

void scan(char *code) {
    int i = 0;
    while (code[i] != '\0') {
        if (isspace(code[i])) { i++; continue; }
        if (isalpha(code[i])) {
            char buf[20]; int j = 0;
            while (isalnum(code[i])) buf[j++] = code[i++];
            buf[j] = '\0';
            printf("Token: Identifier/Keyword [%s]\n", buf);
        } else if (isdigit(code[i])) {
            printf("Token: Number [%c]\n", code[i++]);
        } else {
            printf("Token: Operator/Symbol [%c]\n", code[i++]);
        }
    }
}

int main() {
    char source[] = "int x = 5 + y;";
    scan(source);
    return 0;
}
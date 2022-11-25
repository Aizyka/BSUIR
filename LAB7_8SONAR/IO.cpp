#include "IO.h"
#include <stdio.h>
#include <stdlib.h>

int getint(int min, int max) {
    int number;
    while (!scanf_s("%d", &number) || number > max || number < min || getchar() != '\n') {
        printf_s("Invalid number!\n");
        rewind(stdin);
    }
    return number;
}

int getint(int min) {
    int number;
    while (!scanf_s("%d", &number) || number < min || getchar() != '\n') {
        printf_s("Invalid number!\n");
        rewind(stdin);
    }
    return number;
}

int getint() {
    int number;
    while (!scanf_s("%d", &number) || getchar() != '\n') {
        printf_s("Invalid number!\n");
        rewind(stdin);
    }
    return number;
}

char* getstring() {
    char* string = (char*)calloc(1, sizeof(char));
    char ch;
    int pos = 0;
    while (true) {
        ch = getchar();
        if (ch == '\n')
        {
            string[pos] = '\0';
            return string;
        }

        string[pos] = ch;
        pos++;
        string = (char*)realloc(string, (pos + 1) * sizeof(char));
    }
}
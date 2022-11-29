#include "SO.h"
#include <stdio.h>
#include <stdlib.h>

int str_len(char* str) {
    int len = 0;
    while (str[len] != '\0')
        len++;
    return len;
}

void str_copy(char* str1, char** str2) {
    int len = str_len(str1);
    int i = 0;
    (*str2) = (char *) calloc(len + 1, sizeof(char));
    while (str1[i] != '\0') {
        (*str2)[i] = str1[i];
        i++;
    }
    (*str2)[i] = '\0';
}

char* str_sub(char* str1, int start, int length) {
    char* str2 = (char*)calloc((length+1),sizeof(char));
    for (int i = 0; i < length; i++) {
        if (str1[i+start] == '\0') break;
        str2[i] = str1[i + start];
    }
    str2[length] = '\0';
    return str2;
}

void str_add(char** str, char* add, int pos) {

    int add_len = str_len(add);
    int len = str_len((*str));
    if(pos >= len) return;
    char *newStr = (char *) malloc((len + add_len + 1) * sizeof(char));
    int j = 0;
    for (int i = 0; i < pos; i++) {
        newStr[j] = (*str)[i];
        j++;
    }
    for (int i = 0; i < add_len; i++) {
        newStr[j] = add[i];
        j++;
    }
    if()
    for (int i = pos; i < len; i++) {
        newStr[j] = (*str)[i];
        j++;
    }


    newStr[len + add_len] = '\0';
    free((*str));
    (*str) = newStr;
}

char** str_split(char* str, char letter, int* size) {
    int i = 0;
    int prev_pos = 0;
    int new_arr = 0;
    int max_poses = 1;
    while (str[i] != '\0') {
        if (str[i] == letter) {
            max_poses++;
        }
        i++;
    }
    i = 0;
    char** str2 = (char**)malloc(max_poses*sizeof(char*));

    while (str[i] != '\0') {
        if (str[i] == letter) {
            str2[new_arr] = str_sub(str, prev_pos, i - prev_pos);
            new_arr++;
            prev_pos = i + 1;
        }
        i++;
    }
    if (str[i] == '\0') {
        str2[new_arr] = str_sub(str, prev_pos, i - prev_pos);
    }
    (*size) = new_arr + 1;
    return str2;
}

int str_max(char* str, char letter) {
    int i = 0;
    int prev_pos = 0;
    int max = 0;
    while (str[i] != '\0') {
        if (str[i] == letter) {
            char* sub = str_sub(str, prev_pos, i - prev_pos);
            int strlen = str_len(sub);
            if (strlen > max)
                max = strlen;
            prev_pos = i + 1;
            free(sub);
        }
        i++;
    }
    if (str[i] == '\0') {
        char* sub = str_sub(str, prev_pos, i - prev_pos);
        int strlen = str_len(sub);
        if (strlen > max)
            max = strlen;
        free(sub);
    }
    return max;
}
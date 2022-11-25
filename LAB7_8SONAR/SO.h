#pragma once

int str_len(char* str);
void str_copy(char* str1, char*& str2);
char* str_sub(char* str1, int start, int length);
char** str_split(char* str, char letter, int* size);
void str_add(char*& str, char* add, int pos);
int str_max(char* str, char letter);
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Array.h"
#include "IO.h"
#include "Sort.h"
#include "SO.h"

void Task1(int argc, char** argv);
void Task2(int argc, char** argv);
void Task3(int argc, char** argv);


int main(int argc, char** argv)
{
    //Choose LAB task
    srand(time(NULL));
    while (1) {
        printf("Enter Task (1-3)\n");
        int task;
        while (!scanf("%d", &task) || task > 3 || task < 1 || getchar() != '\n') {
            printf("Invalid task number!\n");
            rewind(stdin);
        }
        void (*task_run[3]) (int, char**) = {Task1, Task2, Task3};
        ((*task_run[task-1])(argc, argv));
        printf("\n\n");
        rewind(stdin);
    }
}



void Task1(int argc, char** argv) {
    printf("Write string: ");
    char* string = getstring();
    int size;
    char** split = str_split(string, ' ', &size);
    int min = str_len(split[0]);
    int min_pos = 0;
    for (int i = 0; i < size; i++) {
        int curr_count = str_len(split[i]);
        if (curr_count < min) {
            min = curr_count;
            min_pos = i;
        }
    }
    printf("\nMinimum string on pos %d: ", min_pos);
    print_string(split[min_pos]);
    free(string);
}

void Task2(int argc, char** argv) {
    printf("Write string S: ");
    char* S = getstring();
    printf("Write string S0: ");
    char* S0 = getstring();
    printf("Write k: ");
    int k = getint(0);
    if (k < str_len(S0)) {
        char* sub_s0 = str_sub(S0, str_len(S0) - k, k);
        printf("To add: ");
        print_string(sub_s0);
        str_add(&S, sub_s0, str_len(S) / 2);
        printf("\nResult: ");
        print_string(S);
        free(sub_s0);
    }
    else
        printf("k cant be larger than length of S0 string\n");
    free(S);
    free(S0);
}

void Task3(int argc, char** argv) {
    if (argc == 1) {
        printf("\nnot enough arguments\n");
        return;
    }
    char** strings = (char**)calloc(argc - 1, sizeof(char*));
    int* sizes = allocate(argc - 1);
    for (int i = 1; i < argc; i++) {
        str_copy(argv[i], &strings[i - 1]);
        sizes[i - 1] = str_max(argv[i], ' ');
        printf("\n%d %s\n", sizes[i - 1], argv[i]);
    }
    printf("\n\n");
    MergeSort(&sizes, &strings, 0, argc - 2);
    for (int i = 0; i < argc-1; i++) {
        printf("\n%d ", sizes[i]);
        print_string(strings[i]);
    }
    for (int i = 0; i < argc-1; i++) {
        free(strings[i]);
    }
    free(strings);
    free(sizes);

}
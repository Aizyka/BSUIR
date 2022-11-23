#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Array.h"
#include "IO.h"
#include "Sort.h"

void Task1();
void Task2();
void Task3();


int main()
{
    //Choose LAB task
    srand(time(NULL));
    while (true) {
        printf_s("Enter Task (1-2)\n");
        int task;
        while (!scanf_s("%d", &task) || task > 2 || task < 1 || getchar() != '\n') {
            printf_s("Invalid task number!\n");
            rewind(stdin);
        }
        switch (task) {
        case 1:
            Task1();
            break;
        case 2:
            Task2();
            break;
        }
        printf_s("\n\n");
        rewind(stdin);
    }
}

void Task1() {
    printf_s("Write length: ");
    int x = getint(0);
    int* arr = allocate(x);
    printf_s("Random? (1 - yes, 0 - no): ");
    int rand = getint(0, 1);
    if (rand == 1)
    {

        printf_s("Write min: ");
        int min = getint();
        printf_s("Write max: ");
        int max = getint(min);
        rand_array(arr, x, min, max);
    }
    else
        user_array(arr, x);

    printf_s("Show Array? (1 - yes, 0 - no): ");
    int showArray = getint(0, 1);
    if(showArray == 1) print_array(arr, x);
    int* duplicate_arr = duplicate(arr, x);
    clock_t time_start = clock();
    MergeSort(duplicate_arr, 0, x - 1);
    clock_t time_end = clock();
    if(showArray == 1) print_array(arr, x);
    printf_s("\nMerge Sort - Ellapsed seconds: %f seconds", (float)(time_end - time_start) / CLOCKS_PER_SEC);

    duplicate_arr = duplicate(arr, x);
    time_start = clock();
    Reverse(duplicate_arr, x);
    MergeSort(duplicate_arr, 0, x - 1);
    time_end = clock();
    if (showArray == 1) print_array(duplicate_arr, x);
    printf_s("\nMerge Sort Reversed - Ellapsed seconds: %f seconds", (float)(time_end - time_start) / CLOCKS_PER_SEC);

    duplicate_arr = duplicate(arr, x);
    time_start = clock();
    BubbleSort(duplicate_arr, x);
    time_end = clock();
    if (showArray == 1) print_array(duplicate_arr, x);
    printf_s("\nBubble Sort - Ellapsed seconds: %f seconds", (float)(time_end - time_start) / CLOCKS_PER_SEC);
    free(duplicate_arr);
    free(arr);
}

void Task2() {
    printf_s("Write height: ");
    int n = getint(0);
    printf_s("Write width: ");
    int m = getint(0);
    int** arr;
    arr = allocate_sec(n, m);
    printf_s("Random? (1 - yes, 0 - no): ");
    int rand = getint(0, 1);
    if (rand == 1)
        rand_array_sec(arr, n, m, 1, 9);
    else
        user_array_sec(arr, n, m, 1);
    print_array_sec(arr, n, m);
    SortMatrixByHoaraMethod(arr, n, m);
    printf_s("\nAfter sorting:\n");
    print_array_sec(arr, n, m);

    free(arr);
}
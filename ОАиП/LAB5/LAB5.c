// LAB5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Array.h"
#include "IO.h"

void Task1();
void Task2();
void Task3();

int main()
{
    //Choose LAB task
    srand(time(NULL));
    while (true) {
        printf_s("Enter Task (1-3)\n");
        int task;
        while (!scanf_s("%d", &task) || task > 3 || task < 1 || getchar() != '\n') {
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
            case 3:
                Task3();
                break;
        }
        printf_s("\n\n");
        rewind(stdin);
    }
}

void Task1() {
    printf_s("Write width: ");
    int x = getint(0);
    printf_s("Write height: ");
    int y = getint(0);
    int** arr = allocate_sec(x, y);
    printf_s("Random? (1 - yes, 0 - no): ");
    int rand = getint(0, 1);
    if (rand == 1)
        rand_array_sec(arr, x, y, 1, 100);
    else
        user_array_sec(arr, x, y, 1);

    printf_s("\n");

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            int get = arr[i][j];
            int sum = 0;

            for (int j1 = 0; j1 < y; j1++) {
                if (j == j1) continue;
                sum += arr[i][j1];
            }
            if (sum < get) {
                printf_s("Found number %d at line %d (sum %d)\n", get, i, sum);
            }
        }
        printf_s("\n");
    }
    print_array_sec(arr, x, y);
    free(arr);
}

void Task2() {
    bool sim = true;
    printf_s("Choose method (1 - Pre Defined, 0 - Standard): ");
    int method = getint(0, 1);
    int n;
    int** a;
    if (method == 1)
    {
        n = 4;
        a = allocate_sec(n, n);
        a[0][0] = 1;
        a[0][1] = 2;
        a[0][2] = 3;
        a[0][3] = 1;
        a[1][0] = 2;
        a[1][1] = 2;
        a[1][2] = 2;
        a[1][3] = 3;
        a[2][0] = 3;
        a[2][1] = 3;
        a[2][2] = 2;
        a[2][3] = 2;
        a[3][0] = 4;
        a[3][1] = 3;
        a[3][2] = 2;
        a[3][3] = 1;
    }
    else {
        printf_s("Write width: ");
        n = getint(0);
        a = allocate_sec(n, n);
        printf_s("Random? (1 - yes, 0 - no): ");
        int rand = getint(0, 1);
        if (rand == 1)
            rand_array_sec(a, n, n, 1, 9);
        else
            user_array_sec(a, n, n, 1);
    }

    printf_s("\n");
    
    for (int i = 0; i < n - 1; i++)
    {
        if ((a[0][i] != a[i][n - i - 1]) || (a[i][0] != a[i][n - i - 1]) || (a[n - 1][n - i - 1] != a[i][n - i - 1]) || (a[n - i - 1][n - 1] != a[i][n - i - 1])) sim = false;
        if (i < n / 2)
            if ((a[i][i] != a[i][n - i - 1]) || (a[n - i - 1][n - i - 1] != a[i][n - i - 1])) sim = false;
        if (!sim)
        {
            break;
        }
    }
    if (sim)
        printf_s("TEST OK");
    else 
        printf_s("TEST FAILED");
    print_array_sec(a, n, n);
    free(a);
}

void Task3() {
    printf_s("Write minimum value: ");
    int number = getint();
    printf_s("Write row count: ");
    int rowsCount = getint(0);
    int** arr = allocate_sec(rowsCount);
    int* size_arr = allocate(rowsCount);
    for (int i = 0; i < rowsCount; i++) {
        printf_s("Row: %d\n", i);
        int size;
        arr[i] = write_until_number(0, &size);

        int n = 0;
        while (n < size) {
            if (arr[i][n] < number && n % 2 == 0) {
                rem_element_sec(arr[i], n, size);
                n = 0;
                size--;
            }
            else n++;
        }
        size_arr[i] = size;
    }

    printf_s("\n");
    for (int i = 0; i < rowsCount; i++) {
        for (int j = 0; j < size_arr[i]; j++) {
            printf_s("%d\t", arr[i][j]);
        }
        printf_s("\n");
    }
    free(arr);
    free(size_arr);
}
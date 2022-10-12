#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define ARR_MAX 100
void Task1();
void Task2();
void Task3();

int main()
{
    //Choose LAB task
    srand(time(NULL));
    printf_s("Enter Task (1-3)\n");
    int task;
    if (!scanf_s("%d", &task) || task > 3 || task < 1) {
        printf_s("Invalid task number!\n");
        return 0;
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
    rewind(stdin);
    getchar(); //Waiting for pressing ENTER to close program
}

void Task1() {
    int x;
    int arr[ARR_MAX][ARR_MAX];

    printf_s("Write size\n");
    while (!scanf_s("%d", &x) || x > 100 || x < 1) { //Getting n value and check if 100 > x,y > 1
        printf_s("Invalid input\n");
        rewind(stdin);
    }
    printf_s("Random Generation?(1 - yes, 0 - no)\n");
    int random;
    while (!scanf_s("%d", &random) || random > 1 || random < 0) {
        printf_s("Invalid input\n");
        rewind(stdin);
    }
    for (int j = 0; j < x; j++) {
        int sum = 0;
        int neg_found = 0;
        for (int i = 0; i < x; i++) { //Creating loop that will fill array with user input
            int val;
            if (random == 1) {
                val = 100 - (rand() % 125);
                printf_s("random at pos (%d, %d): %d\n", j, i, val);
            }
            else {
                printf_s("\nWrite value at position (%d, %d): ", j, i);

                if (!scanf_s("%d", &val)) {
                    printf_s("Invalid input\n");
                    rewind(stdin);
                    j--;
                }

            }
            if (val < 0) neg_found = 1;
            sum += val;
            arr[i][j] = val;
        }
        if (neg_found == 0) printf_s("Sum in a row %d: %d\n", j, sum);
    }
    for (int i = 0; i < x; i++) {
        int sum1 = 0;
        for (int j = 0; j < x; j++) {
            if (j + i >= x) break;
            sum1 += arr[j + i][j];
        }
        printf_s("diag sum start at (%d, %d) = %d\n", i, 0, sum1);
        if (i == 0) continue;
        int sum2 = 0;
        for (int j = 0; j < x; j++) {
            if (j + i >= x) break;
            sum2 += arr[j][j + i];
        }
        printf_s("diag sum start at (%d, %d) = %d\n", 0, i, sum2);
    }
    for (int j = 0; j < x; j++) {
        for (int i = 0; i < x; i++) {
            printf_s("%d ", arr[i][j]);
        }
        printf_s("\n");
    }
}

void Task2() {
    int x, y;
    int arr[ARR_MAX][ARR_MAX];

    printf_s("Write size\n");
    while (!scanf_s("%d %d", &y, &x) || x > 100 || x < 1 || y > 100 || y < 1) { //Getting n value and check if 100 > x,y > 1
        printf_s("Invalid input\n");
        rewind(stdin);
    }
    printf_s("Random Generation?(1 - yes, 0 - no)\n");
    int random;
    while (!scanf_s("%d", &random) || random > 1 || random < 0) {
        printf_s("Invalid input\n");
        rewind(stdin);
    }
    int sum = 0;
    int full_neg_found = 0;
    for (int i = 0; i < x; i++) {
        sum = 0;
        int pos_found = 0;
        for (int j = 0; j < y; j++) { //Creating loop that will fill array with user input
            int val;
            if (random == 1) {
                val = 100 - (rand() % 200);
                printf_s("random at pos (%d, %d): %d\n", j, i, val);
            }
            else {
                printf_s("\nWrite value at position (%d, %d): ", j, i);

                if (!scanf_s("%d", &val)) {
                    printf_s("Invalid input\n");
                    rewind(stdin);
                    j--;
                }

            }
            if (val >= 0) pos_found = 1;
            sum += val;
            arr[i][j] = val;
        }
        if (full_neg_found == 0 && pos_found == 0) {
            full_neg_found = sum / y;
            printf_s("Full negative found at collumn %d with average sum: %d\n", i, sum / y);
        }
    }
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            printf_s("%d ", arr[j][i]);
        }
        printf_s("\n");
    }
    printf_s("\n");
    printf_s("\n");
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            printf_s("%d ", (arr[j][i] - full_neg_found));
        }
        printf_s("\n");
    }
}

void Task3() {
    int x, y;
    int arr[ARR_MAX][ARR_MAX];

    printf_s("Write size\n");
    while (!scanf_s("%d %d", &y, &x) || x > 100 || x < 1 || y > 100 || y < 1) { //Getting n value and check if 100 > x,y > 1
        printf_s("Invalid input\n");
        rewind(stdin);
    }
    printf_s("Random Generation?(1 - yes, 0 - no)\n");
    int random;
    while (!scanf_s("%d", &random) || random > 1 || random < 0) {
        printf_s("Invalid input\n");
        rewind(stdin);
    }
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) { //Creating loop that will fill array with user input
            int val;
            if (random == 1) {
                val = 100 - (rand() % 200);
                printf_s("random at pos (%d, %d): %d\n", j, i, val);
            }
            else {
                printf_s("\nWrite value at position (%d, %d): ", j, i);

                if (!scanf_s("%d", &val)) {
                    printf_s("Invalid input\n");
                    rewind(stdin);
                    j--;
                }
            }
            arr[i][j] = val;
        }
    }
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            printf_s("%d ", arr[j][i]);
        }
        printf_s("\n");
    }
    printf_s("\n");
    printf_s("\n");
    printf_s("Values in second quarter\n");
    int min = arr[x / 2][0];
    for (int i = x / 2; i < x; i++) {
        for (int j = 0; j < y / 2; j++) {
            printf_s("%d ", arr[i][j]);
            if (min > arr[i][j]) min = arr[i][j];
        }
        printf_s("\n");
    }
    printf_s("\nMinimum value: %d\n", min);
}
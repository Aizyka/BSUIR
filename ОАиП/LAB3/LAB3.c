#include <stdio.h>

void Task1();
void Task2();
void Task3();

int main()
{
    //Choose LAB task
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
    getchar();
    fflush(stdin);
    getchar(); //Waiting for pressing ENTER to close program
}

void Task1() {
    int n;
    int arr[100];

    printf_s("Write n\n");
    if (!scanf_s("%d", &n) || n > 100 || n < 0) { //Getting n value and check if 100 > n > 0
        printf_s("Invalid input\n");
        scanf_s("%*s");
        Task1();
        return;
    }
    int neg_1 = -1;
    int neg_2 = -1;
    for (int i = 0; i < n; i++) { //Creating loop
        printf_s("\nWrite value at position %d: ",i);
        int val;
        if (!scanf_s("%d", &val)) {
            printf_s("Invalid input\n");
            scanf_s("%*s");
            i--;
        }
        arr[i] = val;
        if (val < 0 && neg_1 < 0) neg_1 = i;
        else if (val < 0 && neg_2 < 0) neg_2 = i;
    }
    int min = arr[0];
    int min_pos = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
            min_pos = i;
        }
    }
    printf_s("Minimum value at position: %d\n", min_pos);
    if (neg_1 >= 0 && neg_2 >= 0) {
        int sum = 0;
        for (int i = neg_1 + 1; i < neg_2; i++) {
            sum += arr[i];
        }
        printf_s("Sum between two negative values: %d\n", sum);
    }
    else {
        printf_s("Not enough negative values to get sum.");
    }
}

void Task2() {
    int n;
    int arr[100];

    printf_s("Write n\n");
    if (!scanf_s("%d", &n) || n > 100 || n < 0) { //Getting n value and check if 100 > n > 0
        printf_s("Invalid input\n");
        scanf_s("%*s");
        Task2();
        return;
    }
    for (int i = 0; i < n; i++) { //Creating loop
        printf_s("\nWrite value at position %d: ", i);
        int val;
        if (!scanf_s("%d", &val)) {
            printf_s("Invalid input\n");
            scanf_s("%*s");
            i--;
        }
        arr[i] = val;
    }
    int min = arr[0];
    int min_pos = 0;
    int max = arr[0];
    int max_pos = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
            max_pos = i;
        }
    }
    for (int i = 0; i < max_pos; i++) {
        if (arr[i] < min) {
            min = arr[i];
            min_pos = i;
        }
    }
    if (max_pos != 0) {
        int sum = 0;
        for (int i = min_pos + 1; i < max_pos; i++) {
            sum += arr[i];
        }
        printf_s("Sum between two negative values: %d\n", sum);
    }
    else {
        printf_s("Cant calculate sum.");
    }
}

void Task3() {
    int n = 40;
    int arr[40] = { 7,6,1,8,7,5,7,8,1,8,7,5,4,5,1,5,4,9,4,0,4,7,6,5,9,4,3,7,6,8,9,1,5,4,3,5,6,7,8,0 };
    int newarr[20];
    /*for (int i = 0; i < n; i++) {
        printf_s("\nWrite value at position %d: ", i);
        int val;
        if (!scanf_s("%d", &val) || val > 9 || val < 0) {
            printf_s("Invalid input\n");
            scanf_s("%*s");
            i--;
        }
        arr[i] = val;
    }*/
    for (int i = 0; i < 20; i++) {
        newarr[i] = 0;
    }
    printf_s("76187578187545154940 - 47659437689154356780 = ");
    //printf_s("\n");
    for (int val_pos = 19; val_pos >= 0; val_pos--) {
        int value1 = arr[val_pos];
        int value2 = arr[20 + val_pos];
        newarr[val_pos] += value1 - value2;
        if (newarr[val_pos] < 0) {
            newarr[val_pos] += 10;
            newarr[val_pos - 1] -= 1;
        }
        else if (newarr[val_pos] > 9) {
            newarr[val_pos] -= 10;
            newarr[val_pos - 1] += 1;
        }
    }
    for (int val_pos = 0; val_pos < 20; val_pos++) {
        printf_s("%d", newarr[val_pos]);
    }
}
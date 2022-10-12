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
    getchar();
    fflush(stdin);
    getchar(); //Waiting for pressing ENTER to close program
}

void Task1() {
    int n;
    float arr[ARR_MAX];

    printf_s("Write n\n");
    if (!scanf_s("%d", &n) || n > 100 || n < 0) { //Getting n value and check if 100 > n > 0
        printf_s("Invalid input\n");
        scanf_s("%*s");
        Task1();
        return;
    }
    printf_s("Random Generation?(1 - yes, 0 - no)\n");
    int random;
    if (!scanf_s("%d", &random) || random > 1 || random < 0) {
        printf_s("Invalid input\n");
        scanf_s("%*s");
        Task1();
        return;
    }
    int neg_1 = -1;
    int neg_2 = -1;
    for (int i = 0; i < n; i++) { //Creating loop that will fill array with user input
        float val;
        if (random == 1) {
            val = 100 - (rand() % 200);
            printf_s("random at pos %d: %f\n", i, val);
        }
        else {
            printf_s("\nWrite value at position %d: ", i);
            
            if (!scanf_s("%f", &val)) {
                printf_s("Invalid input\n");
                scanf_s("%*s");
                i--;
            }
            
        }
        arr[i] = val;
        if (val < 0.0 && neg_1 < 0) neg_1 = i; //check for first negative
        else if (val < 0.0 && neg_2 < 0) neg_2 = i; //check for second negative
    }
    float min = arr[0];
    int min_pos = 0;
    for (int i = 0; i < n; i++) { //creating loop to find minimum value
        if (arr[i] < min) {
            min = arr[i];
            min_pos = i;
        }
    }
    printf_s("Minimum value at position: %d\n", min_pos);
    if (neg_1 >= 0 && neg_2 >= 0) { //check if two negatives found and calculate sum between them
        float sum = 0;
        for (int i = neg_1 + 1; i < neg_2; i++) {
            sum += arr[i];
        }
        printf_s("Sum between two negative values: %f\n", sum);
    }
    else {
        printf_s("Not enough negative values to get sum.");
    }
}

void Task2() {
    int n;
    int arr[ARR_MAX];

    printf_s("Write n\n");
    if (!scanf_s("%d", &n) || n > 100 || n < 0) { //Getting n value and check if 100 > n > 0
        printf_s("Invalid input\n");
        scanf_s("%*s");
        Task2();
        return;
    }
    printf_s("Random Generation?(1 - yes, 0 - no)\n");
    int random;
    if (!scanf_s("%d", &random) || random > 1 || random < 0) {
        printf_s("Invalid input\n");
        scanf_s("%*s");
        Task1();
        return;
    }
    for (int i = 0; i < n; i++) { //Creating loop that will fill array with user input
        int val;
        if (random == 1) {
            val = 100 - (rand() % 200);
        }
        else {
            printf_s("\nWrite value at position %d: ", i);
            if (!scanf_s("%d", &val)) {
                printf_s("Invalid input\n");
                scanf_s("%*s");
                i--;
            }
        }
        arr[i] = val;
    }
    int min = arr[0];
    int min_pos = 0;
    int max = arr[0];
    int max_pos = 0;
    for (int i = 0; i < n; i++) { //creating loop that will find minimum value
        if (arr[i] > max) {
            max = arr[i];
            max_pos = i;
        }
    }
    for (int i = 0; i < max_pos; i++) { //creating loop that will find maximum value
        if (arr[i] < min) {
            min = arr[i];
            min_pos = i;
        }
    }
    if (max_pos != 0) { //check if two values found and remove values between them
        for (int i = min_pos + 1; i <= n - min_pos; i++) {
            arr[i] = arr[i - min_pos - 1 + max_pos];
        }
        printf_s("New array:");
        for (int i = 0; i <= n + min_pos - max_pos; i++) {
            printf_s(" %d", arr[i]);
        }
    }
    else {
        printf_s("Cant calculate new array.");
    }
}

void Task3() {
    int n = 40;
    int arr[ARR_MAX];
    int newarr[20];
    printf_s("Random Generation?(1 - yes, 0 - no)\n");
    int random;
    if (!scanf_s("%d", &random) || random > 1 || random < 0) {
        printf_s("Invalid input\n");
        scanf_s("%*s");
        Task1();
        return;
    }
    if (random == 1) printf_s("First Value:  ");
    for (int i = 0; i < n; i++) { //Creating loop that will fill array with user input
        
        int val;
        if (random == 1) {
            val = rand() % 10;
            printf_s("%d", val);
        }
        else {
            printf_s("\nWrite value at position %d: ", i);
            if (!scanf_s("%d", &val) || val > 9 || val < 0) {
                printf_s("Invalid input\n");
                scanf_s("%*s");
                i--;
            }
        }
        arr[i] = val;
        if (i == 19) printf_s("\nSecond Value: ");
    }
    for (int i = 0; i < 20; i++) { //fill new array with 0 to prevent errors
        newarr[i] = 0;
    }
    printf_s("\n");
    for (int val_pos = 19; val_pos >= 0; val_pos--) { //Creating loop that will calculate new value
        int value1 = arr[val_pos];
        int value2 = arr[20 + val_pos];
        newarr[val_pos] += value1 - value2;
        if (newarr[val_pos] < 0 && val_pos > 0) {
            newarr[val_pos - 1] -= 1;
            newarr[val_pos] += 10;
        }
        else if (newarr[val_pos] > 9) {
            newarr[val_pos] -= 10;
            newarr[val_pos - 1] += 1;
        }
    }
    for (int val_pos = 0; val_pos < 20; val_pos++) { //Creating loop that will write new value
        printf_s("%d", newarr[val_pos]);
    }
}
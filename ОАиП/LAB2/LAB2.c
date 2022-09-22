#include <iostream>

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
    int S;
    printf_s("Write S\n"); 
    if (!scanf_s("%d", &S) || S <= 7) { //Getting S value and check if S > 7
        printf_s("Invalid input\n");
        scanf_s("%*s");
        Task1();
        return;
    }
    for (int i = 0; i <= S / 5; i++) { //Creating loop
        if ((S - i * 5) % 3 == 0) {
            printf_s("a=%d, b=%d\n", (S - i * 5) / 3, i);
        }
    }
}

void Task2() {
    int n, S2 = 0, S3 = 0;
    printf_s("Write n\n");
    if (!scanf_s("%d", &n) || n < 1) { //Getting N value and check if N > 0
        printf_s("Invalid input\n");
        scanf_s("%*s");
        Task2();
        return;
    }
    for (int i = 1; i <= n; i++) { //Creating loop
        S2 += i * i;
        S3 += i * i * i;
    }
    printf_s("S2: %d\nS3: %d\n", S2, S3); 
}

void Task3() {
    int n;
    float x;
    printf_s("Write X\n");
    if (!scanf_s("%f", &x)) { //Getting X value
        printf_s("Invalid input\n");
        scanf_s("%*s");
        Task3();
        return;
    }
    printf_s("Write N\n");
    if (!scanf_s("%d", &n) || n < 1) { //Geting N value and check if N > 0
        printf_s("Invalid input\n");
        scanf_s("%*s");
        Task3();
        return;
    }

    float numb = x;
    for (int i = 1; i <= n; i++) {
        float up = x;
        float down = 1;
        float f = 2.0 * i + 1;
        for (int d = 1; d < f; d++) { //Create loop to calculate numerator and denomerator
            up *= x;
            down *= d + 1;
        }
        if (i % 2 == 0) // (-1)^n
            numb += up / down;
        else
            numb -= up / down;
    }
    printf_s("%f", numb);
}
#define PI 3.14159265358979323846
#include <iostream>

void Task1();
void Task2();
void Task3();
void Task4();

int main()
{
    printf_s("Enter Task (1-4)\n");
    int task;
    if (!scanf_s("%d", &task) || task > 4 || task < 1) {
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
    case 4:
        Task4();
        break;
    }
    getchar();
    fflush(stdin);
    getchar(); //Waiting for pressing ENTER to close program
}

void Task1() {
    float height, radius;
    printf_s("Write height and radius\n"); 
    if (scanf_s("%f%f", &height, &radius) != 2) { //Getting height and radius values 
        printf_s("Invalid inputs\n");
        return;
    }
    float Sside = 2 * PI * radius * height; //Calculating side S
    float Sfull = 2 * PI * radius * (radius + height); //Calculating full S
    float V = PI * radius * radius * height; //Calculating V
    printf_s("S side: %.2f\nS full: %.2f\nV: %.2f\n", Sside, Sfull, V); //Showing result
}

void Task2() {
    float m,n,p;
    printf_s("Write m,n,p\n");
    if (scanf_s("%f%f%f", &m,&n,&p) != 3) { //Getting m,n,p values
        printf_s("Invalid inputs\n");
        return;
    }
    int count = 0; //Variable count corresponds for "count negative values"
    if (m < 0) count++;
    if (n < 0) count++;
    if (p < 0) count++;
    printf_s("Negative values: %d\n", count); //Showing result
}

void Task3() {
    int x1,x2,x3,a,y1,y2,y3,b;
    printf_s("Write coords of first point\n");
    if (scanf_s("%d%d", &x1, &y1) != 2) { //Getting x1,y1 values
        printf_s("Invalid inputs\n");
        return;
    }

    printf_s("Write coords of second point\n");
    if (scanf_s("%d%d", &x2, &y2) != 2) { //Getting x2,y2 values
        printf_s("Invalid inputs\n");
        return;
    }

    printf_s("Write coords of third point\n");
    if (scanf_s("%d%d", &x3, &y3) != 2) { //Getting x3,y3 values
        printf_s("Invalid inputs\n");
        return;
    }

    printf_s("Write coords of M point\n");
    if (scanf_s("%d%d", &a, &b) != 2) { //Getting a,b values
        printf_s("Invalid inputs\n");
        return;
    }
    //Check if point M placed in triangle
    if ((a - x1) * (y1 - y2) - (b - y1) * (x1 - x2) >= 0 && (a - x2) * (y2 - y3) - (b - y2) * (x2 - x3) >= 0 && (a - x3) * (y3 - y1) - (b - y3) * (x3 - x1) >= 0) {
        printf_s("Yes\n");
    }
    else {
        printf_s("No\n");
    }
}

void Task4() {
    int age;
    printf_s("Write age\n");
    if (!scanf_s("%d", &age) || age < 1 || age > 9) { //Getting age value and check if age 9 > age > 1
        printf_s("Invalid inputs\n");
        return;
    }
    setlocale(LC_ALL, "Russian"); //Enabling Russian support
    printf_s("Мне %d ", age); //Showing first part of sentence
    switch (age) { //Showing second part of sentence based on variable age
    case 1:
        printf_s("год\n");
        break;
    case 2: case 3: case 4:
        printf_s("года\n");
        break;
    default:
        printf_s("лет\n");
        break;
    }
}
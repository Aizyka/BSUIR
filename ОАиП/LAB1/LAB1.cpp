// LAB1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
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
    getchar(); //Ожидание нажатия ENTER для закрытия программы
}

void Task1() {
    float height, radius;
    printf_s("Write height and radius\n"); 
    if (scanf_s("%f%f", &height, &radius) != 2) { //получаем данные о высоте и радиусе и записываем эти данные в переменную
        printf_s("Invalid inputs\n");
        return;
    }
    float Sside = 2 * PI * radius * height; //вычисляем площадь боковой поверхности
    float Sfull = 2 * PI * radius * (radius + height); //вычисляем площадь полной поверхности
    float V = PI * radius * radius * height; //вычисляем объём
    printf_s("S side: %.2f\nS full: %.2f\nV: %.2f\n", Sside, Sfull, V); //выводим данные о проделанных операциях
}

void Task2() {
    float m,n,p;
    printf_s("Write m,n,p\n");
    if (scanf_s("%f%f%f", &m,&n,&p) != 3) { //получаем числа и записываем их в переменные
        printf_s("Invalid inputs\n");
        return;
    }
    int count = 0; //переменная count отвечает за количество отрицательных чисел
    if (m < 0) count++;
    if (n < 0) count++;
    if (p < 0) count++;
    printf_s("Negative values: %d\n", count); //выводим количество отрицательных чисел
}

void Task3() {
    int x1,x2,x3,a,y1,y2,y3,b;
    printf_s("Write coords of first point\n");
    if (scanf_s("%d%d", &x1, &y1) != 2) { //получаем координаты x1,y1 и записываем в эти же переменные
        printf_s("Invalid inputs\n");
        return;
    }

    printf_s("Write coords of second point\n");
    if (scanf_s("%d%d", &x2, &y2) != 2) { //получаем координаты x2,y2 и записываем в эти же переменные
        printf_s("Invalid inputs\n");
        return;
    }

    printf_s("Write coords of third point\n");
    if (scanf_s("%d%d", &x3, &y3) != 2) { //получаем координаты x3,y3 и записываем в эти же переменные
        printf_s("Invalid inputs\n");
        return;
    }

    printf_s("Write coords of M point\n");
    if (scanf_s("%d%d", &a, &b) != 2) { //получаем координаты a,b и записываем в эти же переменные
        printf_s("Invalid inputs\n");
        return;
    }
    //Здесь проверяем, находится ли точка M в треугольнике
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
    if (!scanf_s("%d", &age) || age < 1 || age > 9) { //получаем данные о возрасте, записываем в переменную age, проверяем промежуток 9>age>1
        printf_s("Invalid inputs\n");
        return;
    }
    setlocale(LC_ALL, "Russian"); //включаем поддержку русского языка для корректного вывода программы
    printf_s("Мне %d ", age); //выводим начальные данные
    switch (age) { //выводим дополнительное слово, смотря на данные переменной age
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



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

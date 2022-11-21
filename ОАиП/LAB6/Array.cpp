#include "Array.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string>
#include "IO.h"

int rand(int min, int max) {
	return min + (rand() % (max - min + 1));
}

int* allocate(int size) {
	return (int*)(malloc(size * sizeof(int)));
}

int** allocate_sec(int x, int y) {
	int** arr = (int**)(malloc(x * sizeof(int*)));
	for (int i = 0; i < x; i++) {
		arr[i] = (int*)(malloc(y * sizeof(int)));
	}
	return arr;
}

int** allocate_sec(int x) {
	int** arr = (int**)(malloc(x * sizeof(int*)));
	return arr;
}

void rem_element(int*& arr, int pos, int size) {
	int* temp = (int*)malloc((size - 1) * sizeof(int));
	memmove(temp, arr, (pos) * sizeof(int));
	memmove(temp + pos, (arr)+(pos + 1), (size - pos) * sizeof(int));
	free(arr);
	arr = temp;
}

void rem_element_sec(int*& arr, int pos, int size) {
	int* temp = (int*)malloc((size - 1) * sizeof(int));
	memmove(temp, arr, (pos) * sizeof(int));
	memmove(temp + pos, (arr)+(pos + 1), (size - pos) * sizeof(int));
	arr = temp;
}

int* write_until_number(int number, int* size) {
	*size = 0;
	int* temp = (int*)malloc(sizeof(int));
	int i = 0;
	while (true) {
		int entered;
		printf_s("Write number: ");
		while (!scanf_s("%d", &entered) || (entered < 1 && entered != number) || getchar() != '\n') {
			printf_s("\nInvalid number!\n");
			rewind(stdin);
		}
		if (entered == number) break;
		temp[i] = entered;
		(*size)++;
		i++;
		temp = (int*)realloc(temp, (i + 1) * sizeof(int));
	}
	return temp;
}

int* duplicate(int * arr, int size) {
	int* new_arr = (int*)(malloc(size * sizeof(int)));;
	memmove(new_arr, arr, (size) * sizeof(int));
	return new_arr;
}

void rand_array_sec(int**& arr, int x, int y, int min, int max) {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			arr[i][j] = rand(min, max);
		}
	}
}

void user_array_sec(int**& arr, int x, int y, int min) {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			printf_s("\nWrite element at pos (%d, %d): ", i, j);
			arr[i][j] = getint(min);
		}
	}
}

void print_array_sec(int** arr, int x, int y) {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			printf_s("\nElement at pos (%d, %d): %d", i, j, arr[i][j]);
		}
	}
	printf_s("\n");
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			printf_s("%d\t", arr[i][j]);
		}
		printf_s("\n");
	}
}

void rand_array(int*& arr, int x, int min, int max) {
	for (int i = 0; i < x; i++) {
		arr[i] = rand(min, max);
	}
}

void user_array(int*& arr, int x) {
	for (int i = 0; i < x; i++) {
		printf_s("\nWrite element at pos (%d): ", i);
		arr[i] = getint();
	}
}

void print_array(int* arr, int x) {
	for (int i = 0; i < x; i++) {
		printf_s("\nElement at pos (%d): %d", i, arr[i]);
	}
}

void print_array_with_sizes(int** arr, int* size, int rows) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < size[i]; j++) {
			printf_s("%d\t", arr[i][j]);
		}
		printf_s("\n");
	}
}
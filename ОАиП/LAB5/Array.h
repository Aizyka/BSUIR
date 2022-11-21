#ifndef ARRAY_HEADER
#define ARRAY_HEADER

int* allocate(int size);
int** allocate_sec(int x, int y);
int** allocate_sec(int x);
void rem_element(int*& arr, int pos, int size);
void rem_element_sec(int*& arr, int pos, int size);
int* write_until_number(int number, int* size);

void rand_array_sec(int**& arr, int x, int y, int min, int max);
void user_array_sec(int**& arr, int x, int y, int min);
void print_array_sec(int** arr, int x, int y);

void rand_array(int*& arr, int x, int min, int max);
void user_array(int*& arr, int x);
void print_array(int* arr, int x);
void print_array_with_sizes(int** arr, int* size, int rows);
#endif
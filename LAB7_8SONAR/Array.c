#include "Array.h"
#include <stdio.h>
#include <stdlib.h>
#include "IO.h"

int* allocate(int size) {
    return (int*)(malloc(size * sizeof(int)));
}
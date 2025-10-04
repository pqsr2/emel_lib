#ifndef ARRAY_H
#define ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>
#include <stdbool.h>

struct Array
{
    double *data;
    int size;
    int capacity;
};

struct Array *init_array(int capacity);
int push_back(struct Array *array, double value);
bool get(struct Array *array, int index, double *value);
void free_array(struct Array **array);

#endif
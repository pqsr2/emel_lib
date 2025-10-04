#include <stdio.h>
#include <errno.h>
#include "core/array.h"

int main()
{
    struct Array *myArray = init_array(5);
    if (myArray == NULL)
    {
        return ENOMEM;
    }
    printf("Array created successfully.\n");

    for (int j = 0; j < 7; ++j)
    {
        push_back(myArray, 42.0);
    }

    printf("The elements of the array are:\n");
    double element;
    for (int k = 0; k < myArray->size; ++k)
    {
        get(myArray, k, &element);
        printf("%f ", element);
    }
    printf("\n");
    free_array(&myArray); // address-of operator &: to pass a pointer to the value

    return 0;
}
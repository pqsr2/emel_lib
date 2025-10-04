#include "core/array.h"

/**
 * Initializes a new Array structure with the specified capacity.
 *
 * This function allocates memory for a new Array structure and its data buffer
 * with the given initial capacity. The array starts empty (size = 0).
 *
 * @param capacity The initial capacity of the array (number of elements it can hold)
 * @return A pointer to the newly allocated and initialized Array structure,
 *         or NULL if memory allocation fails
 *
 * @note The caller is responsible for freeing the allocated memory when done
 *       using the array by calling the appropriate cleanup function.
 */
struct Array *init_array(int capacity)
{
    struct Array *array = malloc(sizeof(struct Array));
    if (array == NULL)
    {
        printf("Could not allocate memory for array struct.\n");
        return NULL;
    }

    array->data = (double *)malloc(capacity * sizeof(double));
    if (array->data == NULL)
    {
        printf("Could not allocate memory.\n");
        return NULL;
    }

    array->size = 0;
    array->capacity = capacity;

    return array;
}

/**
 * Adds a value to the end of the array.
 * Automatically resizes the array if necessary by doubling its capacity.
 *
 * @param array Pointer to the Array structure to modify
 * @param value The double value to add to the array
 *
 * @return 0 on success, 1 if memory allocation fails during resizing
 */
int push_back(struct Array *array, double value)
{
    // Resize if necessary
    if (array->size == array->capacity)
    {
        int new_capacity = array->capacity * 2;
        if (new_capacity == 0)
            new_capacity = 1;

        double *new_data = realloc(array->data, new_capacity * sizeof(double));
        if (new_data == NULL)
        {
            printf("Failed to resize array data.\n");
            return ENOMEM;
        }

        array->data = new_data;
        array->capacity = new_capacity;
    }

    // Add element
    array->data[array->size] = value;
    array->size++;
    return 0;
}

/**
 * Retrieves the value at the specified index from the array.
 *
 * @param array Pointer to the Array structure
 * @param index The index of the element to retrieve
 * @param value Pointer to store the retrieved value if successful
 *
 * @return true if the index is valid and value was retrieved,
 *         false if the index is out of bounds
 */
bool get(struct Array *array, int index, double *value)
{
    if (0 <= index && index < array->size)
    {
        *value = array->data[index];
        return true;
    }
    return false;
}

/**
 * @brief Frees memory allocated to an Array structure and its data.
 *
 * This function deallocates memory used by an Array structure and its internal data.
 * It also sets the pointer to NULL to prevent use-after-free errors. The function
 * safely handles cases where array_ptr or *array_ptr is NULL.
 *
 * @param array_ptr Double pointer to the Array structure to be freed.
 *                  Using a double pointer allows setting the original pointer to NULL.
 *
 * @note After calling this function, the pointer passed to it will be set to NULL,
 *       making it safe for subsequent operations.
 */
void free_array(struct Array **array_ptr)
{
    // The Double-Pointer Pattern:
    // The reason for using struct Array **array_ptr is to be able to set the caller's pointer to NULL.
    // This is a common pattern in C for functions that completely dispose of resources.
    if (array_ptr == NULL || *array_ptr == NULL)
    {
        return;
    }

    if ((*array_ptr)->data != NULL)
    {
        free((*array_ptr)->data);
    }
    // Free the struct
    free(*array_ptr);

    *array_ptr = NULL; // Prevent use-after-free
    return;
}

#include "reverse_list_recursively.h"

int* revR(int* array, int n)
{
    if (n < 2) {
        return array;
    }
    int temp = array[0];
    array[0] = array[n - 1];
    array[n - 1] = temp;
    revR(array + 1, n - 2);
    return array;
}

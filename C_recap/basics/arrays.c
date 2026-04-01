#include <stdio.h>

int main() {

    int arr[5] = {1, 2, 3, 4, 5};
    int *start_ptr = &arr[0];
    int *end_ptr = &arr[5];

    printf("The contents of the array are: \n");

    while (start_ptr < end_ptr) { // comparing the pointer addresses, not the values.
        printf("%d \n", *start_ptr);
        start_ptr++;
    }

    return 0;
}

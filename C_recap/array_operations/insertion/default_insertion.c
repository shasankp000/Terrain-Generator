#include <stdio.h>
#include <stdlib.h>


int main() {

    int n_elements_def;

    printf("Enter number of elements for the array: ");
    scanf("%d", &n_elements_def);
    printf("\n");

    int *arr = (int *) malloc(n_elements_def * sizeof(int)); // (type *) malloc(n * sizeof(type))

    if (arr == NULL) { 
        printf("Dynamic memory allocation for array failed");
        return 1;
    }

    // fill up the array

    for (int i = 0; i<n_elements_def; i++) {
        arr[i] = i+1;
    }

    printf("Elements of the array are: \n");

    for (int j = 0; j<n_elements_def; j++) { 
        printf("arr[%d] = %d \n", j, arr[j]);
    }

    // free up the memory

    free(arr);
    arr = NULL; 

    return 0;
}
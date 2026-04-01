#include<stdio.h>
#include<stdlib.h>

int *pop(int *arr, int *size) {

    if (*size <= 0) {
        printf("Array is already empty.\n");
        return arr;
    }

    arr[*size-1] = 0;
    (*size)--;

    int *temp_arr = (int *) realloc(arr, (*size) * sizeof(int));

    if (temp_arr == NULL && *size > 0) {
        printf("Memory re-allocation for the array failed.\n");
        return arr;
    }

    if (*size == 0) {
        printf("Array has been emptied. Freeing up memory.");
        free(arr); // array is empty.
        return NULL;
    }

    return temp_arr;

}


int main() {

    int *n_elements_def = (int *) malloc(sizeof(int));
    int *arr;
    char choice;

    if (n_elements_def == NULL) {
        printf("Memory allocation for size failed.\n");
        return 1;
    }

    printf("Enter number of elements for the array: ");
    scanf("%d", n_elements_def);

    arr = (int *) malloc(*n_elements_def * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i=0; i<*n_elements_def; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
        printf("\n");
    }

    printf("\n");
    printf("Array after insertion:");
    printf("\n\n");

    for (int i=0; i<*n_elements_def; i++) {
        printf("arr[%d] = %d \n", i, arr[i]);
    }

    printf("\n");

    printf("Pop element (y/n)? ");
    scanf(" %c", &choice); // space added so that scanf doesn't pick up the whitespace after the ? instead.

    switch (choice) {
        case 'y':
            arr = pop(arr, n_elements_def);

            printf("Array after popping the array: ");
            printf("\n\n");

            for (int i=0; i<*n_elements_def; i++) {
                printf("arr[%d] = %d \n", i, arr[i]);
            }

            printf("\n");

            break;

        case 'n':
            printf("Exiting....\n");
            break;

        default:
            printf("Invalid input. Exiting... \n");
            break;
    }

    free(arr); // free up the array
    free(n_elements_def); // free the size pointer

    return 0;

}

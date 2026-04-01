#include<stdio.h>
#include<stdlib.h>


int main() {

    int *n_elements_def1 = (int *) malloc(sizeof(int));
    int *n_elements_def2 = (int *) malloc(sizeof(int));
    int *total_size = (int *) malloc(sizeof(int));
    int *arr1, *arr2, *final_arr = NULL;

    if (!n_elements_def1 || !n_elements_def2 || !total_size) {
        printf("Memory allocation for pointers failed.");

        free(n_elements_def1);
        free(n_elements_def2);
        free(total_size);

        return 1;
    }

    printf("Enter number of elements for the first array: ");
    scanf("%d", n_elements_def1);

    arr1 = (int *) malloc(*n_elements_def1 * sizeof(int));

    if (arr1 == NULL) {
        printf("Memory allocation failed.\n");
        printf("Performing memory cleanup... \n\n");

        free(n_elements_def1);
        free(n_elements_def2);
        free(total_size);

        printf("Exiting...");

        return 1;
    }

    for (int i=0; i<*n_elements_def1; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr1[i]);
        printf("\n");
    }

    printf("\n");
    printf("First array after insertion:");
    printf("\n\n");

    for (int i=0; i<*n_elements_def1; i++) {
        printf("arr1[%d] = %d \n", i, arr1[i]);
    }

    printf("Enter number of elements for the second array: ");
    scanf("%d", n_elements_def2);

    arr2 = (int *) malloc(*n_elements_def2 * sizeof(int));

    if (arr2 == NULL) {
        printf("Memory allocation failed.\n");

        printf("Performing memory cleanup... \n\n");

        free(n_elements_def1);
        free(n_elements_def2);
        free(total_size);
        free(arr1);

        printf("Exiting...");

        return 1;
    }

    for (int i=0; i<*n_elements_def2; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr2[i]);
        printf("\n");
    }

    printf("\n");
    printf("Second array after insertion:");
    printf("\n\n");

    for (int i=0; i<*n_elements_def2; i++) {
        printf("arr2[%d] = %d \n", i, arr2[i]);
    }

    *total_size = *n_elements_def1 + *n_elements_def2;

    final_arr = (int *) malloc(*total_size * sizeof(int));

    if (final_arr == NULL) {
        printf("Memory allocation failed.\n");

        printf("Performing memory cleanup... \n\n");

        free(n_elements_def1);
        free(n_elements_def2);
        free(total_size);
        free(arr1);
        free(arr2);

        printf("Exiting...");

        return 1;
    }

    // loop 1, copy from first array.

    for (int i=0; i<*n_elements_def1; i++) {
        final_arr[i] = arr1[i];
    }

    // loop 2, copy from second array, start at the tail end.

    for (int i=0; i<*n_elements_def2; i++) {
        final_arr[*n_elements_def1+i] = arr2[i];
    }

    printf("Final array: ");
    printf("\n\n");

    for (int i=0; i<*total_size; i++) {
        printf("final_arr[%d] = %d \n", i, final_arr[i]);
    }

    printf("Performing memory cleanup... \n\n");

    free(n_elements_def1);
    free(n_elements_def2);
    free(total_size);
    free(arr1);
    free(arr2);
    free(final_arr);

    printf("Exiting...");

    return 0;
}

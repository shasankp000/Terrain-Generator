#include<stdio.h>
#include<stdlib.h>

#define NaN -1

int indexof(int element, int *arr, int *size) {

    for (int index_value = 0; index_value<*size; index_value++) {

        if (arr[index_value] == element) {
            return index_value;
        }

    }

    return NaN;

}

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
        printf("\n\n");
        return NULL;
    }

    return temp_arr;

}

int main() {

    int *n_elements_def = (int *) malloc(sizeof(int));
    int *size_before_index = (int *) malloc(sizeof(int));
    int *size_after_index = (int *) malloc(sizeof(int));
    int *del_element = (int *) malloc(sizeof(int));
    int *del_index = (int *) malloc(sizeof(int));
    int *old_size = (int *) malloc(sizeof(int));
    int *arr, *final_arr = NULL;

    *size_before_index = 0;
    *size_after_index = 0;

    if (!n_elements_def || !size_before_index || !size_after_index ||!del_element || !del_index || !old_size) {
        printf("Memory allocation for pointers failed.");

        free(n_elements_def);
        free(size_before_index);
        free(size_after_index);
        free(del_index);
        free(del_element);
        free(old_size);

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

    printf("Enter element to be deleted: ");
    scanf("%d", del_element);
    printf("\n\n");

    *del_index = indexof(*del_element, arr, n_elements_def);

    if (*del_index == NaN) {
        printf("Error! Element does not exist in the array.");
    }
    else {
        // edge case checks

        // only one element in array

        if (*n_elements_def == 1) {
            arr = pop(arr, n_elements_def);
        }

        // element to be deleted is the last element

        else if (*del_element == arr[*n_elements_def-1]) {
            arr = pop(arr, n_elements_def);

            printf("Array after deleting %d: ", *del_element);
            printf("\n\n");

            for (int i=0; i<*n_elements_def; i++) {
                printf("arr[%d] = %d \n", i, arr[i]);
            }

            printf("\n\n");
        }

        else if (*del_index > 0 && *del_index < *n_elements_def-1) {
            // element to be deleted is somewhere in the middle of the array

            // calculate the size of the elements before the element.

            for (int i=0; i<*del_index; i++) {
                (*size_before_index)++;
            }

            for (int i = *del_index+1; i<*n_elements_def; i++) {
                (*size_after_index)++;
            }

            *old_size = *n_elements_def;
            *n_elements_def = *size_before_index + *size_after_index;


            final_arr = (int *) malloc(*n_elements_def * sizeof(int));

            for (int i=0; i<*del_index; i++) {
                final_arr[i] = arr[i];
            }

            for (int i = *del_index+1; i<*old_size; i++) {
                final_arr[i-1] = arr[i];
            }

            printf("Array after deleting %d: ", *del_element);
            printf("\n\n");

            for (int i=0; i<*n_elements_def; i++) {
                printf("arr[%d] = %d \n", i, final_arr[i]);
            }

            printf("\n\n");


        }
    }


    printf("Performing memory cleanup... \n\n");

    free(n_elements_def);
    free(old_size);
    free(del_element);
    free(size_before_index);
    free(size_after_index);
    free(del_index);
    free(arr);

    if (final_arr != NULL) {
        free(final_arr);
    }

    printf("Exiting...");

    return 0;
}

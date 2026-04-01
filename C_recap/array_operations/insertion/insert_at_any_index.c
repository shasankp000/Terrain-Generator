#include <stdio.h>
#include <stdlib.h>

#define NaN -1

int indexof(int element, int *arr, int size) {

    for (int index_value = 0; index_value<size; index_value++) {

        if (arr[index_value] == element) {
            return index_value;
        }

    }

    return NaN;

}

int main() {

    int n_elements_def, last_element_index, insert_index, new_element;

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

    printf("Initial elements of the array are: \n");

    for (int j = 0; j<n_elements_def; j++) {
        printf("arr[%d] = %d \n", j, arr[j]);
    }


    last_element_index = indexof(n_elements_def, arr, n_elements_def);

    printf("Enter index at which you want to insert the element: ");
    scanf("%d", &insert_index);
    printf("\n");

    n_elements_def = n_elements_def + 1; // increase the total size by 1.

    int *temp_arr = (int *) realloc(arr, n_elements_def * sizeof(int));

    if (temp_arr == NULL) {

        printf("Array memory reallocation failed. Exiting...");
        free(arr);
        arr = NULL;

        return 1;

    }

    arr = temp_arr;


    // shift all elements beyond the chosen index by 1 place.
   for (last_element_index; last_element_index>=insert_index; last_element_index--) {
        arr[last_element_index+1] = arr[last_element_index];
   }

   printf("Enter element to be inserted: ");
   scanf("%d", &new_element);
   printf("\n");

   arr[insert_index] = new_element;



   printf("Final array: \n");

   for (int j = 0; j<n_elements_def; j++) {
    printf("arr[%d] = %d \n", j, arr[j]);
   }

   // free up memory.

   free(arr);
   arr = NULL;

    return 0;
}

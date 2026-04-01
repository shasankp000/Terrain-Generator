#include <stdio.h>
#include <stdlib.h>

#define NaN -1

int indexof(int element, int *arr, int size) {
    int index_value = 0;

    for (index_value; index_value<size; index_value++) {

        if (arr[index_value] == element) { 
            return index_value;
        }
        
    }

    return NaN;

}

int main() {

    int n_elements_def, last_element_index, n_elements_new;
    char choice;

    printf("Enter number of elements for the array: ");
    scanf("%d", &n_elements_def);
    printf("\n");

    int *arr = (int *) malloc(n_elements_def * sizeof(int)); // (type *) malloc(n * sizeof(type))

    if (arr == NULL) { 
        printf("Dynamic memory allocation for array failed!");
        return 1;
    }

    // fill up the array

    for (int i = 0; i<n_elements_def; i++) {
        arr[i] = i+1;
    }

    last_element_index = indexof(n_elements_def, arr, n_elements_def);

    printf("Elements of the array are: \n");

    for (int j = 0; j<n_elements_def; j++) { 
        printf("arr[%d] = %d \n", j, arr[j]);
    }

    printf("Last element index on the array: %d \n", last_element_index);

    printf("The array is full, do you want to enter new elements again? (y/n): ");
    scanf(" %c", &choice);
    printf("\n");

    switch (choice) {

        case 'y':

            printf("Enter new number of elements for the array (add previous size + the new size you want): ");
            scanf("%d", &n_elements_new);
            printf("\n");

            int *new_arr = (int *) realloc(arr, n_elements_new * sizeof(int)); // (type *) realloc(ptr to be reallocated, size * sizeof(type))

            if (new_arr == NULL) {
                printf("Memory reallocation failed. Exiting...");
                free(arr); // free up the existing array to prevent dangling pointers and memory leaks;
                arr = NULL;
                return 1;
            }

            arr = new_arr;

            last_element_index = last_element_index + 1; // start from the new empty position after the currently last element.

            // fill up the remaining of the array

            for (last_element_index; last_element_index<n_elements_new; last_element_index++) {
                arr[last_element_index] = last_element_index+1;
            }

            printf("Elements of the new array after reallocation are: \n");

            for (int j = 0; j<n_elements_new; j++) { 
                printf("arr[%d] = %d \n", j, arr[j]);
            }

            // free up the memory of the array

            free(arr);
            arr = NULL;

            break;

        case 'n':
            printf("Exiting....");

            // free up the memory
            free(arr);
            arr = NULL;

            break;

        default:
            printf("Invalid input! Exiting....");
            return 1;
    }


    return 0;
}
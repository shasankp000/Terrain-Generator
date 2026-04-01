#include <stdio.h>

int main() {

    int a, b;
    int *ptr1, *ptr2;

    a = 6;
    b = 7;

    ptr1 = &a; // ptr1 now has the reference to a's value.

    ptr2 = &b;

    printf("Address of a = %d is %p \n", *ptr1, (void *)ptr1); // (void *) ptr1 prints the memory address of the value of a. %d is in decimal format and %p is for hexadecimal
    printf("Address of b = %d is %p \n", *ptr2, (void *)ptr2); 

    return 0;
}
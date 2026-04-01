#include <stdio.h>

int sum(int a, int b) { 
    int val = a + b;
    return val;
}

int main() {

    int a, b;
    int *ptr1, *ptr2;
    printf("Enter the first number: ");
    scanf("%d", &a);
    printf("\n");
    printf("Enter the second number: ");
    scanf("%d", &b);
    printf("\n");

    ptr1 = &a;
    ptr2 = &b;

    int result = sum(*ptr1, *ptr2);
    printf("The sum of %d and %d is %d \n", *ptr1, *ptr2, result);

    return 0;
}
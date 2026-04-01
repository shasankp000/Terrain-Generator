#include <stdio.h>

int sum(int a, int b) { 
    int val = a + b;
    return val;
}

int main() {

    int a, b;
    printf("Enter the first number: ");
    scanf("%d", &a);
    printf("\n");
    printf("Enter the second number: ");
    scanf("%d", &b);
    printf("\n");

    int result = sum(a, b);
    printf("The sum of %d and %d is %d \n", a, b, result);

    return 0;
}
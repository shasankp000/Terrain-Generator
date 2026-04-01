#include <stdio.h>

int main() {

    struct Profile {
        char Name[50];
        int Age;
    };

    // declare the struct instance and assign the values.

    struct Profile p1 = {"Shasank", 22};
    
    printf("Subject's name is: %s \n", p1.Name);
    printf("Subject's age is: %d \n", p1.Age);
    
    return 0;
}
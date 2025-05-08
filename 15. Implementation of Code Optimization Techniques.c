#include <stdio.h>
int main() {
    int n, choice, i, fact = 1;
    printf("Choose method to calculate:\n"); 
    printf("for loop\n"); 
    printf("do-while loop\n");
    printf("Enter(1 or 2): "); 
    scanf("%d", &choice); 
    printf("Enter an integer: ");
    scanf("%d", &n);
    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        return 1;}
    switch (choice) {
        case 1:
            fact = 1; for (i = 1; i <= n; ++i) {
                fact *= i;
}
 printf("The factorial value is: %d\n", fact);
               break;
        case 2:
            { 
                int temp = n; fact = 1;
                do { fact *= temp; temp--;
                } while (temp > 0);
                printf("The factorial value is: %d\n", fact);}
            break;
        default:
            printf("Invalid choice.\n");
            break;}
    return 0;}

/*
Program to enter two integer numbers and checks if the first is evenly divisible by the second
*/

#include <stdio.h>

int main()
{
    int num1 = 0;
    int num2 = 0;

    printf("Enter any two whole numbers\n");
    scanf("%d", &num1);
    scanf("%d", &num2);

    // Check if the first number is evenly divisible by the second
    if ( (num1 % num2) == 0 )
    {
        printf("\n%d is divisible by %d", num1, num2);

    } // end if
    else
    {
        printf("\n%d is NOT divisible by %d", num1, num2);
    } // end else
    
    return 0;

} // end main
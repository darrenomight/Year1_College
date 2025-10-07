/*
Program to enter a number between 1 -100 and check whether it is even or odd
*/

#include <stdio.h>

int main()
{
    int num = 0;

    printf("Enter any number between 1 - 100\n");
    scanf("%d", &num);

    // Check if the number entered is between 1 - 100
    if(num > 0 && num < 101)
    {
        // Check if the number is even or odd
        // Divide the number by 2 and check for a remainder

        if ( (num % 2) == 0 )
        {
            printf("\nThe number entered is Even");
        } // end if
        else
        {
            printf("\nThe number entered is Odd");
        } // end else

    } // end if
    else
    {
        printf("\nInvalid number entered");
    } // end else

    return 0;

} // end main
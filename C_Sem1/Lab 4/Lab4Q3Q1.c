/*
Program to enter a character and using a switch statement to check the marriage status
*/

#include <stdio.h>

int main()
{
    char marriage_status = ' ';

    printf("Enter marriage status: S, M, W, E, D\n");
    scanf("%c", &marriage_status);

    // check if the character is a vowel, i.e., a, e, i, o, u
    switch(marriage_status)
    {
        case 'S':
        {
            printf("\nSingle");
            break;
        } // end case 'S'

        case 'M':
        {
            printf("\nMarried");
            break;
        } // end case 'M'

        case 'W':
        {
            printf("\nWidowed");
            break;
        } // end case 'W'

        case 'E':
        {
            printf("\nSeparated");
            break;
        } // end case 'E'

        case 'D':
        {
            printf("\nDivorced");
            break;
        } // end case 'D'
        
        default:
        {
            printf("\nThe character you entered is NOT valid");
        } // end case 'a'

    } // end switch

    return 0;

} // end main
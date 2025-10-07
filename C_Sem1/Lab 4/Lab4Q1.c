/*
Program to enter a character and using a switch statement to check whether it is a vowel or not
*/

#include <stdio.h>

int main()
{
    char my_char = ' ';

    printf("Enter any character a - z\n");
    scanf("%c", &my_char);

    // check if the character is a vowel, i.e., a, e, i, o, u
    switch(my_char)
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
        {
            printf("\n%c is a vowel", my_char);
            break;
        } // end case 'a'
        
        default:
        {
            printf("\nThe character you entered is NOT a vowel");
        } // end case 'a'

    } // end switch

    return 0;

} // end main
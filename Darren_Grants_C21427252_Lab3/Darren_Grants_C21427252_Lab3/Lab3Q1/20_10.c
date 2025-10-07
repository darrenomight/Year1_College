#include <stdio.h>

int main()
{
    char oper;
    float num1, num2, answer;

    printf("Enter a simple maths operation\n");
    
    scanf("%f", &num1);
    scanf("%c", &oper);
    scanf("%f", &num2);

    // Now use the switch statement

    switch (oper)
    {
        case '+':
        {
            answer = num1 + num2;
            printf("\n%.1f PLUS %.1f is %.1f", num1, num2, answer);
            break;
        } // end case '+'

        case '-':
        {
            answer = num1 - num2;
            printf("\n%.1f MINUS %.1f is %.1f", num1, num2, answer);

            break;
        } // end case '-'

        case '*':

        case 'x':

        case 'X':
            // similar to: if (oper == '*' || oper == 'x' || oper == 'X')
        {
            answer = num1 * num2;

            printf("\n%.1f MULTIPLY %.1f is %.1f", num1, num2, answer);

            break;

        } // end case '*'

        case '/':
        {
            answer = num1 / num2;

            printf("\n%.1f DIVIDE %.1f is %.1f", num1, num2, answer);
        
            break;
        } // end case '/'

        default:
        {
            printf("\nInvalid operator entered");
            break;
        } // end default

    } // end switch

    return 0;

} // end main
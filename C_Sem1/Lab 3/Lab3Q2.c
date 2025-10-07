//Programm to collect and display 2 characters from user input, Darren G, 19/10/21
#include <stdio.h>

int main(void)
{
    char let1 = ' ';
    char let2 = ' ';   

    printf("\nPlease Input two single letters\n");

    scanf("%1s",&let1);
    while (getchar() != '\n');
    scanf("%c",&let2);
    
    printf("\nYour Characters are %c and %c",let1,let2);

    return(0);
}
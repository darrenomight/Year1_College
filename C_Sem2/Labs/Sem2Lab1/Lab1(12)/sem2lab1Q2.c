/*program to print a character X amount of times*/
#include <stdio.h>

//#define SIZE 10

void Letter(char ,int);

int main(void)
{
    int num = 0;
    char my_char;
    
    printf("\nProgramn Start chose a character\n");
    scanf("%c",&my_char);
    
    while(getchar() != '\n');

    printf("\nHow many times good sir?\n");
    scanf("%d",&num);
    
    Letter(my_char, num);

    printf("\n\n We got %c %d times POGGERS\n",my_char, num);

    return 0;
}

void Letter(char my_char, int num)
{
    int i;
    for (i = 0; i < num; i++)
    {
        printf("%c",my_char);
    }

}
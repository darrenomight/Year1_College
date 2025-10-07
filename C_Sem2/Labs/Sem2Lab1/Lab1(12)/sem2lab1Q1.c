/* Programn to Make a function print 10 stars when called */
#include <stdio.h>

#define SIZE 10

void stars(int);

int main(void)
{
    int num = SIZE;
    
    printf("\nProgramn Start\n");
    

    stars(num);

    printf("\n\n We got %d stars POGGERS\n",SIZE);

    return 0;
}

void stars(int num)
{
    int i;
    for (i = 0; i < SIZE; i++)
    {
        printf("*");
    }

}


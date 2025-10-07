/*program to print a character X amount of times*/
#include <stdio.h>

//#define SIZE 10

int Nummers(int ,int,int);

int main(void)
{
    int num1 = 10;
    int num2 = 420;
    int num3 = 36;
    
    printf("\nProgramn Starting to find your 3 Intergers order!!!\n");
    
    Nummers(num1, num2, num3);

    return 0;
}

int Nummers(int num1, int num2, int num3)
{
    int high = 0;
    int low = 0;

    if (num1 < num2 && num1 < num3)
    {
        low = num1;
        printf("%d",low);
    }
    else if (num2 < num1 && num2 <num3)
    {
        low = num2;
        printf("%d",low);
    }
    else
    {
         low = num3;
         printf("%d",low);
    }

    if (num1 > num2 && num1 > num3)
    {
        high = num1;
        printf("%d",high);
    }
    else if (num2 > num1 && num2 > num3)
    {
        high = num2;
        printf("%d",high);
    }
    else
    {
         high = num3;
         printf("%d",high);
    }

    printf("\n\n Highest number =%d low =%d",high,low);
}
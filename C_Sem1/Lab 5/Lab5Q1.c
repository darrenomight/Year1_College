//Darren Grants
//02_11_21
//Program using a loop to display 1-10 desending with Comma no comma for last.
#include <stdio.h>
int main(void)
{
    int num = 10;

    while (num != 1)
    {
        printf("%d,",num);
        num = num-1;

        if(num==1)
        printf("%d",num);
    }
 return 0;
}
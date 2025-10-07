//Darren Grants
//02_11_21
//Programm that takes postive integers that does X and Y until =1 disaply the inputs
#include <stdio.h>

int main(void)
{
    int usernum = 0;
    int counter = 0;
   
   
    do
    {
        printf("Please input any Postive integer\n");
        scanf("%d", &usernum);
        
    }   while (usernum < 0);
   

    //start of the system
    //while usernum is not 1 start system
    while (usernum > 1)
    {
        //if even divide by 2
        if (usernum % 2 == 0)
        {
            usernum = usernum / 2;
            printf("Next value is %d\n",usernum);
    
        }
        // anything else *3+1
        else
        {
            usernum = (usernum * 3) + 1;
            printf("Next value is %d\n",usernum);
        }
        //counts amounts done
        counter++;
    }

    printf("Final Value is %d Number of steps %d",usernum,counter);
   
return 0;   
}
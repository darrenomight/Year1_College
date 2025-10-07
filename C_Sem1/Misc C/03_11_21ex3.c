#include <stdio.h>

int main(void)
{
    int num = 0;
    int counter = 0;


    do
    {
        printf("\nEnter a number between 1 and 5\n");
        scanf("%d",&num);
    }while(num < 1 ||)
    //check num divisible by 1-20
    do
    {
        if(counter % num == 0)
        {
            printf("\n%d is divisible by %d",counter,num);
        }
    
        counter++;
    
    } 
    while (counter < 21);

    return 0;
    
}
/*Programn to find odd or even numbers using an function
Darren Grants 08/02/22
*/
#include <stdio.h>

//define SIZE 10

int Check(int*);

int main()
{
    int user_num = 0;

    printf("\nPlease input a number to check if its odd or even\n");
    scanf("%d",&user_num);

    Check(&user_num);

    printf("your number is %d, 1 is even, 0 is odd", user_num);

    return 0;

}

int Check(int *user_num)
{
    //int even=1;
    //int odd=0;
    
    if (*user_num%2 == 0)
    {
        //printf("This number is even");
        *user_num = 1;
        return *user_num;
    }
    else
    {
        //printf("This number is odd");
        *user_num = 0;
        return *user_num;
    }
}


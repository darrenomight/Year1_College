/*Programn to find odd or even numbers using an function
Darren Grants 08/02/22
*/
#include <stdio.h>

#define SIZE 3

int highest_finder(int*, int*, int*);

int main()
{
    int user_num1 = 0;
    int user_num2 = 0;
    int user_num3 = 0;
    int highest = 0;

    printf("\nPlease input %d number to find the largest number\n",SIZE);
    scanf("%d",&user_num1);
    scanf("%d",&user_num2);
    scanf("%d",&user_num3);


    highest = highest_finder(&user_num1, &user_num2, &user_num3);
    

    printf("Your largest number is %d", highest);

    return 0;

}

int highest_finder(int *user_num1,int *user_num2, int *user_num3)
{
    int highest = 0;

    if (*user_num1 > *user_num2 && *user_num1 > *user_num3)
    {
        highest = *user_num1;
    }
    else if (*user_num2 > *user_num1 && *user_num2 > *user_num3)
    {
        highest = *user_num2;
    }
    else
    {
         highest = *user_num3;
    }
    
    return highest;
}




/*Programn to find odd or even numbers using an function
Darren Grants 08/02/22 Nikola
*/
#include <stdio.h>

#define SIZE 3

int average_finder(int*, int*, int*);

int main()
{
    int user_num1 = 0;
    int user_num2 = 0;
    int user_num3 = 0;
    int num_average = 0;

    printf("\nPlease input %d number to find their average\n",SIZE);
    scanf("%d",&user_num1);
    scanf("%d",&user_num2);
    scanf("%d",&user_num3);


    num_average = average_finder(&user_num1, &user_num2, &user_num3);
    

    printf("your numbers average is %d", num_average);

    return 0;

}

int average_finder(int *user_num1,int *user_num2, int *user_num3)
{
    int num_average = 0;

    num_average = (*user_num1 + *user_num2 + *user_num3)/SIZE;

    return num_average;
}




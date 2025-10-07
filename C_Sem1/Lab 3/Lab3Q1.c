//Program to get 3 digits from a user, Darren Grants 19/10/21
#include <stdio.h>

int main (void)
{
    //Data collection
    int user_num1;
    int user_num2;
    int user_num3;

    user_num1 = 0;
    user_num2 = 0;
    user_num3 = 0;
    
    //the actual number collecting/storage//

    printf("\nPlease input any 3 postive number\n");

    scanf("%d", &user_num1);
    scanf("%d", &user_num2);
    scanf("%d", &user_num3);

    while (getchar() != '\n');

    printf("\nYour numbers are \n%d\n %d\n %d\n", user_num1, user_num2, user_num3);

    return 0;
}
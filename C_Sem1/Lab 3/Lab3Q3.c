//Program to collect floats and display in a certin amounts of decimial places
#include <stdio.h>

int main(void)
{
    float user_num1 = 0.0;
    float user_num2 = 0.0;
    float user_num3 = 0.0;

    printf("Please enter any 3 digits with decimal places with at 5 decimals points from the whole number\n");

    scanf("%f",&user_num1);
    scanf("%f",&user_num2);
    scanf("%f",&user_num3);

    //the .4/.3 are used to show to that decimal point
    printf("Your numbers are \n %.4f\n %.3f\n and %.0f",user_num1,user_num2, user_num3);
    return (0);
}
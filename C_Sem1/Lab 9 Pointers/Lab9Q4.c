#include <stdio.h>

int main()
{
    int num1 = 0;
    int num2 = 0;
    int sum = 0;

    int *ptr1;
    int *ptr2;
    int *ptr3;

    ptr1 = &num1;
    ptr2 = &num2;
    ptr3 = &sum;

    printf("\ninput your 2 numbers\n");
    
    scanf("%d",&num1);
    scanf("%d",&num2);

    sum = *ptr1 + *ptr2;

    printf("\nthe sum is %d",*ptr3);

    return 0;
}
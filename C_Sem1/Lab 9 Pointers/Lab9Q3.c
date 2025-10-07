#include <stdio.h>

int main()
{
    float input1 = 0;
    float input2 = 0;

    //intialise the pointers
    float *ptr1;
    float *ptr2;

    //make them point at the inputs
    ptr1 = &input1;
    ptr2 = &input2;

    printf("\nInput your numbers\n");
    scanf("%f",&input1);
    scanf("%f",&input2);

    printf("\naddress of input1 %p and\n adress input2 %p\n",&input1,&input2);
    printf("\naddress of pointers %p and\n adress input2 %p\n",&ptr1,&ptr2);
    printf("\ncontent of input1: %p content of input2: %p",ptr1,ptr2);
    printf("\ncontent of ptr1: %f and ptr2: %f",*ptr1,*ptr2);

    return 0;
    
}
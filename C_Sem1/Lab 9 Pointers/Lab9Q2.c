#include <stdio.h>
int main(void)
{
    int numb1;
    char char1;

    int *ptrl1;
    char *ptrl2;
    int *ptrl3;

    numb1 = 1;
    char1 ='a';

    //make pointer 1 point at number1
    ptrl1 = &numb1;

    //make pointer 2 point at char1
    ptrl2 = &char1;
    ptrl3 = &char1;

    printf("\nHere is the content of num1: %d and char1: %c and here are their memory adresses num1: %p and char1: %p",numb1 ,char1,&numb1,&char1);
    printf("\nHere is the content of Pointer 1: %p and pointer 2: %p",ptrl1,ptrl2);
    printf("\nHere is the derefrence content %d and %c",*ptrl1,*ptrl2);
    printf("\nPointer 3 %p and %c",&ptrl3,*ptrl3);

    return 0;

}

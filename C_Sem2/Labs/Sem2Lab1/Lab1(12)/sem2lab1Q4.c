/*program to print a character X amount of times*/
#include <stdio.h>

//#define SIZE 10

void Sum(int ,int,int);
void Avg(int);

int main(void)
{
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    
    printf("\nProgramn Starting to find your 3 Intergers order!!!\n\n");
    
    scanf("%d",&num1);
   // while(getchar() != '\n');
    scanf("%d",&num2);
    scanf("%d",&num3);
    
    Sum(num1, num2, num3);

    return 0;
}

void Sum(int num1, int num2, int num3)
{
    int sum=0;

    sum = num1+num2+num3;

    printf("sum = %d",sum);

    Avg(sum);

}

void Avg(int sum)
{
    float average = 0;

    average = sum/3;

    printf("\tAvg=%.2f",average);
}

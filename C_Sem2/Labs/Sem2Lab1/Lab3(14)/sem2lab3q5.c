/*Programn to find the largest number in an area using an function */
#include <stdio.h>

#define SIZE 5

int odd_even(int[]);

int main()
{
    int numbers[SIZE];
    int i;
    int even = 0;

    printf("please input your %d numbers please\n",SIZE);

    for ( i = 0; i < SIZE; i++)
    {
        scanf("%d",&numbers[i]);
    }
    
    even = odd_even(numbers);

    printf("\nYou had %d even numbers",even);

    return 0;

}

//to find biggest number in array
int odd_even(int numbers[])
{
    int odd = 0;
    int even = 0;
    int i;

    for ( i = 0; i < SIZE; i++)
    {
        //printf("%d",numbers[i]);

        if (numbers[i]%2 == 0)
        {
            printf("\n\n%d even\n",numbers[i]);
            even++;
        }
        else
        {
            odd++;
            printf("\n\n%d is odd\n",numbers[i]);
        }
               
    }

   //printf("\n%d even %d odd\n",even ,odd);
    
    return even;
}


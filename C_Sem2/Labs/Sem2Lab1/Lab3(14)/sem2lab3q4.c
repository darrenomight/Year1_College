/*Programn to find the largest number in an area using an function */
#include <stdio.h>

#define SIZE 5

int sorter_array(int[]);

int main()
{
    int numbers[SIZE];
    int i;
    int largest;

    printf("input your %d numbers please\n",SIZE);

    for ( i = 0; i < SIZE; i++)
    {
        scanf("%d",&numbers[i]);
    }
    
    largest = sorter_array(numbers);

    printf("The largest number in your array is %d",largest);

    return 0;

}

//to find biggest number in array
int sorter_array(int numbers[])
{
    int largest = 0;
    int i;

    for ( i = 0; i < SIZE; i++)
    {
        if (largest < numbers[i])
        {
            largest = numbers[i];
        }
        
    }
    
    return largest;
}


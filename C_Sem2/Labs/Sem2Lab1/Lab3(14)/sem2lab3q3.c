/*Programn to find the largest number in an area using an function */
#include <stdio.h>

#define SIZE 5

float average_array(int[]);

int main()
{
    int numbers[SIZE];
    int i;
    float average;

    printf("Hello please Input your %d numbers that you wish to get the average of\n",SIZE);

    for ( i = 0; i < SIZE; i++)
    {
        scanf("%d",&numbers[i]);
    }
    
    average = average_array(numbers);

    printf("Your average number in your array is %.2f",average);

    return 0;

}

//to find average in array
float average_array(int numbers[])
{
    float total = 0;
    int i;

    for ( i = 0; i < SIZE; i++)
    {
        total = total + (float)numbers[i];
    }

    //average found after numbers added together
    total = (float)total/(float)SIZE;
    
    return total;
}


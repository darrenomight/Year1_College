/*
Program that uses an array and calculates the average age of a set of 
people
*/
#include <stdio.h>
int main()
{
    int ages[5];
    int sum = 0;
    float average = 0;
    int i;

    printf("Enter the ages of 5 people\n");
   
    for (i = 0; i < 5; i++)
    {
        // enter an age
        scanf("%d", &ages[i]);
        // add the current value in sum to the age entered, i.e., keep a running sum total of ages
        sum = sum + ages[i];
    }
    // end for
    // cast the variable sum to be a float just for this line of code
    average = (float)sum / 5;
    
    printf("The average age is %.1f", average);
    
    return 0;
} // end main
// C program for insertion sort
#include <math.h>
#include <stdio.h>

#define SIZE 6

void print_array(int*);
void sort_array(int*);


int main()
{
    int user_nums[SIZE];

    printf("Input numbers pls\n");

    for (int i = 0; i < SIZE; i++)
    {
        scanf("%d",(user_nums + i));
    }
    
    sort_array(user_nums);
    print_array(user_nums);
 
    return 0;
}

// A utility function to print an array of size n
void print_array(int *user_nums)
{
    int i;
    for (i = 0; i < SIZE; i++)
    {
        printf("%d ", user_nums[i]);
    } //end for
    printf("\n");
} //end function 


/* Function to sort an array using insertion sort*/
void sort_array(int *user_nums)
{
    int i; 
    int Lowest_value;
    int j;

    for (i = 1; i < SIZE; i++) 
    {
        Lowest_value = *(user_nums + i);
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && *(user_nums + j) > Lowest_value) 
        {
            *(user_nums + j + 1) = *(user_nums + j);
            j = j - 1;
            print_array(user_nums);
        }
        *(user_nums + j + 1) = Lowest_value;
    }
}


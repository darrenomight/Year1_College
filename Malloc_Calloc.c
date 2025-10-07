/*
Dynamic Memory Allocation (DMA)
This program uses calloc() to dynamically allocate a block of memory,
enter data into the memory block and display it. The memory block is
freed (released) at the end when the memory block is no longer
required.
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr;
    int numbers = 0;
    // int no_bytes = 0;
    int i;

    // Part 1
    // How many numbers, i.e., data items do you wish to enter
    printf("\nHow many numbers will you enter?\n");
    scanf("%d", &numbers);

    // Part 2 NOT NEEDED
    // Calculate the number of bytes required to store the set of numbers in memory
    // no_bytes = numbers * sizeof(int);

    // Part 3
    // Allocate the block of memory required
    ptr = calloc(numbers, sizeof(int));

    // Part 4
    // Check if malloc was successful, i.e., check if the memory was allocated successfully
    if (ptr == NULL)
    {
        printf("\nFailed to allocate memory\n");
    }    // end if
    else // memory allocated successfully
    {

        // Part 5
        // memory allocated successfully - go and use it
        printf("\nMemory allocated successfully\n");
        printf("\nEnter the set of %d numbers\n", numbers);
        // Enter data items into the allocated memory block
        for (i = 0; i < numbers; i++)
        {
            scanf("%d", &*(ptr + i));
        } // end for

        printf("\nYou entered:\n");
        // Display the data items entered into the allocated memory block
        for (i = 0; i < numbers; i++)
        {
            printf("%d\n", *(ptr + i));
        } // end for

        // Part 6
        // Free the allocated memory block once finished using it
        free(ptr);
    } // end else
    return 0;
} // end main()
/*
Program to show how to initialise an array
Author:
Date:
*/
#include <stdio.h>
#define NO_OF_MONTHS 12 

int main()
{
    int days[NO_OF_MONTHS] = {31,28,31,30,31,30,31,31,30,31,30,31};
    //int days[NO_OF_MONTHS];
    int month = 0;
    int i;
    for (i = 0;i < NO_OF_MONTHS; i++)
    {
        printf( "%d ", days[i]);
    }
    printf("\n\nPlease enter a month,e.g., 1 = Jan, 2 = Feb, etc.,\n");
    // user enters a number corresponding to the month they wish to view the no.of days
    do
    {
        scanf("%d", &month);
        // check if valid month entered, i.e., 1 - 12 inclusive
        if (month < 1 || month > 12)
        {
            printf("\nInvalid month entered\n");
        }
        // end if
    }
    // end do
    while (month < 1 ||month >12);
    printf("\n\nThe number of days in month %d are % d ", month, days [month - 1]);
    
    return 0;
}
// end main()
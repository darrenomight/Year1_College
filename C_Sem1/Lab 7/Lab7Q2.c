#include <stdio.h>

#define X 3
#define Y 2

int main()
{
    int numb[X][Y];
    int i;
    int j;
    int highest = 0;
    int lowest = 0;
    float avg = 0;
    int total = 0;

    printf("Please input 6 Numbers\n");

    for (i = 0; i < X; i++)
    {
        for (j = 0; j < Y; j++)
        {
            scanf("%d", &numb[i][j]);
        }
    }

    lowest = numb[0][0];
    for (i = 0; i < X; i++)
    {
        for (j = 0; j < Y; j++)
        {
            total = total + numb[i][j];
            printf("\nX %d,Y %d contains %d", i, j, numb[i][j]);
        }
    }


    for (i = 0; i < X; i++)
    {
        for (j = 0; j < Y; j++)
        {
            numb[i][j];
        }
    }

    for (i = 0; i < X; i++)
    {
        for (j = 0; j < Y; j++)
        {
            if (highest < numb[i][j])
            {
                highest = numb[i][j];
            }
            // end if
            // find the lowest number in the array
            if (lowest > numb[i][j])
            {
                lowest = numb[i][j];
            }
        }    
    }

    // end for
    // Display the highest and lowest number in the array
    printf("\n\nThe highest number is %d ",highest);
    printf("\n\nThe lowest number is %d ",lowest);
    // cast the variable sum to be a float just for this line of code
    avg = (float)total/(X * Y);
    printf("\n\nThe average values are %.1f ",avg);

    return 0;
}
// end main
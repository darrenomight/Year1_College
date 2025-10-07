#include <stdio.h>

#define ROW 3
#define COL 4

int main(void)
{
    int array1[3][4]={1,2,3,
                      4,5,6,
                      7,8,9,
                      10,11,12};
    
    int array2[3][4]={1,2,3,
                      4,5,6,
                      7,8,9,
                      10,11,12};
    int array3[3][4];
    
    int i;
    int j;

    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            array3[i][j] = array1[i][j] * array2[i][j];
        }
        
    }
    
    for ( i = 0; i < ROW; i++)
    {
        for ( j = 0; j < COL; j++)
        {
            printf("\n%d",array3[i][j]);
        }
        
    }
    
    return 0;
}

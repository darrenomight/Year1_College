#include <stdio.h>

#define NUM 10
#define MIN 0
#define MAX 10

int main(void)
{
    printf("Hello");
    int a[NUM]; 
    int i = 0;

    for (i = MIN; i < MAX; i++)
    {
        a[i] = 9 - i;
    }//for end
    
    for (i = MIN; i < MAX; i++)
    {
        a[i] = a[ a[i] ];
        printf("\n The numbers are %d",a[i]);
    }//for end
    return 0;
}//end maij
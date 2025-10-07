#include <stdio.h>

#define TEMP 3

int main(void)
{
    float fahrenheit = TEMP;
    float celsius = 0;

    int i;

    printf("Enter %d Temperatures in Farheneit\n",TEMP);

    for ( i = 0; i < TEMP; i++)
    {
        scanf("%f"&fahrenheit[i]);
    }
    
    printf("converting into Celsuis")

    return 0;
}

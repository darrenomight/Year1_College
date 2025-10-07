/*programn to use 2 functions 1 to calculate the area of a square and another the area of a circle
Darren Grants 15/02/22
*/

#include <stdio.h>

//#define PI 3.14

int square(int);
float circle(int);

int main()
{
    int square_length = 0;
    int circle_radius = 0;
    int square_area= 0;
    float circle_area= 0;


    printf("Input a whole interger for a circles radius\n");
    scanf("%d",&circle_radius);

    printf("Input a whole interger for a squares length\n");
    scanf("%d",&square_length);

    square_area = square(square_length);
    circle_area = circle(circle_radius);

    printf("This is the square area %d\n",square_area);
    printf("This is the circles area %f\n",circle_area);

    return 0;

}

//function Squares to calculate the area of a square with the value set by the user 
int square(int square_length)
{
    int square_area = 0;
    
    square_area = (square_length * square_length);

    return square_area;
}

float circle(int circle_radius)
{
    float circle_area = 0;
    float pi = 3.14;
    float circle_squared = 0;

    circle_squared = (circle_radius * circle_radius);
    circle_area = ((float)circle_squared * pi);

    return circle_area;
}
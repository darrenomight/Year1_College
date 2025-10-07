/* Program to show number generator game. Player inputs their number/guess 5 times showing the differences and same numbers when either the player 
has the same number as the system or different and lastly to show how many times the player has the same or different number.
Darren Grants, 09/11/21
*/
#include <stdio.h> 
#include <stdlib.h> // this header file is required for the rand() function 
#include <time.h> // used in srand() for seeding purposes 
 
int main(void) 
{ 
    int num = 0; 
    int i = 0;
    int usernum = 0;
    int Same = 0;
    int Different = 0;
 

    //i for amount of games while i is less than 5 play the game increase i every time
    for (i=0; i < 5; i++)
    {   
        //instructions for game 
        printf("\nPlease select a number between 1-10 to play\n");
        printf("\nGenerating a random number between 1-10 \n"); 
        scanf("%i",&usernum);

        //to catch inputs outside the range
        while (usernum <= 0 || usernum > 10)
        {
            printf("\nInvalid Numbers, input a number within the range\n");
            scanf("%d",&usernum);
        }
        
        // seed the random number generator with a range 0 – large number 
        srand(time(NULL)); 
     
        // num is assigned a random number between 1 – 10  
        num = (rand() % 10) + 1; 
     
        // display the random number generated 
        //display the user number
        printf("\nSystem number is %d", num); 
        printf("\nYou Number is %d",usernum);
    
        //if the numbers are the same add a point to same numbers counter
        if (usernum == num) 
        
        {
            printf("\nThey are the same");
            Same++;
        }
        
        //if not the same numbers add a point to Different counter
        else 
        {
            printf("\nThey are not the same");
            Different++;
        }

    }
    //Display the amount of same and different results
    printf("\nYou got %d Same and %d Different",Same,Different);
     
    return 0; 
 
} // end main
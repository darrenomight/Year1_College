/* Program to show number generator 5 times show differences or same numbers and lastly show how many times different at end 
Darren Grants, 09/11/21
*/
#include <stdio.h> 
#include <stdlib.h> // this header file is required for the rand() function 
#include <time.h> // used in srand() for seeding purposes 
 
int main() 
{ 
    int num = 0; 
    int usernum = 0;
    int different = 0;
    int same = 0;
    int attempts = 0;

    //for loop to do it 5 times
    for ( attempts = 0; attempts < 5; attempts++)
    {
         printf("\nGenerating a random number between 1 – 10 "); 
         printf("\nPlease input your own number better 1-10\n");

         scanf("%d",&usernum);
 
          // seed the random number generator with a range 0 – large number 
         srand(time(NULL)); 
     
         // num is assigned a random number between 1 – 10  
         num = (rand() % 10) + 1; 
     
         // display the random number generated 
         printf("\nSystem number is %d ", num); 
         printf("\nYour number is %d\n",usernum);

        if (num == usernum)  //if number same //if theres a break it breaks the loop
        {
            printf("Same Numbers\n");
            same++;
        }
    
        while (num =! usernum);
        {
         printf(" Different numbers\n");
         different++;
        } //end while
    }

    printf("Your numbers were different %d times, your numbers were the same %d times",different,same);

    return 0; 
 
} // end main
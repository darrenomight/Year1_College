/*
This programme is to be a maths quiz made with c, it has to have 4 features incoroparted in its design. It has to be menu based.
The amount of questions the user wishes to play (Max 5). Start and play the game. 3 Display the number of questions that were answered 1: correctly and 2: 
incorrectly for this round. Finally an option to leave the programme.
Darren Grants 19/11/21
*/

#include <stdio.h>// Main library
#include <stdlib.h> // This header file is required for the rand() function 
#include <time.h> // Used in srand() for seeding purposes 

int main(void)
{   
    int p_ans;
    int i;
    int correct = 0;
    int incorrect = 0;
    int amo_Q = 0;
    int num = 0;
    int num1 = 0;
    int system_ans;
    
    char option;
    char catch;
    

    // Seed the random number generator with a range 0 – large number 
    srand(time(NULL)); 
    
    printf("\nPlease select an option from a to c and please press d when you wish to end the game\n");

    while (option != 'd' && option != 'D')
    {
        printf("\nA: Choose the amount of questions!\t B: Play the game!\t C: See your correct and wrong answers!\t D: End the Game!\n");

        while (1)
        {
            option = getchar();
            if (option != (int)'\n')// If option not= to n. break it/ checks all inputs before /n aka Enter key 
            {
                break;
            } 
        }// While end
        

        switch (option)// The switch operations allows us to choose which of the 4 required features the user can interact with and using the least amount of reasources
        {

        case 'a':
        case 'A':// Select your questions from a min of 1 and a max of 5
        {
            amo_Q = 0;
            while (amo_Q <= 0 || amo_Q > 5)
            {
                while (1)
            {
                option = getchar();
                if ((int)option != (int)'\n')// If option not= to n. break it/ checks all inputs before /n aka Enter key 
                {
                    break;
                } 
            }// While end
                printf("Please select the amount of questions you would like asked from 1 to 5\n");
                while (1)
                {
                    scanf("%d",&amo_Q);
                    if (getchar() == (int)'\n')// If option not= to n. break it/ checks all inputs before /n aka Enter key 
                    {
                        break;
                    } 
                }// While end

                if (amo_Q <= 0 || amo_Q > 5)
                {
                    printf("\nPlease enter a valid number witin the range\n");
                }// If end
                else
                {
                    printf("\nYou will have %d questions this quiz\n", amo_Q);
                }// Else end
            }// While end
            
            break;
        }// Case a end

        case 'b':
        case 'B':// Play the game 
        {
            while (1)
        {
            option = getchar();
            if ((int)option != (int)'\n')// If option not= to n. break it/ checks all inputs before /n aka Enter key 
            {
                break;
            } 
        }// While end
            correct = 0;
            incorrect = 0;
            // The correct and incorrect are reset to 0 every time a new game starts
            if (amo_Q == 0)
            {
                printf("\nYou must selcet the amount of questions you would like to play");
            }// If end
            else
            {
                printf("\n You have %d questions waiting for you now\n", amo_Q);
                for (i = 0; i < amo_Q; i++)
                {
                    printf("\nHere is your question\n");
     
                    // Num is assigned a random number between 1 – 100
                    num = (rand() % 100) + 1;
                    num1 = (rand() % 100) + 1;

                    // Display the 2 random number generated which creates the questions
                    printf("%d + %d = ?", num,num1);
                    
                    // The system that checks the answer
                    system_ans = num + num1;
                    
                    // Player input here
                    printf("\nWhat is the answer?\n");
                    scanf("%d",&p_ans);

                    // This if checks if user answer is correct if not it marks it down as wrong
                    if (p_ans == system_ans)
                    {
                        correct++;
                        printf("\nGood Job \n");
                    }// End If
                    else
                    {
                        incorrect++;
                        // When incorrect show the right answer next to the players input
                        printf("That was wrong, your answer was %d the right answer was %d \n",p_ans,system_ans);
                        printf("Better luck next time\n");
                    }// End else
                
                }// End for
                printf("\nThanks for playing, come back soon :)\n");  
            }
            break;
        }// End b case

        case 'c':
        case 'C':// To count correct and incorrect answers in the game 
        {
            while (1)
        {
            option = getchar();
            if ((int)option != (int)'\n')// If option not= to n. break it/ checks all inputs before /n aka Enter key 
            {
                break;
            } 
        }// While end
            if (correct != 0 || incorrect != 0)
            {
                printf("\n You have answered %d correct and %d incorrectly for this round", correct, incorrect);
            } // End if
            else
            {
                 printf("You must play the quiz to see your results");
            } // End Else
            break;
        }// Case c end

        case 'd':
        case 'D':// End the Game
        {
            printf("\nBye! Bye!");
            break;
        }// Case d ends game and leads to system end
        
        default: // Invalid option catcher (too good of a catcher sometimes)
            printf("\nInvalid option, please input what you're asked for\n");
            break;
        }// End default

    }// End while
    return 0;
}// End main
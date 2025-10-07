/* 
This Programme is a lotto game built modularised and has to have each main taks done in its own function and we have to pass our Array with Pointer Notation.Each major task described below:
A: The user can enter any 6 digits between 1-42 from their keyboard, Perform the nessary checks
B: Display the contents of the Users array aka their numbers the just inputed
C: Sort the array with an algorithm of choice, in increasing order (Insertion was my choice)
D: Compare the users lotto numbers to the winning numbers (this can be done with unsorted or sorted user numbers)Depending on the users amount of Matching numbers Print a prize 
E: Display the frequency of the numbers entered by the user without exiting the programn
F: Simply exit the programn and ask the user are they sure they wish to leave

/Extra 
Keep the programn running after functions calls 
option 2,3,4,5,6 cant be accesed until option 1 is done, display approiate errors 

Darren Grants
Start date:02/03/2022 End date://
*/

//Libraries used
#include <stdio.h>

//Defines
#define SIZE 6

//Structures

//Function Signatures
void input_values(int*); //1
void display_values(int*); //2
void sort_array(int*); //3
void compare_lotto_numbs(int*); //4
void display_frequency(int*); //5
int exit_programme(int); //6

//Main function to display and interact with the menu
int main(void)
{
    int user_choice; //main changable variable to go through switch cases
    int exit_choice; //main variable to change when planning to exit the game
    int user_nums[SIZE]; //the users lotto numbers
    int user_nums_inputed[SIZE];


    printf("\nWelcome to the D.G.Lotto systems, please select 1 of the 6 options to continue!!!, We highly recommend to begin with option 1\n");
    
    while (exit_choice != 1 ) //while the user dosent press 2 they will stay in the loop
    {
        printf("\n\nPlease select an option: 1-6\n");
        printf("_____________________________________________________________________________________\n");
        printf("\nOption 1: Select your Lotto Numbers\n");
        printf("Option 2: View your selected Lotto Numbers\n");
        printf("Option 3: Sort your array\n");
        printf("Option 4: Compare your Lotto Ticket To the winning numbers\n");
        printf("Option 5: See how often you choose certain numbers\n");
        printf("Option 6: Exit D.G.Lotto systems\n");
        printf("\n_____________________________________________________________________________________\n");
        
        scanf("%d",&user_choice); //Lets the user input their choice of what they want to do
        
        
        switch (user_choice) //Allows us to make a menu like selection screen
        {
        case 1:
        {
            printf("You will be shortly asked to input your lotto tickets\n");
            
            //call function to input lotto numbers
            input_values(user_nums);

            printf("\nYou have inputed your lotto numbers GG\n");

            break;
        }

        case 2:
        {
            printf("Option 2 Your Lotto Numbers");

            //function called to display your lotto numbers
            display_values(user_nums); 

            break;
        }

        case 3:
        {
            printf("Your Array will be sorted in ascending order");

            break;
        }

        case 4:
        {
            printf("Dima4");

            break;
        }

        case 5:
        {
            printf("Dima5");

            break;
        }

        case 6:
        {
            //printf("\nAre you sure you want to Leave\nPress 1 to Exit\t Press 2 to stay\n");
            exit_choice = 0;
            printf("debug exit value %d",exit_choice);
            
            exit_programme(exit_choice);

            printf("debug exit value after loop %d",exit_choice);

            if (exit_choice == 1)
            {
                return 0;
            }
            
            break;

        }

        default:
        {
            printf("\nInvalid option, please input what you're asked for\n");
            break;
        }
        } //End the switch case
    } //End while
    return 0;
} //End Main

//Function to read in our array 
void input_values(int *user_lotto_nums)
{
    int i;
    
    printf("Please input your lotto numbers between the values of 1 to 42\n ");

    //for loop to read in the user lotto numbers into an array
    for (i = 0; i < SIZE; i++)
    {
        scanf("%d",(user_lotto_nums + i));
        
        //error checking to prevent Numbers higher than 42 or lower than 1
        while (*(user_lotto_nums + i ) <= 0 || *(user_lotto_nums + i ) > 42)
        {
        
            if (*(user_lotto_nums + i) <= 0 || *(user_lotto_nums + i) > 42)
            {
                printf("\nPlease input numbers only between 1 and 42\n");
                scanf("%d",(user_lotto_nums + i));
            } //end if
            else
            {
                printf("\nSuccessful Input of your Lotto Numbers\n");
            } //end else
        
        } //End While
    } 
    /*
    while (*user_lotto_nums <= 0 || *user_lotto_nums > 42)
    {
        if (*user_lotto_nums <= 0 || *user_lotto_nums > 42)
        {
            printf("Please input numbers only between 1 and 42");
        }
        else
        {
            printf("Successful Input of Lotto Numbers");
        }
        
    }
    */

}

//Function to simply display the users Lotto Numbers
void display_values(int *Display_numbers)
{
    int i;
    printf("\nYour lotto numbers are as following\n");

    for (i = 0; i < SIZE; i++)
    {
        printf("%d,",*(Display_numbers + i));
    }
    
}

















//function to Leave programmn with a confirmation screen
int exit_programme(int leave)
{
    int false = 0;
    int true = 1;
    printf("\nAre you sure you want to Leave?\nPress 1 to Exit\t Press 2 to stay\n");
            
    scanf("%d",&leave);

    printf("\n%d\n",leave);

        if (leave == 1)
        {
            printf("\nBye Bye, Vist again sometimes!!");
            return true;
        } //end if
        else
        {
            printf("\nGlad you stayed\n");
            return false;
        } // end else
} //end exit function

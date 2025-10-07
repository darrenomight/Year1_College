/* 
This Programme is a lotto game built modularised and has to have each main taks done in its own function and we have to pass our Array with Pointer Notation.Each major task described below:
A: The user can enter any 6 digits between 1-42 from their keyboard, Perform the nessary checks
B: Display the contents of the Users array aka their numbers the just inputed
C: Sort the array with an algorithm of choice, in increasing order (Insertion was my choice)
D: Compare the users lotto numbers to the winning numbers (this can be done with unsorted or sorted user numbers)Depending on the users amount of Matching numbers Print a prize 
E: Display the frequency of the numbers entered by the user without exiting the programn
F: Simply exit the programn and ask the user are they sure they wish to leave

/Extra 
Keep the programn running after functions calls / options picked
option 2,3,4,5 cant be accesed until option 1 is done, display approiate errors 

Darren Grants
Start date:02/03/2022 End date:16/03/2022
*/

//Libraries used
#include <stdio.h>

//defines
#define SIZE 6
#define MAX 43
#define SMALLEST 1
#define LARGEST 42
//Structures

//Function Signatures
void input_values(int*); //option1
void display_values(int*); //option2
void sort_array(int*); //option3
void compare_lotto_numbs(int*); //option4
void display_frequency(int*, int*); //option5
int exit_programme(int); //option6
int scan_check(); //error check for main
void update_freq(int*, int*);// option5 freq

//the main
int main(void)
{
    int frequency_array[MAX] = {0}; //hold inputed numbers starts full of 0s
    int user_choice; //main changable variable to go through switch cases
    int exit_choice = 0; //main variable to change when planning to exit the game
    int user_nums[SIZE];
    int lock = 0; //used to control the users options


    printf("\nWelcome to the D.G.Lotto systems, please select 1 of the 6 options to continue, we highly recommens starting with option 1!!!\n");
    
    //this while loop allows us to stay in the switch cases until user inputs option 6 and selects to leave
    while (exit_choice != 1 )
    {
        //The menu
        printf("\n\nPlease select an option: 1-6\n");
        printf("_____________________________________________________________________________________\n");
        printf("\nOption 1: Select your Lotto Numbers\n");
        printf("Option 2: View your selected Lotto Numbers\n");
        printf("Option 3: Sort your array\n");
        printf("Option 4: Compare your Lotto Ticket To the Winning numbers\n");
        printf("Option 5: See your freqeunt Lotto Numbers\n");
        printf("Option 6: Exit D.G.Lotto systems\n");
        printf("\n_____________________________________________________________________________________\n");
        
        
        // error checking function for the menu
        user_choice = scan_check();

        switch (user_choice)
        {
        case 1:
        {
            printf("You will be shortly asked to input your lotto tickets\n");
            
            //fucntion call to allow users to input their selected numbers should be the only option avaible in the beginning
            input_values(user_nums);

            lock++;

            printf("\nYou have inputed your lotto numbers GG\n");

            //function call to hold frequency
            update_freq(user_nums, frequency_array);

            break;
        } //end case 1

        case 2:
        {
            printf("Option 2 Your Lotto Numbers\n");
            
            if (lock == 0)
            {
                printf("\n*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!\n");
                printf("\nPlease select your lotto numbers before contining ahead\n");
                printf("\n*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!\n");
            }//end if
            else
            {
                //function call to display the users inputed numbers
                display_values(user_nums); 

            } //end else
            break;

        } //end case 2

        case 3:
        {
            printf("We will sort your lotto numbers shortly please stand by!!\n");

            if (lock == 0)
            {
                printf("\n*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!\n");
                printf("\nPlease select your lotto numbers before contining ahead\n");
                printf("\n*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!\n");
            }//end if
            else
            {
                //call function sort_array to sort the users inputted 
                sort_array(user_nums);
            } //end else
            
            
            break;
        } //end case 3

        case 4:
        {
            printf("We are now comparing your lotto ticket to our winning numbers, Are you todays big winner ???\n");
            
            if (lock == 0)
            {
                printf("\n*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!\n");
                printf("\nPlease select your lotto numbers before contining ahead\n");
                printf("\n*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!\n");
            }//end if
            else
            {
                //function call to compare the users tickets to the systems winning numbers if a set number of the numbers win print certain rewards
                compare_lotto_numbs(user_nums);
            } //end else

            break;
        }//end case 4

        case 5:
        {
            if (lock == 0)
            {
                printf("\n*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!\n");
                printf("\nPlease select your lotto numbers before contining ahead\n");
                printf("\n*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!\n");
            }//end if
            else
            {
                printf("\n We are now checking your numbers number frequency which is your lucky number?\n");

                display_frequency(user_nums, frequency_array);
                
            } //end else

            break;
        } //end case 5

        case 6:
        {
            //call function exit_programme to check if user wishes to stay, Returns a 1 if user wishes to leave anyting else the programme remains
            exit_choice = exit_programme(exit_choice);
            
            if (exit_choice == 1)
            {
                return 0;
            } //end if
            
            printf("resuming lotto system :)");  
            printf("\n_____________________________________________________________________________________\n");
            break;

        } //end case 6

        default:
        {
            printf("\nInvalid option, please input what you're asked for\n");
            break;
        } //end default
        } //End the switch case
    
    } //End while
    return 0;
} //end main

//function to allow the user to input their lotto numbers 
void input_values(int *user_nums)
{
    int i;
    int j;
    

    printf("Please input your lotto numbers between the values of 1 to 42\n");

    //for loop, to allow the user to input their numbers into an array
    for (int i = 0; i < SIZE; i++)
    {
        scanf("%d",(user_nums + i));
        while (getchar()!='\n'); //to catch characters
        
        //while to catch inputs out of range (1-42)
        while (*(user_nums + i ) < SMALLEST || *(user_nums + i ) > LARGEST)
        {
            //if the actions to do when input is out of range
            //if (*(user_nums + i) < SMALLEST || *(user_nums + i) > LARGEST)
            {
                printf("\nPlease input numbers only between 1 and 42\n");
                scanf("%d",(user_nums + i));
                while (getchar()!='\n'); //to catch characters
            } //end if
            //else
            {
                //printf("\nSuccessful Input of Numbers\n");
            } //end else
        
        } //end while 
        
        //for loop to compare inputted numbers to themselves to prevent duplicates 
        for (j = (i-1); j >= 0; j--)
        {
            if (*(user_nums + i ) == *(user_nums + j ))
            {
                //action to do if numbers the same
                while (*(user_nums + i ) == *(user_nums + j ))
                {
                    printf("\nPlease input unique numbers\n");
                    scanf("%d",&*(user_nums + i));
                    while (getchar()!='\n'); //to catch characters
                }//end while
            }// end if
        }//end for error
    }//end for
} //end function

//function to display the users numbers when option 2 is pressed
void display_values(int *user_num)
{
    int i;


    printf("\nYour lotto numbers are as following\n");

    //for loop to simple print out users entered numbers
    for (i = 0; i < SIZE; i++)
    {
        printf("%d\t",*(user_num + i));
    } // end for
    
}

//Function to sort an array using a insertion sort algorithm when option 3 is pressed
void sort_array(int *user_nums)
{
    int i; 
    int lowest_value;
    int j;


    //for loop to sort the array nubers 
    for (i = 1; i < SIZE; i++) 
    {
        //set the 2nd item to smallest 
        lowest_value = *(user_nums + i);
        j = i - 1;
 
        //Move elements of my array, that are larger than my lowest number in lotto ticket, to one position ahead of their current position 
        while (j >= 0 && *(user_nums + j) > lowest_value) 
        {
            *(user_nums + j + 1) = *(user_nums + j);
            j = j - 1;
        } //end while
        *(user_nums + j + 1) = lowest_value;
    }// end for
}//end function

//function 4 to check user numbers to winning numbers
void compare_lotto_numbs(int *players_nums)
{
    int winning_numbers[SIZE] = {1,3,5,7,9,11};
    int matches = 0;
    int i;
    int j;
    
    
    //to begin comparsion between winning tickets and users tickets,take the users 1st digit
    for (i = 0; i < SIZE; i++)
    {
        //checks the users 1st digit agannist all winning numbers, till all numbers checked
        for ( j = 0; j < SIZE; j++)
        {
            //if a number matches add a value to mathces, 
            if (*(players_nums + i ) == winning_numbers[j])
            {
                matches++;
            } //end if
        } //end nested for
    
    }  //end for

    //depending on the amount of matches dictates which prize the user won
    switch (matches)
        {
        case 3:
        {
            printf("\nYou have won a Cinema Pass to the VUE in Liffey Valley !!!\n");
            break;
        }//end case 3

        case 4:
        {
            printf("\nYou have won a weekend away to Wicklow !!!\n");
            break;
        } //end case 4
            
        case 5:
        {
            printf("\nYou have won a brand new luxury Car, insurance is not included !!!\n");
            break;
        } //end case 5
        
        case 6:
        {
            printf("\nYou have won THE JACKPOT, you lucky devil !!!\n");
            break;
        } //end case 6

        default:
        {
            printf("\nYou have won no prizes better luck next time!\n");
            break;
        } //end default
        } //end switch(matches)
} //end functions

//function 5 to display the users most choosen numbers
void display_frequency(int *chosen_numbers, int *freq)
{
    int i;


    for( i = 0; i < SIZE; i++)
    {
        printf("You have used Number:%d, %d times\n",*(chosen_numbers + i),*(freq + (*(chosen_numbers + i ))));
    } //end for

}//end function 

//function to leave programn when option 6 is pressed
int exit_programme(int leave)
{
    printf("\nAre you sure you want to Leave\nPress 1 to Exit\t Press 2 or any other number to stay\n");
    scanf("%d",&leave);
    
    //if the user inputs 1 return number 1 which will exit the system in case 6 
    if (leave == 1)
    {
        printf("\nBye, Bye Vist again sometimes!!");
        printf("\n_____________________________________________________________________________________\n");
        return leave;
    }//end if
    //any other input / 2 will keep us in the system
    else
    {
        printf("\nGlad you stayed\n");
    } //end else
}//end function

//function to error check scanf in main menu
int scan_check()
{
    int choice = 0;
    scanf("%d",&choice);
    while (getchar()!='\n');

    return choice;
} // end function

//function to add users lotto numbers into a frequency call
void update_freq(int *user_numbers, int *freq_array)
{
    int i;


    // for loop to place user numbers freqeunecy by 1 in the freq array holder
    for(i = 0; i < SIZE; i++)
    {
        *(freq_array + (*(user_numbers + i))) += 1; //frequency [user_numb[i] ] += 1; put users number in freq and add together into frq_array EXAMPLE freq[5]=0+1 (frequency user_numb[i] += 1 )
    } //end for
}//end function


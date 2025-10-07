/*  This is the Lotto program for CMPU1025, Assignment 2
    for the 20/03/22,
    Made by Cesar Hannin (C21415142)
    
    The program is meant to be easily adjustable by fiddling around with the #define values
    All computation and logic is supposed to be done in as many seprate functions as nessesary
    as asked by the assignment specification
*/

#include <stdio.h>
#include <string.h>                 // needed for the number -> english function
#include <stdlib.h>                 // needed for the random function and int input verification
#include <time.h>                   // needed for random seed
#include <stdbool.h>                // for the bool type 



#define DEBUG               if(0){
#define END_DEBUG           }

#define INPUT_BUFFER_SIZE   99999               // about 100KB seems to be ok incase the user slams the keyboard and types multiple characters, A MB seemed to be enough to accomadate any input
#define NUM_OF_ENTRIES      6                   // how many numbers can the user enter?
#define MIN_ENTRY_NUMBER    1                   // due to how integer input works here, the min entry number CANNOT be below 1
#define MAX_ENTRY_NUMBER    42
#define MIN_MATCHES_TO_WIN  3                   // the minimum amount of matches to make to pass the match-check
#define MATCH_6             "THE JACKPOT!"
#define MATCH_5             "A New Car"
#define MATCH_4             "A Weekend away"
#define MATCH_3             "A Cinema Pass"
#define IPs_ERROR_MESSAGE   "\n\nSorry, but please enter your chosen numbers first,\nYou can do this by selecting option 1 from the main menu!\n"   //insufficient plays error message



char* Convert_Int_To_English(int*);

int Verify_Entry(int*);

int Get_Int_Input();

void Generate_Lotto_Nums(int*);

void Show_Entry_Numbers(int*);

void Entry_Input(int*, int*);

void Custom_Sort(int*);

void Compare_Show_Prize(int*, int*);

void Get_Entry_Stats(int*, int*);

void Increment_Counter_List(int*, int*);

void Main_Menu(); 

void Show_Intro(bool*);

void Add_Entries(int*, int*, int*);



int main()
{
    Main_Menu();    //start up the main menu and begin our program
    
    return 0;
}



char* Convert_Int_To_English(int* i) //just to make some of the strings sound nicer
{
    if (*i > 11) //i havent put in more than 12 words
    {
        printf("\n\tProgram Error, need more english in Convert_Int_To_English function\nClampping to 'ninth' to keep this from breaking\n");

        *i = 11; // just return twelveth and continue
    }
    

    char * english_notation[12] = { "first",     "second",   "third",
                                    "fourth",   "fifth",    "sixth",
                                    "seventh",  "eigth",    "ninth",
                                    "tenth",    "eleventh", "twelveth", };


    return english_notation[*i];    
}



int Verify_Entry(int* entries_to_verify)    //return 0 on success, 1 on failure
{

    for (int x = 0; x < NUM_OF_ENTRIES; x++)
    {
        
        if ( !(entries_to_verify[x] >= MIN_ENTRY_NUMBER)  ||  !(entries_to_verify[x] <= MAX_ENTRY_NUMBER) ) //check to see if all numbers follow the rules
        {
            printf("\nThere was a problem detected with your %s number...\nIt's over or under the acceptable range\nOr Maybe it's invalid?\n",  Convert_Int_To_English(&x) );
            
            return 1;   //return failure
        }


        for (int y = 0; y < NUM_OF_ENTRIES; y++)
        {

            if ( (entries_to_verify[x] == entries_to_verify[y]) && (x != y ) )  //check to see if 2 numbers at different indexs are the same
            {
                printf("\nThere was a problem detected with your %s number...\nyou repeated some numbers\n",  Convert_Int_To_English(&x) );
                printf("\n\tPlease try again!\n");

                return 1;   //return failure

            }//end if
            
        }//end for loop
        
    }


    return 0;
}



int Get_Int_Input()
{
    char temp_input[INPUT_BUFFER_SIZE];     // the input buffer the user will type into
    char* char_ptr;                         // a char pointer, to be used later in this function with the strtol() function
    long int_of_input = 0;                  /*  if the user types ints and then characters, this long will be assigned to the ints he enetered.
                                                this is a long because the strtol() function returns a long and I didnt want to risk unforseen hiccups */

    printf(" : ");
    scanf("%s", &temp_input);             // get a string input from the user


    int_of_input = strtol(temp_input, &char_ptr, 10);       /*  learnt about this in the C documentation: https://www.tutorialspoint.com/c_standard_library/c_function_strtol.htm
                                                                Returns 0 for the long if no number is found... acceptable because the range of numbers is only from 1-42, and NOT 0-42 
                                                                    
                                                                strtol works like this: strtol(X, Y, Z)
                                                                    X is the inputed string that should have the integer
                                                                    Y is a temporay pointer that strtol uses to cycle through the inputted string until it gets to the end
                                                                    Z is just the base Number system to use, 2 is binary, 10 is normal numbers, 16 is hex, etc...
                                                            */

    return int_of_input;
}//end of Entry Input function



void Generate_Lotto_Nums(int* where_to_write_to)
{
    int iteration = 0;
    bool need_to_fix = true;


    srand( time(NULL) );    //set our random stream seed


    for (int i = 0; i < NUM_OF_ENTRIES; i++)
    {

        int temp_int = rand() % MAX_ENTRY_NUMBER + 1; //generate a number from 0 - MAX_ENTRY_NUMBER
        
        if( temp_int == 0)
        {
            temp_int++; //rand includes 0 when generating a random int... increase it to 1 just incase
        }//end if

        *(where_to_write_to + i) = temp_int;    //set our ranom number at i
        
    }//end for loop
    

    do
    {
        need_to_fix = false;


        for (int x = 0; x < NUM_OF_ENTRIES; x++)
        {

            for (int y = 0; y < NUM_OF_ENTRIES; y++)
            {

                if ( *(where_to_write_to + x) == *(where_to_write_to + y) && (x != y) ) //are the two numbers the same, and at different indexs?
                {
                    DEBUG
                        printf("\nDETECTED LOTTO MATCHING NUMBER\nTrying to fix for the %dth time\n", iteration);   //for debugging, can ignore
                    END_DEBUG

                    *(where_to_write_to + x) = rand() % MAX_ENTRY_NUMBER + 1; // regenerate the random number
                    
                    need_to_fix = true; //repeat the check again

                    break;  //stop the current for loop;

                }//end if
                
            }//end of inner for loop
        
        }//end of outer for loop
                

        iteration++;    //increase how many times this do has run


        if (iteration >= 999)   //if we've found identical numbers over 999 times, that means we've run into a huge problem, probably with the #defines
        {
            printf("\n\n\t############\t\tFATAL LOTTO NUMBER GEN ERROR\t\t############\n");
            printf("\t############\t\tPLEASE RESTART THE APP      \t\t############\n");
            
            need_to_fix = false;    //just stop the loop
        }//end if
        
    }//end of do

    while (need_to_fix);    //keep repeating until there's no more identical numbers


    Custom_Sort(where_to_write_to); //sort our lotto numbers

}



void Show_Entry_Numbers(int* numbers)
{
    printf("\nYour entered numbers were: \n");


    for (int i = 0; i < NUM_OF_ENTRIES; i++)
    {

        if (i == (NUM_OF_ENTRIES / 2) ) //just to make the number display look nicer, i wanted 2 rows, instead of one big one
        {
            printf("\n");
        }

        printf("\t%d\t", *(numbers + i) );  //print out the number at index i

    }//end for loop


    printf("\n\n"); //make sure there's a nice space at the end
}



void Entry_Input(int* number_frequencys, int* where_to_write_into)
{

    do
    {
        printf("\nPlease enter your numbers\n\tNOTE: Numbers must be in the range from %d to %d (inclusive)\n", MIN_ENTRY_NUMBER, MAX_ENTRY_NUMBER);


        for (int i = 0; i < NUM_OF_ENTRIES; i++)    //cycle through the array
        {  
            printf("\nPlease enter your %s number", Convert_Int_To_English(&i) );
            
            where_to_write_into[i] = Get_Int_Input();   //set the entry array to whatever the user types
        }//end for loop


    }//end do
    
    while ( Verify_Entry(where_to_write_into) );    //keep repeating the above until we get valid numbers


    printf("\n\tAll entries successfully inputted!\n\n\n");

    Increment_Counter_List(number_frequencys, where_to_write_into); //increase the frequency of the entered numbers in the number frequency table, for number statisics later on
}



void Custom_Sort(int* array) //my implementation of bubble sort, I tried to do quick sort but too much unneeded complexity was added
{
    bool change_made = false;
    
    do
    {
        change_made = false;    //this is here, otherwise an infitie loop will occur


        for (int i = 0; i < NUM_OF_ENTRIES-1; i++)
        {

            if ( *(array + i) > *(array + i + 1) )
            {
                int temp_int = *(array + i);//make a placeholder value of whats currently at i

                array[i] = array[i + 1];    //begin swapping the 2 numbers around
                                            //I only remembered that *(array + i) and array[i] do the same thing when I got here
                array[i+1] = temp_int;      

                change_made = true;   
            }//end of if
            

        }//end of for loop
        

    }//end of do

    while (change_made);    //keep repeating the above until no changes were needed  
    
}



void Compare_Show_Prize(int* entry, int* lotto)
{

    int matches = 0;


    for (int x = 0; x < NUM_OF_ENTRIES; x++)
    {

        for (int y = 0; y < NUM_OF_ENTRIES; y++)//cycle through the entered and lotto number arrays
        {

            if (*(entry + x) == *(lotto + y) )
            {
                matches++; //increment the amount of matches made if one was found
            }//end if
            
        }//end of the inner for-loop

    }//end of the outer for loop
    

    printf("\nYour numbers have made %d matches!\n\n", matches); 
    

    if(matches >= MIN_MATCHES_TO_WIN)   //if we need 3 matches in order to win anything, then do the following if we have > 3 made
    {
        
        printf("\t\t\tCONGRATULATIONS! \n");
        printf("\t\t\tYou just won ");
    

        //////////  I'M NOT HAPPY WITH THIS IMPLEMENTATION, I TRIED DEFINING AN ARRAY OF PRIZES USING #DEFINES BUT NOTHING WAS BOTH FUNCTIONAL  //////////
        //////////  AND SIMPLE... THIS WILL REQUIRE MANUAL EDITING IF MORE PRIZES WANT TO BE ADDED BECAUSE THIS IS HARD-CODED TO 4 PRIZES       //////////                             

        switch (matches)    //determine what prize to show, based off of the matches made
        {
            case 3:
                printf("%s", MATCH_3);
                break;

            case 4:
                printf("%s", MATCH_4);
                break;

            case 5:
                printf("%s", MATCH_5);
                break;

            default:    //Incase the user gets 6 or more matches
                printf("%s", MATCH_6);
                break;
        }//end switch

        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    }//end if

    else
    {
        printf("\n\nSorry, You didn't win anything\nBetter Luck next time!\n");
    }//end if-else


    ////////// Showing the Users numbers and the lottos
    printf("\nYour Numbers were :  \t");

    for (int i = 0; i < NUM_OF_ENTRIES; i++)
    {
        printf("%d, ", entry[i]);
    }


    printf("\nLotto Numbers were : \t");

    for (int i = 0; i < NUM_OF_ENTRIES; i++)
    {
        printf("%d, ", lotto[i]);
    }
    //////////

}



void Get_Entry_Stats(int* entered_numbers, int* number_frequencies)     //get the statistics of the numbers that the user entered 
{
    int inc_index;
    int freq_of_number;
    

    for (int i = 0; i < NUM_OF_ENTRIES; i++)
    {

        inc_index = *(entered_numbers + i);                 //make an index based off whatever number entered_numbers[i] is
        freq_of_number = *(number_frequencies + inc_index); //equivelant to number_frquency[inc_index], this is supposed to be the amount of thimes that number has been entered before


        if (freq_of_number > 1)
        {
            printf("\nYour %s number (%d) has been entered %d times before", Convert_Int_To_English(&i), inc_index, freq_of_number);
        }

        else
        {
            printf("\nYour %s number (%d) has been entered %d time before", Convert_Int_To_English(&i), inc_index, freq_of_number);
        }//end of if-else
        
    }//end of for loop

    printf("\n\n");

}//end of entry statistics function



void Increment_Counter_List(int* counter_list, int* entered_numbers)    //Meant to increase the frequencies of the entered numbers since runtime
{

    for (int i = 0; i < NUM_OF_ENTRIES; i++)
    {

        int inc_index = *(entered_numbers + i); //makes a temporary index, which is the integer at location i of the users entered numbers array 


        DEBUG
            printf("increased %d from %d to ", i, *(counter_list + inc_index));
        END_DEBUG


        *(counter_list + inc_index) = *(counter_list + inc_index) + 1;  //increment the int at 
        

        DEBUG
            printf("%d\n", *(counter_list + inc_index) );   //just to make sure the int got incremented
        END_DEBUG

    }//end for loop
    
}//end of the frquency table incrementation function



void Main_Menu()
{
    int choice;                                                             //what the user has decided to do in the menu
    int entered_numbers[NUM_OF_ENTRIES];                                    //an array to hold the users entry
    int number_frequencys[ ((MAX_ENTRY_NUMBER - MIN_ENTRY_NUMBER) + 2) ];   //A table to record how often a number has been entered for lotto entries
    int lotto_nums[NUM_OF_ENTRIES];                                         //an array to hold the lotto numbers
    bool entered_once = false;                                              //used to determine if the user has played at least once


    Generate_Lotto_Nums(lotto_nums);    //initiallise and sort our Lotto Numbers


    for (int i = 0; i < ((MAX_ENTRY_NUMBER - MIN_ENTRY_NUMBER) + 1); i++)
    {
        number_frequencys[i] = 0; //make sure that our number frquency table is fully initiallised
    }
    

    do  //this is our menu, should keep doing this until the user decides to exit 
    {
        Show_Intro(&entered_once);

        printf("\nPlease select what you would like to do?");

        choice = Get_Int_Input();   //set the choice of what to do based off the users input


        switch (choice)
        {
            case 1:

                Entry_Input(number_frequencys, entered_numbers);    //get the user input and write it into the address of 'entered_numbers'

                entered_once = true;    //the user has now entered something

                break; //end case 1


            case 2:


                if ( entered_once ) //only do the following if the user has entered something first
                {  
                    Show_Entry_Numbers(entered_numbers);    //show the entered numbers as defined by this function
                }//end if
                

                else
                {
                    printf(IPs_ERROR_MESSAGE);
                }//end of if-else

                break;// end of case 2


            case 3:


                if ( entered_once ) //only do the following if the user has entered something first
                {
                    printf("\nSorting your numbers now");
                    Custom_Sort(entered_numbers);   //sort the numbers at the memory address of the entered numbers array
                    printf("...\nNumbers are now sorted!\nChoose the see 'my numbers option' from the menu to see them\n"); //printf's are here just to give some feedback to the user
                }

                else 
                {
                    printf(IPs_ERROR_MESSAGE);
                }//end of if-else

                break;// end of case 3


            case 4: //Comparing the users numbers to the lotto and seeing what he gets
            

                if ( entered_once ) //only do the following if the user has entered something first
                {
                    Compare_Show_Prize(entered_numbers, lotto_nums);    //compare the entered numbers with the lotto numbers and see what prizes are won
                }

                else 
                {
                    printf(IPs_ERROR_MESSAGE);  //the user hasnt played once yet
                }//end of if-else

                break;// end of case 4


            case 5: //geting the statisics of the users entered numbers 


                if (entered_once)   //only do the following if the user has entered something first
                {
                    Get_Entry_Stats(entered_numbers, number_frequencys); //call the statisics function, passing in the users entered numbers and the number frequency table
                }

                else
                {
                    printf(IPs_ERROR_MESSAGE);  //the user hasnt played once yet
                }//end of if-else

                break;// end of case 5


            case 6: //user quits
                
                printf("\n\nThank you!\nDo come again");
                
                break;       


            default:

                printf("\n\nI'm sorry but that's an invalid input,\nPlease choose from the menu items above\nThank you\n\n\n");
            
                break;

            
        }//end switch
    
    }//end do

    while (choice != 6); //6 is the exit option
    
}//end of Main Menu Function



void Show_Intro(bool *has_entered_before)
{
    DEBUG
        printf("\n###############\t\tBTW, you're in Debug mode, remember to turn off before sending off\t\t###############\n");
    END_DEBUG


    printf("\n\n=========================  Welcome to the Hannin Inc. Lotto!  =========================");
    printf("\n                          Please select an action from below:                          ");
    printf("\n                                                                                       ");
    

    if(*has_entered_before == 1)
    {
        printf("\n          1.)     Re-enter in my numbers for the Lotto!          ");                                  
    }//end if
    
    else
    {
        printf("\n          1.)     Enter in my numbers for the Lotto!          ");                                  
    }//end else


    printf("\n          2.)     Show my Lotto Numbers!                                              ");                                  
    printf("\n          3.)     Sort my numbers                                                     ");                                  
    printf("\n          4.)     Compare Numbers and Show what prizes I win!                         ");                                  
    printf("\n          5.)     View the statisics of my numbers!                                   ");                                  
    printf("\n          6.)     Exit                                                            \n\n");       
    printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n ");

}// end of Show intro function 
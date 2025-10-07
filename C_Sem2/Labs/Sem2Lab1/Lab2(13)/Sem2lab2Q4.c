/*Programn to find odd or even numbers using an function
Darren Grants 08/02/22
*/
#include <stdio.h>

#define SIZE 3

char common_finder(char*, char*, char*);

int main()
{
    char user_char1;
    char user_char2;
    char user_char3;
    char mostcommon;

    printf("\nPlease input %d character to find the most common\n",SIZE);

    scanf("%c",&user_char1);
    
    while(getchar() !='\n');
   
    scanf("%c",&user_char2);
    
    while(getchar() !='\n');
    
    scanf("%c",&user_char3);
    
    //Function call to find common
    mostcommon = common_finder(&user_char1, &user_char2, &user_char3);
    
    printf("Your most common character is %c", mostcommon);

    return 0;
}

char common_finder(char *user_char1,char *user_char2, char *user_char3)
{
    char common; //Can use Return user_num1/2/3 instead of Common = *user_char1/2/3

    if (*user_char1 == *user_char2 || *user_char1 == *user_char3)
    {
        common = *user_char1;
    }
    else if (*user_char2 == *user_char1 || *user_char2 == *user_char3)
    {
        common = *user_char2;
    }
    else
    {
        common = *user_char3;
    }
    
    return common;
}




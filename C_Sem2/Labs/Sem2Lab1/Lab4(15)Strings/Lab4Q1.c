#include <stdio.h>

#define SIZE 5

int main()
{
   printf("\n%5s","abcd"); // normal print
   printf("\n%5s","abcdef"); //just works
   printf("\n%-5s","abc"); //
   printf("\n%5.2s","abcd"); //1st 2 by decimal
   printf("\n%-5.2s","abcde"); //1st 2 by decimal
}
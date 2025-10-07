#include <stdio.h>
#include <string.h>

#define SIZE 7

int main()
{
   char name[SIZE]={'R','o','b','e','r','t'};
   
   *(name + 5) = 'a'
   ;
   printf("\n%s",name);
   return 0;
}
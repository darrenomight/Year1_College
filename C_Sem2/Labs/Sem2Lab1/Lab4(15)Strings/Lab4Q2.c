#include <stdio.h>
#include <string.h>

#define SIZE 7

int main()
{
   char name[SIZE]={'R','o','b','e','r','t'};

   puts(name);  //intilise array
   
   scanf("%s",name); // no & sign needed
   
   strcpy(name, "Philip");
   printf("\n%s", name);
   
   *(name + 5) = 'a';
   printf("\n%s",name);
   
   char name2;
   
   strcpy(name,"Philip2");
   printf("%s",name);
   
   return 0;
}
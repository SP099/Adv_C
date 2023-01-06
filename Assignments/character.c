/*
● WAP to check whether character is
– Upper case
– Lower case
– Digit
– No of the above
*/
#include <stdio.h>
int main()
{
   char ch;
   printf("enter the character:");
   scanf("%c",&ch);

   if( ch >= 'a' && ch <= 'z' )
      printf("lower case letter");

   else if( ch >= 'A' && ch <= 'Z' )
      printf("upper case letter");

   else if( ch >= '0' && ch <= '9' )
      printf("digit");

   else
      printf("special character");

   printf("\n");
   return 0;

}

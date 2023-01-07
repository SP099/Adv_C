//WAP to print number is palindrome or not

#include <stdio.h>
int main()
{  
   int x,y=0,temp;
   printf("enter the number:");
   scanf("%d",&x);
   temp=x;
   while (x)
   {
      y=y*10+x%10;
      x=x/10;
   }
   
   if(temp==y)
      printf("%d is a palindrome number",temp);

   else
       printf("%d is not palindrome number",temp);

   printf("\n");
   return 0;

}

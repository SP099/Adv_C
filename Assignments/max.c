//● WAP to find the max of two numbers

#include <stdio.h>
int main()
{
   int num1,num2;
   printf("enter two numbers:");
   scanf("%d%d",&num1,&num2);

   if( num1 > num2 )
      printf("maximum of %d and %d is %d",num1,num2,num1);

   else if( num2 > num1 )
      printf("maximum of %d and %d is %d",num1,num2,num2);

   else
      printf("%d is equal to %d",num1,num2);

   printf("\n");
   return 0;

}

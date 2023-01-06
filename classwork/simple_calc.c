//● W.A.P for simple calculator using switch

#include <stdio.h>
int main()
{
   int num1,num2;
   char ch;
   printf("\n+.Additon");
   printf("\n-.substracton");
   printf("\n*.multiplication");
   printf("\n/.division");
   printf("\nenter your choice:");
   scanf("%c",&ch);
   
   switch ( ch )
   {
   case '+' :
      printf("enter two numbers:");
      scanf("%d%d",&num1,&num2);
      printf("Addition of %d & %d is %d",num1,num2,num1+num2);
      break;

   case '-' :
      printf("enter two numbers:");
      scanf("%d%d",&num1,&num2);
      printf("substraction of %d & %d is %d",num1,num2,num1 - num2);
      break;
   
   case '*' :
      printf("enter two numbers:");
      scanf("%d%d",&num1,&num2);
      printf("multiplication of %d & %d is %d",num1,num2,num1 * num2);
      break;

   case '/' :
      printf("enter two numbers:");
      scanf("%d%d",&num1,&num2);
      printf("division of %d & %d is %d",num1,num2,num1 / num2);
      break;

   default:
      printf("Invalid Choice");
      break;
   }

   printf("\n");
   return 0;

}

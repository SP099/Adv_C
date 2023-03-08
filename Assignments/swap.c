/*
Name            : Sushant Patil
date            : 05/03/2023
Description     : WAP to define a macro swap (t, x, y) that swaps 2 arguments of type t
                  Implement swap concept with the help of macro
                  The type of arguments to swap will be passed as t
                  swap (int, x, y) where x and y are of types int.
Sample Execution: Test Case 1:
                  user@emertxe] ./swap
                  1. Int
                  2. char
                  3. short
                  4. float
                  5. double
                  6. string
                  Enter you choice : 1

                  Enter the num1 : 10
                  Enter the num2 : 20
                  After Swapping :
                  num1 : 20
                  num2 : 10              
 */

#include<stdio.h>
#include <stdlib.h>
#include<stdio_ext.h>

/*->defines the SWAP macro, which takes three arguments: 
    the data type of the variables, and the two variables to be swapped.
  ->The macro defines a temporary variable temp to store the value of num1, 
    then swaps the values of num1 and num2.
*/
#define SWAP(type,num1,num2) \
{                           \
  type temp = num1;         \
  num1 = num2;              \
  num2 = temp;              \
}

int main()
{ 
  //declaration of variable
  int choice;

  //printing a menu of data types and prompts the user to enter their choice.
  printf("1. Int\n2. char\n3. short\n4. float\n5. double\n6. string\nEnter your choice: ");
  scanf("%d", &choice);

  //starts a switch statement based on the user's choice.
  switch (choice)
  {

    //corresponds to int data type.
    case 1:
    {
      //declaration of variables
      int num1,num2;

      //getting input from user
      printf("Enter the num1 : ");
      scanf("%d", &num1);

      //getting input from user
      printf("Enter the num2 : ");
      scanf("%d", &num2);

      //calling the SWAP macro with the int data type and the num1 and num2 variables to swap their values.
      SWAP(int,num1,num2);

      //printing the swapped values of num1 and num2.
      printf("After Swapping :\nnum1 : %d\nnum2 : %d\n",num1,num2);
    }
    break;
  
    //corresponds to char data type.
    case 2:
    {
      //declaration of variables
      char ch1,ch2;

      //getting input from user
      printf("Enter the char1 : ");
      scanf(" %c", &ch1); // using a space before %c to consume newline left in buffer

      //getting input from user
      printf("Enter the char2 : ");
      scanf(" %c", &ch2); // using a space before %c to consume newline left in buffer
      
      //calling the SWAP macro
      SWAP(char,ch1,ch2);

      //printing the swapped values
      printf("After Swapping :\nchar1 : %c\nchar2 : %c\n",ch1,ch2);
    }
    break;

    //corresponds to short data type.
    case 3:
    {
      //declaration of variables
      short num1,num2;

      //getting input from user
      printf("Enter the num1 : ");
      scanf("%hd", &num1);

      //getting input from user
      printf("Enter the num2 : ");
      scanf("%hd", &num2);

      //calling the SWAP macro
      SWAP(short,num1,num2);

      //printing the swapped values
      printf("After Swapping :\nnum1 : %hd\nnum2 : %hd\n",num1,num2);
    }
    break;

    //corresponds to float data type.
    case 4:
    {
      //declaration of variables
      float num1,num2;

      //getting input from user
      printf("Enter the num1 : ");
      scanf("%f", &num1);

      //getting input from user
      printf("Enter the num2 : ");
      scanf("%f", &num2);

      //calling the SWAP macro
      SWAP(float,num1,num2);

      //printing the swapped values
      printf("After Swapping :\nnum1 : %f\nnum2 : %f\n",num1,num2);
    }
    break;

    //corresponds to double data type
    case 5:
    {
      //declaration of variables
      double num1,num2;

      //getting input from user
      printf("Enter the num1 : ");
      scanf("%lf", &num1);

      //getting input from user
      printf("Enter the num2 : ");
      scanf("%lf", &num2);

      //calling the SWAP macro
      SWAP(double,num1,num2);

      //printing the swapped values
      printf("After Swapping :\nnum1 : %lf\nnum2 : %lf\n",num1,num2);
    }
    break;
    
    //corresponds to string
    case 6:
    {
      //declaration of pointers
      char *str1, *str2;
      
      //allocating memory dynamically
      str1 = malloc(100 * sizeof(char));

      //checking if the memory allocation is successful or not
      if (str1 == NULL)
      {
          printf("Memory allocation failed!\n");
          return 1;
      }

      //allocating memory dynamically
      str2 = malloc(100 * sizeof(char));

      //checking if the memory allocation is successful or not
      if (str2 == NULL) 
      {
          printf("Memory allocation failed!\n");
          return 1;
      }
      
      //getting input from user
      printf("Enter the string1: ");
      __fpurge(stdin);
	  scanf("%[^\n]", str1);

      //getting input from user
      printf("Enter the string2: ");
      __fpurge(stdin);
	  scanf("%[^\n]", str2);
      
      //calling the SWAP macro
      SWAP(char *, str1, str2);

      //printing the swapped values
      printf("\nAfter Swapping :\nString 1: %s\nString 2: %s\n", str1, str2);

      //deallocating memory
      free(str1);
      free(str2); 
      return 0;
    }
    break;
    
    //if user entered invalid choice printing error
    default:
    printf("Invalid choice!\n");
    break;
  }
  return 0 ;
}

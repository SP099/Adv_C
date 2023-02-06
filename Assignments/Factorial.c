/*

Name             : Sushant Patil
Date             : 06/02/2023
Description      : WAP to find factorial of given number using recursion
                   -> Read number n from user.
                   -> Validate the given number
                   -> Call main function from main for calculating factorial.
                   -> Prompt for continue option without using loop.
Sample Execution : user@emertxe] ./factorial
                   Test Case 1:
                   Enter the value of N : 7
                   Factorial of the given number is 5040

                   Test Case 2:
                   Enter the value of N : 5
                   Factorial of the given number is 120

                   Test case 3:
                   Enter the value of N : -1
                   Invalid Input

                   Test case 4:
                   Enter the value of N : 0
                   Factorial of the given number is 1

*/

#include <stdio.h>

int main()
{
    //declaration and initilizataion of variables
    static int num;
    static unsigned long long int fact = 1;
    static int flag = 0 ;
    
    if( flag == 0 )
    { 
        //getting number from user
        printf("Enter the value of N : ");
        scanf("%d",&num);
        
        //if number is negative then printing error
        if( num < 0 )
        {
            printf("Invalid input\n");
            return 0;
        }

        flag = 1 ;
    }

    //logic to get factorial of number
    if( num > 0 )
    {
        fact = fact * num-- ;

        //recursive function
        main();
    }

    else
    {
        //printing ouput
        printf("Factorial of the given number is %llu\n",fact);
        return 0 ;
    }
}

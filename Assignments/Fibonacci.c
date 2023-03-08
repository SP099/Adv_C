/*

Name            : Sushant Patil
Date            : 11/02/2023
Description     : WAP to generate fibbonacci numbers using recursion
                ->In mathematics, the Fibonacci numbers or Fibonacci sequence are the numbers 
                  in the following integer sequence  1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144 . . .OR 
                  0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144 . . .
                ->By definition, the first two numbers in the Fibonacci sequence are either 1 and 1, or 0 and 1, 
                  depending on the chosen starting point of the sequence, 
                  and each subsequent number is the sum of the previous two.
Sample execution: user@emertxe] ./fibbonacci_series
                  Test Case 1 :
                  Enter a number: 8
                  0, 1, 1, 2, 3, 5, 8

                  Test Case 2:
                  Enter a number: 10
                  0, 1, 1, 2, 3, 5, 8

                  Test Case 3:
                  Enter a number: -12
                  Invalid input

*/
#include <stdio.h>

//function declaration
void positive_fibonacci(int, int, int, int);

int main()
{
    //declaration of variable
    int limit;
    
    //getting limit from user
    printf("Enter the limit : ");
    scanf("%d", &limit);
    
    //condition for positive number
    if( limit >= 0 )
    {
        //function call
        positive_fibonacci(limit, 0, 1, 0);
    }
    else
    {
        //printing error if limit is negative
        printf("Invalid Input");
    }

    printf("\n");
    return 0;
}
void positive_fibonacci(int limit, int first, int second, int sum)
{
    //condition to print series upto limit
    if ( sum <= limit )
    {   
        //printing positive fibonacci series  
        printf("%d, ",sum);
        
        //updating first,second and sum
        first = second;
        second = sum;
        sum = first + second;

        //recursive function
        positive_fibonacci(limit, first, second, sum);
    }

}


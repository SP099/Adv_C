/*
Name             : Sushant Patil
Date             : 11/02/2023
Description      : WAP to generate negative fibbonacci numbers using recursion
                   ->In mathematics, the Fibonacci numbers or Fibonacci sequence are the numbers 
                     in the following integer sequence  0, 1, -1, 2, -3, 5, -8, 13, -21, 34, -55, 89, -144 . . .
                   ->By definition, the first two numbers in the Fibonacci sequence are 0 and 1, 
                     each subsequent number is the subtraction of the previous two
Sample execution : user@emertxe] ./neg_fib_rec
                   Test Case 1:
                   Enter a number: -10
                   0, 1, -1, 2, -3, 5, -8

                   Test Case 2:
                   Enter a number: -21
                   0, 1, -1, 2, -3, 5, -8, 13, -21

                   Test Case 3:
                   Enter a number: 21
                   Invalid input
*/
#include <stdio.h>

//function declaration
void negative_fibonacci(int, int, int, int);

int main()
{
    //declaration of variable
    int limit ;
    
    //getting limit from user
    printf("Enter the limit : ");
    scanf("%d", &limit);
    
    //condition for negative number
    if( limit <= 0 )
    {   
        //function call
        negative_fibonacci(limit, 0, 1, 0);
    }
    else
    {
        //printing error if limit is positive
        printf("Invalid Input");
    }

    printf("\n");
    return 0;
}

void negative_fibonacci(int limit, int first, int second, int sum)
{
 
    //condition to print series upto limit
    if( sum >= limit && ( sum <= ( limit * (-1) )))
    {
        //printing negative fibonacci series
        printf("%d, ",sum);

        //updating first,second and sum
        first = second;
        second = sum;
        sum = first - second;
        
        //recursive function
        negative_fibonacci(limit, first, second, sum);
    }

}


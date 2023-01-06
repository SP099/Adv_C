/*
Name          : Sushant Patil
Date          : 28/12/2022
Description   : WAP to generate positive Fibonacci numbers
Sample Input  : Enter a number: 10
Sample Output : 0 1 1 2 3 5 8
*/

#include<stdio.h>
int main()
{
    
    //Declaration of variables
    int first,second,num,sum;
    
    //Initilize first,second and sum terms
    first = -1;
    second = 1;
    sum = 0;

    //get number from user
    printf("Enter a number:");
    scanf("%d",&num);

    //Enter only positive number
    if( num < 0 )
        printf("Invalid input");

    else
    {
        //Printing series upto 'nth' term 
        while( sum <= num )
        {
            //printing output
            printf("%d ",sum);

            //updating values of first,second and sum
            first = second;
            second = sum;
            sum = first + second;
       }
    }

    printf("\n");
    return 0;
}

/*
Name          : Sushant Patil
Date          : 28/12/2022
Description   : WAP to generate negative Fibonacci numbers
Sample Input  : Enter a number: -8
Sample Output : 0 1 -1 2 -3 5 -8
*/

#include<stdio.h>
int main()
{
    //declration of variables
    int first,second,sum,num;

    //initilize first,second and sum
    first = -1;
    second = 1;
    sum = 0;

    //Get number from user
    printf("Enter a number:");
    scanf("%d",&num);

    //enter only negative number
    if( num > 0 )
        printf("Invalid input");

    else
    {
        //printing series upto 'nth' term
        while( sum>= num && sum <= -num )
        {
            //printing output
            printf("%d ",sum);

            //updating values of first,second and sum
            first=second;
            second=sum;
            sum=first-second;
       }
    } 

    printf("\n");
    return 0;
}

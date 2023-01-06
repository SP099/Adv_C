/*
Name          : Sushant Patil
Date          : 22/12/2022
Description   : WAP to check if number is perfect or not
Sample Input  : Enter a number: 6
Sample Output : Yes, entered number is perfect number
*/

#include<stdio.h>
int main()
{
    //variable declaration
    int num;

    //initilization of variable
    int sum=0;

    //reading input from user
    printf("Enter a number:");
    scanf("%d",&num);

    //condition for positive number
    if(num>0)
    {
        //Adding factors of entered number
        for(int i=1;i<=num/2;i++)           
            {
                if(num%i==0)
                sum=sum+i;
            }

        //condition for sum of factors of entered number eqaul to number
        if(num==sum)

            //printing Yes if entered number is perfect
            printf("Yes, entered number is perfect number");
        else

            //printing No if entered number is not perfect
            printf("No, entered number is not a perfect number");
    }

    //printing error if number is negative
    else
        printf("Error : Invalid Input, Enter only positive number");

    printf("\n");
    return 0;
}

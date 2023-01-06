/*
Name          : Sushant Patil
Date          : 22/12/2022
Description   : WAP to check if number is odd or even
Sample Input  : Enter the value of 'n' : -2
Sample Output : -2 is negative even number
*/

#include<stdio.h>
int main()
{

    //variable declaration
    int n;

    //reading input from the user
    printf("Enter the value of 'n' :");
    scanf("%d",&n);

    //condition for negative number
    if(n < 0)

        //printing negative even number
        if(n % 2 == 0)
            printf("%d is negative even number",n);

        //printing negative odd number
        else
            printf("%d is negative odd number",n);

    //condition for positive number
    else if(n > 0 )

        //printing positive even number
        if(n % 2 == 0)
            printf("%d is positive even number",n);

        //printing positive odd number
        else
            printf("%d is positive odd number",n);

    //printing number is neither odd nor even
    else
        printf("%d is neither odd nor even",n);

    printf("\n");
    return 0;
}

/*
Name          : Sushant Patil
Date          : 29/12/2022
Description   : WAP to print the numbers in X format
Sample Input  : Enter the number: 4
Sample Output : 1  4
                 23
                 23
                1  4
*/

#include<stdio.h>
int main()
{

    //Declaration of variables
    int num,row,col;

    //get number from user
    printf("enter the number:");
    scanf("%d",&num);

    //entered number must be positive
    if( num > 0 )
    {

        //initiate loop for row
        for( row = 1; row <=num ; row++ )
        {

            //initiate loop for column
            for ( col = 1 ; col <= num ; col++ )
            {

                //printing output

                if( row == col)
                    printf("%d",col);

                else if( row + col == num + 1 )
                    printf("%d",col);

                else
                    printf(" ");

            }

            printf("\n");

         }
    }
    
    //print error if negative number
    else
       printf("Invalid Input");

    printf("\n");
    return 0;  

}


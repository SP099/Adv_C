/*
Name          : Sushant Patil
Date          : 01/01/2023
Description   : WAP to print pyramid pattern as shown below
Sample Input  : Enter the number: 4
Sample Output : 4
                3 4
                2 3 4
                1 2 3 4
                2 3 4
                3 4
                4
*/

#include<stdio.h>
int main()
{
    //declaration of variables
    int num,row,col,k;

    //get number from user
    printf("enter the number:");
    scanf("%d",&num);

    //this is upper half of pattern

    //iteration over each row
    for( row = num ; row >= 1 ; row-- )
    {

        k = row ;

        //iteration over each column
        for( col = num ; col >= 1 ; col-- )
        {

            if( col >= row )
                printf("%d ",k);

            else
                printf(" ");
                k++;

        }

        //move to the next line
        printf("\n");
    }


    //this is lower half of pattern

    //iteration over each row
    for( row = 1 ; row <= num ; row++ )
    {

        k = row ;

        //iteration over each column
        for( col = num ; col >= 1 ; col-- )
        {

            if( col >= row + 1 )
                printf("%d ",k + 1 );

            else
                printf(" ");
                k++;

        }

        //move to the next line
        printf("\n");

    }

    return 0;
}


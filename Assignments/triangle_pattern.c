/*
Name          : Sushant Patil
Date          : 01/01/2023
Description   : WAP to print triangle pattern as shown below
Sample Input  : Enter the number: 5
Sample Output : 1 2 3 4 5
                6     7
                8   9
                10 11
                12
*/

#include<stdio.h>
int main()
{
    //declaration of variables
    int num,row,col,k;

    //get number from user
    printf("Enter the number:");
    scanf("%d",&num);
    
    //initilize k
    k = 1 ;

    //initilise loop for rows
    for( row = 1 ; row <= num ; row++ )
    {  
       //initilise loop for column
       for ( col = 1 ; col <= (num + 1 - row) ; col++ )
       {
           //use conditions to print expected output
           if( row == 1 || col == 1 || ( row + col == num + 1 ) )
               printf("%d ",k++);
           
           else
               printf(" ");

       } 

       printf("\n");

    }

    printf("\n");
    return 0;
}


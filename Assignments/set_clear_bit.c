/*
Name          : Sushant Patil
Date          : 12/01/2023
Description   : WAP to check N th bit is set or not, If yes, clear the M th bit
Sample Input  : ./set_clear_bit
Sample Output : Enter the number: 19

                Enter 'N': 1

                Enter 'M': 4
                 
                Updated value of num is 3
*/

#include<stdio.h>
int main()
{
    //declaration of variables
  	int num,N,M;

    //get number from user
    printf("Enter the number: ");
    scanf("%d",&num);

    //get nth bit from user
    printf("Enter 'N': ");
    scanf("%d",&N);

    //get mth bit from user
    printf("Enter 'M': ");
    scanf("%d",&M);

    //nth bit and mth bit must be in between range from 0 t0 31 bit
    if( N>=0 && N<=31 && M>=0 && M<=31)
    {
        //checking nth bit is set or not
        if(num&(1<<N))
        {
            //if nth bit is set then clear mth bit and print updated value of num
            printf("Updated value of num is %d",(num & ~(1<<M)));
        }
        else
        {   
            //printing same num if nth bit is not set
            printf("Updated value of num is %d", num);
        }
    }
    else
    {
        //printing error if nth bit and mth bit is not in between range
        printf("Invalid Input");
    }
    printf("\n");
    return 0;
}


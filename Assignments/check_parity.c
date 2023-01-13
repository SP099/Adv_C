/*
Name          : Sushant Patil
Date          : 12/01/2023
Description   : WAP to count number of set bits in a given number and print parity
Sample Input  : user@emertxe] ./check_parity
Sample Output : Enter the number : 7

                Number of set bits = 3

                Bit parity is Odd
*/

#include<stdio.h>
int main()
{   
    //declaration of variables
    int num,i,count;

    //initilization of variable
    count = 0 ;

    //get number from user
    printf("Enter the number : ");
    scanf("%d",&num);

    //for integer initiate loop 0 to 31(integer is 4 byte)
    for( i = 0 ; i <= 31 ; i++ )
    {
        //logic to get total numbr of set bit in number
        if(( num & ( 1 << i ) ) )
        {
            count++;
        }
    }

    //printing total number of set bit
    printf("\nNumber of set bits = %d\n",count);

    //logic to check bit parity 
    if( count % 2 )
    {
        printf("\nBit parity is Odd");
    }

    else
    {
        printf("\nBit parity is Even");
    }

    printf("\n");
    return 0;
}

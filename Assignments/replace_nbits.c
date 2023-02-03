/*
Name          : Sushant Patil
Date          : 24/01/2023
Description   : WAP to replace 'n' bits of a given number
Sample Input  : user@emertxe]./replace_nbits
Sample Output : Enter the number: 10

                Enter number of bits: 3

                Enter the value: 12

                Result = 12
*/

#include <stdio.h>

//declaration of replace_nbits function
int replace_nbits(int, int, int);

int main()
{
    //declaration of variables
    int num, n, val, res ;
    
    //geting number from user
    printf("Enter the number:");
    scanf("%d", &num);

    //getting n bits from user
    printf("\nEnter number of bits:");
    scanf("%d", &n);

    //getting number from user
    printf("\nEnter the value:");
    scanf("%d", &val);
    
    //bit should be in between 1 to 31
    if(n>=1&&n<=32)
    {
        //calling replace_nbits function and storing result in res variable
        res = replace_nbits(num, n, val);
    
        //printing result
        printf("\nResult = %d\n", res);
    }
    else
    {   
        //printing error
        printf("\ninvalid input");

    }
    printf("\n");
    return 0;
}

int replace_nbits(int num, int n, int val) //called function
{
    //declaration of variables
    int mask1, mask2;
    
    //clearing n bits from lsb of 'num' and storing in num
    mask1 = ~ (( 1 << n ) - 1 ) ;
    num = num & mask1 ;

    //taking n bits from lsb end of 'val' and storing in mask2
    mask2 = (( 1 << n ) - 1 ) ;
    mask2 = val & mask2 ;
    
    //replacing num from lsb using mask2,using bitwise OR
    return num | mask2 ;


}

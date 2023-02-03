/*
Name          : Sushant Patil
Date          : 26/01/2023
Description   : WAP to toggle 'n' bits from given position of a number
Sample Input  : user@emertxe] ./toggle_nbits_from_pos
Sample Output : Enter the number: 10

                Enter number of bits: 3

                Enter the pos: 5

                Result = 50
*/

#include <stdio.h>

//declaration of function
int toggle_nbits_from_pos(int, int, int);

int main()
{
    //declaration of variables and initilize res equal to 0
    int num, n, pos, res = 0 ;
    
    //get number from user
    printf("Enter the number:");
    scanf("%d", &num);
    
    //get number of bits from user
    printf("\nEnter number of bits:");
    scanf("%d", &n);

    //get position from user
    printf("\nEnter the pos:");
    scanf("%d", &pos);

    /*position should be in between 0 to 31 and
    bits should be in between 1 to 32 */
    if( n >= 1 && n <= 32 && pos >= 0 && pos <= 31 )
    { 

        /* calling toggle_nbits_from_pos function and 
        storing result of function in res variable */
        res = toggle_nbits_from_pos(num, n, pos);
    
        //printing output
        printf("\nResult = %d\n", res);

    }

    else
    {
        //printing error
        printf("\ninvalid input");
    }
}

int toggle_nbits_from_pos(int num, int n, int pos) 
{
    //declaration of variables and initilize res equal to 0
    int mask1, mask2, res=0 ;

    //logic to create mask
    mask1 = (( 1 << n ) -1 );
    mask2 = mask1 << ( pos - ( n - 1 )) ;
    
    /* toggling 'n' bits from given position of a number with mask2 
    using bitwise XOR operator */
    res = num ^ mask2 ;

    //returning result to main()
    return res;
}

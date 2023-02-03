/*
Name          : Sushant Patil
Date          : 25/01/2023
Description   : WAP to get 'n' bits from given position of a number
Sample Input  : user@emertxe] ./get_nbits_from_pos
Sample Output : Enter the number: 12

                Enter number of bits: 3

                Enter the pos: 4

                Result = 3
*/

#include <stdio.h>

//declaration of function
int get_nbits_from_pos(int, int, int);

int main()
{
    //declaration of variables
    int num, n, pos, res ;
    
    //get number from user
    printf("Enter the number: ");
    scanf("%d", &num);
    
    //get number of bits from user
    printf("\nEnter number of bits: ");
    scanf("%d", &n);

    //get position from user
    printf("\nEnter the pos: ");
    scanf("%d", &pos);
    
    /*position should be in between 0 t0 31 and
    bits should be in between 1 to 32 */
    if(n>=1&&n<=32&&pos>=0&&pos<=31)
    {
        /* calling get_nbits_from_pos function and 
        storing result of function in res variable */
        res = get_nbits_from_pos(num, n, pos);
    
        //printing output
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

int get_nbits_from_pos(int num, int n, int pos)
{
    //declaration of variables and initilize res equal to 0
    int mask1, mask2, res=0 ;

    /*fetcheing 'n' bits from position 'pos' of num 
    and returning result to main() */

    mask1 = (( 1 << n ) -1 );
    mask2 = mask1 << ( pos - ( n - 1 )) ;
    res = ( num & mask2 ) >> (( pos - ( n - 1 ))) ;
   
    return res;
}

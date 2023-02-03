/*
Name          : Sushant Patil
Date          : 29/01/2023
Description   : WAP to put the (b-a+1) lsb’s of num into val[b:a]
Sample Input  : user@emertxe] ./bit_ops
Sample Output : Enter the value of 'num' : 11
                Enter the value of 'a' : 3
                Enter the value of 'b' : 5
                Enter the value of 'val': 174
                Result : 158
*/

#include <stdio.h>

//function declaration
int replace_nbits_from_pos(int, int, int, int);

int main()
{
    //declaration of variables and initilize res equal to 0
    int num, a, b, val, res = 0;

    //getting number from user
    printf("Enter the value of 'num' : ");
    scanf("%d", &num);

    //getting value of 'a' from user
    printf("Enter the value of 'a' :");
    scanf("%d",&a);

    //getting value of 'b' (position) from user
    printf("Enter the value of 'b' : ");
    scanf("%d",&b);

    //getting value from user
    printf("Enter the value of 'val':");
    scanf("%d",&val);

    //validation for a and b
    if( a>= 0 && a <= 31 && b >= 0 && b <= 31)
    {
        //getting result from called function replace_nbits_from_pos
        res = replace_nbits_from_pos(num, a, b, val);

        //printing result
        printf("Result = %d\n", res);
    }
    else
    {
        //printing error
        printf("invalid input");
    }

    printf("\n");
    return 0;
}

int replace_nbits_from_pos(int num, int a, int b, int val)
{
    //declaration of variable
    int n;

    //calculating no. of bits (n) using values of a and b
    n = b - a + 1 ;

    //clearing 'n' no. of bits from position 'b' of 'val'
    val = val & ( ~((( 1 << n ) -1 ) << ( b - ( n - 1 ))) );

    /* fectching 'n' bits from LSB end of 'num'
    and moving fetched bits towords required position */
    num = ( (num & ( ( 1 << n ) - 1 )) << (b - ( n - 1)) ) ;

    /* replacing 'n' bits from position 'b' of 'val'
    and returning their result to main */
    return val | num ;
}

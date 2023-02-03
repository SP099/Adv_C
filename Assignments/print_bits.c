/*
Name          : Sushant Patil
Date          : 28/01/2023
Description   : WAP to print 'n' bits from LSB of a number
Sample Input  : user@emertxe] ./print_bits
Sample Output : Enter the number: 10

                Enter number of bits: 12

                Binary form of 10: 0 0 0 0 0 0 0 0 1 0 1 0 
*/

#include <stdio.h>

//Declaration of function
int print_bits(int, int);

int main()
{
    //declaration of variables
    int num, n ;
    
    //get number from user
    printf("Enter the number: ");
    scanf("%d",&num);
    
    //get number of bits from user
    printf("\nEnter number of bits: ");
    scanf("%d",&n);

    //printing n bits from lsb of a number
    printf("\nBinary form of %d: ", num); 

    //function call
    print_bits(num, n);

    printf("\n");
    return 0;
    
 }

int print_bits(int num, int n)
{
    //declaration of variables
    int i ;

    //logic to get n bits from lsb of a number
    for( i = (n - 1) ; i >= 0 ; i-- )
    {
        printf("%d ",( num >> i ) & 1 );
    }
}

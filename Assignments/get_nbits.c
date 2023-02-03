/*
Name          : Sushant Patil
Date          : 24/01/2023
Description   : WAP to get 'n' bits of a given number
Sample Input  : user@emertxe]./get_nbits
Sample Output : Enter the number: 10

                Enter number of bits: 3

                Result = 2
*/

#include <stdio.h>

//declaration of get_nbits function 
int get_nbits(int, int);

int main()
{
    //declaration of variables
    int num, n, res ;
    
    //get number from user
    printf("Enter the number: ");
    scanf("%d", &num);

    //get number of bits from user
    printf("\nEnter number of bits:");
    scanf("%d", &n);
    
    //bit should be in between 1 to 31
    if(n>=1&&n<=32)
    {
        //calling get_nbits and storing in res variablr
        res = get_nbits(num, n);
        
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

int get_nbits(int num, int n) //called function
{
    //declaration of variable 
    int mask;

    //left shift 1, n times and substract with 1 to get mask 
    mask = ( ( 1 << n ) - 1 );

    //performing bitwise AND with num and returning the result
    return num & mask;
}

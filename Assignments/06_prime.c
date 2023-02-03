/*
Name          : Sushant Patil
Date          : 19/01/2023
Description   : WAP to print all primes using Sieve of Eratosthenes method
Sample Input  : user@emertxe] ./prime_series
Sample Output : Enter the value of 'n' : 20
                The primes less than or equal to 20 are : 2, 3, 5, 7, 11, 13, 17, 19
*/

#include<stdio.h>
int main()
{   
    //declaration of variables
    int num,i,j;

    //get number from user(for primes less than or equal to that number)
    printf("Enter the value of 'n' : ");
    scanf("%d",&num);

    //number must be grater than 1
    if( num > 1 )
    {
        //declaration of arry of size num
        int prime[ num ];

        //loading array with numbers from 2 to num
        for( i = 2 ; i <= num ; i++ )
        {
            prime[i] = i ;
        }

        
        for( i = 2 ; i*i <= num ; i++ )
        {
            if( prime[i] != 0 )
            {
                for( j= 2 ; j<= num ; j++ )
                {
                    if( prime[i]*j > num )
                    {
                        break;
                    }

                    else
                    { 
                        //making elements 0
                        prime[ prime[i] * j ] = 0;
                    }
                }
            }
        }

        //printing all primes less than or equal to entered number
        printf("The primes less than or equal to %d are : 2",num);
        for( i = 3 ; i <= num ; i++ )
        {
            //if number is not 0 then it is prime
            if( prime[i] != 0 )
            {
                printf(", %d",prime[i]);
            }
        }
    }
    else
    {
        //printing error if number is less than 1
        printf("Please enter a positive number which is > 1");
    }   
  
printf("\n");
return 0; 

}

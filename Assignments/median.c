/*
Name          : Sushant Patil
Date          : 14/01/2023
Description   : WAP to find the median of two unsorted arrays
sample input  : user@emertxe] ./median
Sample output : Enter the 'n' value for Array A: 5
                Enter the 'n' value for Array B: 4

                Enter the elements one by one for Array A: 3 2 8 5 4
                Enter the elements one by one for Array B: 12 13 7 5

                Median of array1 : 4
                Median of array2 : 9.5                                      
                Median of both arrays : 6.75 
*/

#include<stdio.h>
int main()
{
    //declaration of variables
    int i , j , m , n , temp ;
    float med1 , med2 , median ;

    //get size of Array_A from user
    printf("Enter the 'n' value for Array A: ");
    scanf("%d",&n);

    //get size of Array_B from user 
    printf("Enter the 'n' value for Array B: ");
    scanf("%d",&m);

    //declaration of Array_A and Array_B
    int Array_A[n] , Array_B[m];

    //get element of Array_A from user
    printf("\nEnter the elements one by one for Array A: ");
    for( i = 0 ; i < n ; i++ )
    {
        scanf("%d",&Array_A[i]);
    }

    //sorting Array_A in ascending order
    for( i = 0 ; i < ( n - 1 ) ; i++ )
    {
        for( j = 0 ; j < ( n - 1 - i ) ; j++ )
        {
            if( Array_A[j] > Array_A[ j + 1 ] )
                {
                    temp = Array_A[j];
                    Array_A[j] = Array_A[ j + 1 ];
                    Array_A[ j + 1 ] = temp;
                }
        }
    }



    /*----------------------->logic to get median of Array_A<-------------------*/
    //if size of Array_A ('n') is odd then median is middle number in sorted array
    if( ( n % 2 ) == 1 )
    {
        med1 = Array_A[ n / 2 ];
    }
    //if size of Array_A is even then median is average of middel two numbers in sorted array
    else
    {
        med1 = (( Array_A[ n / 2 ] + Array_A[( n / 2 ) - 1 ]) / (float) 2);
    }


    //get element of Array_B from user 
    printf("Enter the elements one by one for Array B: ");
    for ( i = 0 ; i < m ; i++ )
    {
        scanf("%d",&Array_B[i]);
    }  

    //sorting Array_B in ascending order
    for( i = 0 ; i < ( m - 1 ) ; i++ )
    {
        for( j = 0 ; j < ( m - 1 - i ) ; j++ )
        {
            if( Array_B[j] > Array_B[ j + 1 ])
            {
                temp = Array_B[j];
                Array_B[j] = Array_B[ j + 1 ];
                Array_B[ j + 1 ] = temp;
            }
        }
    }



    /*----------------------->logic to get median of Array_B<-------------------*/
    //if size of Array_B ('m') is odd then median is middle number in sorted array
    if( ( m % 2 ) == 1 )
    {
            med2 = Array_B[ m / 2 ];
    }
    //if size of Array_B is even then median is average of middel two numbers in sorted array
    else
    {
        med2 = (( Array_B[ m / 2 ] + Array_B[( m / 2 ) - 1 ]) / (float) 2 );
    }


    //printing median of Array_A
    printf("\nMedian of Array_A : %g\n",med1);

    //Printing median of size_B
    printf("Median of Array_B : %g\n",med2);



    /*------------->logic to get median of Array_A and Array_B<-------------*/
    median = ( med1 + med2 ) / (float) 2;

    //printing median of both array
    printf("Median of both arrays : %g",median);
    printf("\n");
    return 0;
}


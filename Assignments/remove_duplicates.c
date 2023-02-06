/*
Name          : Sushant Patil
Date          : 04/02/2023
Description   : WAP to remove duplicate elements in a given array
Sample Input  : user@emertxe]./remove_duplicates
Sample Output : Enter the size: 5
                Enter elements into the array: 2 1 1 1 5
                After removing duplicates: 2 1 5
*/

#include <stdio.h>

//function declaration
void fun( int arr1[], int size, int arr2[], int *new_size );

int main()
{
    //declaration of variable
    int size ;

    //getting size from user
    printf("Enter the size: ");
    scanf("%d",&size);

    //size should be greater than 1
    if( size > 1 )
    {
        //declaration of arrays and variables and initilze new_size = 0
        int arr1[size], arr2[size], new_size = 0, i ;

        //getting array elements from user and stores in array1
        printf("Enter elements into the array: ");
        for( i = 0 ; i < size ; i++ )
        {
            scanf("%d",&arr1[i]);
        }
        
        //function call
        fun( arr1, size, arr2, &new_size );

        //after removing duplicates in array1 and stores unique elements in array2,printing array2
        printf("After removing duplicates: ");
        for( i = 0 ; i < new_size ; i++ )
        {
            printf("%d ",arr2[i]);
        }
    }

    else
    {
        printf("invalid input");
    }

    printf("\n");
    return 0;
}

void fun( int arr1[], int size, int arr2[], int *new_size )
{
    //declaration of variables and initilize count=0
    int i, j, count = 0 ;

    //logic To store unique elements in array2 after removing the duplicate elements

    //initiate outer loop,to copy elements from array1 to array2
    for ( i = 0 ; i < size ; i++ ) 
    {
        //inner loop
        for ( j = 0 ; j < count ; j++ )
        {
            /* if element is already present in array2 then breaking inner loop
             and increament value of i by 1 in outer loop */
            if ( arr1[i] == arr2[j])
                break;
        }
        
        /* if element is already not present in array2 
         then storing that element in array2 and increamenting count */
        if ( j == count )
        {
            arr2[count] = arr1[i];
            count++ ;
        }
    }
    
    //updating new_size after removing duplicate
    *new_size=count;
}

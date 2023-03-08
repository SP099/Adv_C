/*
Name            : Sushant Patil
Date            : 11/02/2023
Description     : Print the values in sorted order without modifying or copying array
                  ->Read n and n no.of elements from user and store them into an array.
                  ->Run a loop for printing the elements in sorted order.
Sample execution: Test Case 1:
                  user@emertxe] ./sort
                  Enter the size : 5
                  Enter 5 elements 
                  10 1 3  8 -1
                  After sorting: -1 1 3 8 10
                  Original array values 10 1 3 8 -1

                  Test Case 2:
                  user@emertxe] ./sort
                  Enter the size : 7
                  Enter 7 elements 
                  1 3 2 5 4 7 6
                  After sorting: 1 2 3 4 5 6 7
                  Original array values 1 3 2 5 4 7 6

                  Test Case 3:
                  user@emertxe] ./sort
                  Enter the size : 4
                  Enter 4 elements 
                  -1 -2  4 3
                  After sorting: -2 -1 3 4
                  Original array values -1 -2  4 3
*/

#include <stdio.h>

//function declaration
void print_sort(int [], int);

int main()
{
    //declaration of variables
    int size, iter;

    //getting array size from user
    printf("Enter the size : ");
    scanf("%d", &size);
    
    //array size should be positive
    if( size > 0 )
    {
        //declaration of array
        int arr[size];

        //loading array elements in an array
        printf("Enter %d elements\n",size);
        for ( iter = 0; iter < size; iter++ )
        {
            scanf("%d", &arr[iter]);
        }

        //function call
        print_sort(arr, size);

        //printing original array
        printf("\nOriginal array values ");
        for ( iter = 0; iter < size; iter++ )
        {
            printf("%d ", arr[iter]);
        }
    }

    else
    {
        //printing error if size is negative
        printf("Invalid Input");
    }

    printf("\n");
    return 0;
}
void print_sort(int arr [], int size)
{
    //declaration of variables
    int i, j, large, small, sec_small;

    //logic to find largest element in original array
    large = arr[0];
    for( i = 1 ; i < size ; i++ )
    {
        if( arr[i] > large )
        {
            large = arr[i] ;
        }
    }

    //logic to find smallest element in original array
    small = arr[0];
    for( i = 1 ; i < size ; i++ )
    {
        if( arr[i] < small )
        {
            small = arr[i];
        }
    }

    //assign sec_small=large
    sec_small = large;

    //logic to print array elements in sorted order
    printf("After sorting: ");
    for( j = 0 ; j < size ; j++ )
    {
        for( i = 0 ; i < size ; i++ )
        {
            /*condition to compare array elements with small and sec_small values  in array
              if condition is true then assign sec_small=arr[i],and process repeats until end of array
            */
            if( arr[i] > small && arr[i] < sec_small )
            {
                sec_small = arr[i];
            }
        }

        ////printing array elements
        printf("%d ",small);

        //updating values of small and sec_small
        small = sec_small;
        sec_small = large;
    }
}

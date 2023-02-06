/*
Name          : Sushant Patil
Date          : 04/02/2023
Description   : WAP to find 3rd largest element in an array
Sample Input  : user@emertxe]./third_largest
Sample Output : Enter the size of the Array : 5
                Enter the elements into the array: 5 1 4 2 8
                Third largest element of the array is 4
*/

#include <stdio.h>

//function declaration
int third_largest(int *arr, int size);

int main()
{
    //declaration of variables
    int size, ret, i ;
    
    //Read size from the user
    printf("Enter the size of the Array : ");
    scanf("%d", &size);
    
    //array should have 3 elements
    if( size >= 3 )
    {
        //declaration of array
        int arr[size];
    
        //Read elements into the array
        printf("Enter the elements into the array: ");
        for(i=0;i<size;i++)
        {
            scanf("%d",&arr[i]);
        }

        //funtion call and storing result in ret variable
        ret = third_largest(arr, size);
    
        //printing third largest element
        printf("third largest element of the array is %d\n", ret);
    }

    else
    {
        printf("invalid input");
    }

    printf("\n");
    return 0;
}

int third_largest(int *arr, int size)
{
    //declaration and initilization of variables
    int i, first_max = 0, second_max = 0, third_max = 0 ;

    //use loop to compare array elements
    for( i = 0 ; i <= ( size - 1 ) ; i++ )
    {
        /*comparing first_max with array elements 
        and updating third_max with second_max,second_max with first_max 
        and first_max with arr[i] */
        if( first_max < *( arr + i ) )
        {
            third_max = second_max ;
            second_max = first_max ;
            first_max = *(arr+i) ;
        }
        
        /*comparing second_max with fisrt_max and arr[i] 
        and updating third_max with second_max,second_max with arr[i]*/
        else if( second_max < first_max && second_max < *( arr + i ) )
        {
            third_max = second_max ;
            second_max = *( arr + i ) ;
        }

        /*comparing third_max with fisrt_max,second_max and arr[i] 
        and updatind third_max with arr[i]*/
        else if ( third_max < first_max && third_max < second_max && third_max < *( arr + i ))
        {
            third_max = *( arr + i ) ;
        }
    }
    
    //returning third_max
    return third_max;
}

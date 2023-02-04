/*
Name          : Sushant Patil
Date          : 04/02/2023
Description   : WAP to find 2nd largest element in an array
Sample Input  : user@emertxe] ./sec_largest
Sample Output : Enter the size of the Array : 5
                Enter the elements into the array: 5 1 4 2 8
                Second largest element of the array is 5
*/

#include <stdio.h>

//function declaration
int sec_largest(int *arr, int size);

int main()
{
    //declaration of variables
    int size, ret, i ;
    
    //Read size from the user
    printf("Enter the size of the Array : ");
    scanf("%d", &size);
    
    //validation (atleast 2 elements must be in array)
    if( size >= 2 )
    {
        //declaration of array
        int arr[size];
    
        //Read elements into the array
        printf("Enter the elements into the array: ");
        for( i = 0 ; i < size ; i++ )
        {
            scanf("%d",&arr[i]);
        }

        //funtion call and storing result of function in variable
        ret = sec_largest(arr, size);
    
        //printing second largest element in array
        printf("Second largest element of the array is %d\n", ret);
    }

    else
    {
        printf("invalid input");
    }
}

int sec_largest(int *arr, int size)
{
    //delaration of variables
    int i, max, second_max ;

    /*if 1st array element is greater than 2nd array element then 
    storing 1st array element in max 
    and 2nd  array element in second_max */
     
    if( *( arr + 0 ) > *( arr + 1 ) )
    {
        max = *( arr + 0 );
        second_max = *( arr + 1 ) ;
    }

    /*else storing 1st array element in second_max
    and 2nd array element in max */
    else
    {
        max = *( arr + 1 ) ;
        second_max = *( arr + 0 ) ;
    }

    /*use loop,comparing remaining array elements and 
    updating max and second_max,this process repeats till the 
    end of the array */
    for( i = 2 ; i <= (size - 1) ; i++ )
    {
        if( *( arr + i ) > max )
        {
            second_max = max ;
            max = *( arr + i ) ;
        }

        else
        {
            if( *( arr + i ) > second_max )
                second_max = *( arr + i ) ;
        }
    }
      
    //returning second lagest element to main function
    return second_max;
}

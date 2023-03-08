/*
Name            : Sushant Patil
date            : 01/03/2023
Description     : Variance calculation with dynamic arrays
                  ->In probability theory and statistics, variance measures how far a set of numbers is spread out. A variance of zero indicates that all the values are identical. Variance is always non-negative: a small variance indicates that the data points tend to be very close to the mean (expected value) and hence to each other, while a high variance indicates that the data points are very spread out around the mean and from each other.
                   Example:
                   x(input)                D = X - Mean                   D2
                   9                          -11                                   121
                   12                        -8                                     64
                   15                        -5                                     25
                   18                        -2                                     4
                   20                         0                                     0
                   22                         2                                     4
                   23                         3                                     9
                   24                         4                                     16
                   26                         6                                     36
                   31                         11                                   121
                   Sum = 200                                                  Sum = 400
                   Mean = (sum of x) / size
                   where : size = Number of items in the input
                   Formula to calculate the variance:
                   sigma = (sum of D2 ) / size
Sample Execution:  Test Case 1:
                   user@emertxe] ./variance
                   Enter the no.of elements : 10

                   Enter the 10 elements:
                   [0] -> 9
                   [1] -> 12
                   [2] -> 15
                   [3] -> 18
                   [4] -> 20
                   [5] -> 22
                   [6] -> 23
                   [7] -> 24
                   [8] -> 26
                   [9] -> 31
                   Variance is 40.000000
               
 */
#include <stdio.h>
#include<stdlib.h>

//declaration of function
float variance(int *, int);

int main()
{
    //declaration of ponter and variables
    int *arr, i, size;
    float var;

    //getting number of elements from user
    printf("Enter the no.of elements : ");
    scanf("%d", &size);

    //dynamically allocating memory for an integer array of size 'size'
    arr = (int *)calloc(size, sizeof(int));

    //condition to checks if the memory allocation was successful or not
    if (arr == NULL) 
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    else
    {
        /*
          code snippet prompts the user to input a number of elements 
          specified by the variable "size", and then reads those elements 
          into an integer array "arr" using a loop
        */
        printf("Enter the %d elements:\n",size);
        for( i = 0 ; i < size ; i++ )
        {
            printf("[%d] -> ", i);
            scanf("%d",&arr[i]);
        }
    }

    //calls the function "variance(arr, size)" and assigns the returned value to the variable "var".
    var = variance(arr,size);

    //prints out the result of the variance calculation
    printf("Variance is %f",var);

    /*
      the "free(arr)" function is called to free 
      the dynamically allocated memory used by the "arr" array.
    */
    free(arr);
    printf("\n");
    return 0;
}

//function definition
float variance(int *arr, int size)
{
    /*initializes two integer variables "sum" and "dsum" to 0 
      and declares two more integer variables "i" and "D"
      and a float variable "mean".*/
    int sum = 0, i, dsum = 0, D;
    float mean;

    /*the loop is used to calculate the sum of all the elements in the "arr" array, 
      which is stored in the "sum" variable.*/
    for( i = 0 ; i < size ; i++ )
    {
        sum += *(arr+i);
    }

    /*After the loop, the calculates the mean of all the elements 
      in the "arr" array by dividing the sum of all the elements by 
      the number of elements in the array, and stores the result 
      in the "mean" variable.*/
    mean = (float) sum / size;

    /*loop calculates the variance of all the elements in the "arr" array. 
      It calculates the difference between the current element and 
      the mean, squares it, and adds the result to the "dsum" variable. 
      The loop continues until it has visited all the elements in the array.*/
    for( i = 0 ; i < size ; i++ )
    {
        D = *(arr+i) - mean;
        D = D * D;
        dsum += D;
    }

    /*After the loop, the calculates the variance by dividing 
      the sum of squared differences by the number of elements 
      in the array, and returns the result as a float*/
    return (float)dsum / size;
}

/*
name                : Sushant Patil
date                : 01/03/2023
Description         : WAP to implement fragments using Array of Pointers
sample execution    : 
                      Test case 1:
                      user@emertxe] ./fragmentsEnter
                      Enter no.of rows : 3
                      Enter no of columns in row[0] : 4
                      Enter no of columns in row[1] : 3
                      Enter no of columns in row[2] : 5
                      Enter 4 values for row[0] : 1 2 3 4
                      Enter 3 values for row[1] : 2 5 9
                      Enter 5 values for row[2] : 1 3 2 4 1

                      Before sorting output is:
                      1.000000 2.000000 3.000000 4.000000 2.500000
                      2.000000 5.000000 9.000000 5.333333
                      1.000000 3.000000 2.000000 4.000000 1.000000 2.200000

                      After sorting output is:
                      1.000000 3.000000 2.000000 4.000000 1.000000 2.200000
                      1.000000 2.000000 3.000000 4.000000 2.500000
                      2.000000 5.000000 9.000000 5.333333
*/
#include <stdio.h>
#include <stdlib.h>

//function declaration
int fragments(int, int [], float *[]);

int main() 
{
    //declaration of variables
    int i, j, r;

    //getting number of rows from user
    printf("Enter no.of rows: ");
    scanf("%d", &r);
    
    /*declares an array pointers .
      declares an integer array named c with a size of r.
      The c array will be used to store the number of columns for each row 
      in the two-dimensional array that will be dynamically allocated later 
      in the code.
    */
    float* arr[r];
    int c[r];


    /*loop initializes the dynamically allocated two-dimensional array of floats created
      For each row in the array, the loop prompts the user to enter the number of columns 
      for that row with printf("Enter no of columns in row[%d]: ", i); 
      and reads in the input with scanf("%d", &c[i]);.
    */
    for (i = 0; i < r; i++) 
    {
        printf("Enter no of columns in row[%d]: ", i);
        scanf("%d", &c[i]);

        /*dynamically allocates memory for the row's array of floats using 
          arr[i] = malloc((c[i] + 1) * sizeof(float));. 
          Here, (c[i] + 1) * sizeof(float) calculates the number of bytes 
          needed to store a row of floats, 
          where c[i] represents the number of columns in row i.
        */
        arr[i] = malloc((c[i] + 1) * sizeof(float));


        /*condition to checks if the memory allocation was successful. 
         If the allocation fails, the code prints an error message and terminates the program 
         with a return value of 1.
        */
        if (arr[i] == NULL) 
        {
            printf("Error: could not allocate memory\n");
            return 1;
        }
    }

    printf("\n");


    /*outer loop iterates over each row of the array with for (i = 0; i < r; i++). 
      For each row, the code prompts the user to enter c[i] values for that row with 
      printf("Enter %d values for row[%d]: ", c[i], i);.
      The inner loop iterates over each column in the row with for (j = 0; j < c[i]; j++).
      For each column, the code reads in a float value from the user with 
      scanf("%f", &arr[i][j]); and stores it in the corresponding element of the 
      two-dimensional array.      
    */
    for (i = 0; i < r; i++) 
    {
        printf("Enter %d values for row[%d]: ", c[i], i);
        for (j = 0; j < c[i]; j++) 
        {
            scanf("%f", &arr[i][j]);
        }
    }
    
    //function call
    fragments(r, c, arr);
    
    /*loop  iterates over each row of the array and frees
      the memory allocated for that row with free(arr[i]);.*/
    for (i = 0; i < r; i++) 
    {
        free(arr[i]);
    }

    //indicate successful execution.
    return 0;
}

//function definition
int fragments(int r, int c[], float* arr[]) 
{
    //declaration of variables
    int i, j, sum;
    float *temp;
    float avg;

    /*outer loop for (i = 0; i < r; i++) iterates over each row of the array. 
      For each row, the code initializes a variable sum to zero and then iterates 
      over each column in the row with for (j = 0; j < c[i]; j++). 
      For each column, the code adds the value in that column to the sum with sum += arr[i][j];.
      After adding all the values in the row, the code calculates the average value 
      by dividing sum by the number of columns in the row with avg = (float) sum / c[i];. 
      The resulting average value is then stored in the last element of that row with arr[i][c[i]] = avg;.
    */
    for (i = 0; i < r; i++) 
    {
        sum = 0;
        for (j = 0; j < c[i]; j++) 
        {
            sum += arr[i][j];
        }
        avg = (float) sum / c[i];
        arr[i][c[i]] = avg;
    }


    //begore sorting the array arr
    printf("\nBefore sorting output is:\n");
    for (i = 0; i < r; i++) 
    {
        for (j = 0; j < c[i] + 1; j++) 
        {
            printf("%f ", arr[i][j]);
        }
        printf("\n");
    }


    //swapping
    for (i = 0; i < r - 1; i++) 
    {
        for (j = 0; j < r - i - 1; j++) 
        {
            if (arr[j][c[j]] > arr[j+1][c[j+1]]) 
            {
                // Swap rows j and j+1
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

                // Swap column counts
                int temp_c = c[j];
                c[j] = c[j+1];
                c[j+1] = temp_c;
            }
        }
    }

    //after sorting
    printf("\nAfter sorting output is:\n");
    for (i = 0; i < r; i++) 
    {
        for (j = 0; j < c[i] + 1; j++) 
        {
            printf("%f ", arr[i][j]);
        }
        printf("\n");
    }
}

/*
Name            : Sushant Patil
date            : 05/03/2023
Description     : Read n & n person names of maxlen 20. Sort and print the names
                  Read the N name from the user
                  Sort it in alphabetical order
                  Use 1st dynamic and 2nd static. Char (*name)[20]
                  No.of names should be dynamic and no.of characters should be static.
                  Allocate the memory dynamically for no.of names.
Sample Execution: Test Case 1:
                  user@emertxe] ./sort

                  Enter the size: 5

                  Enter the 5 names of length max 20 characters in each
                  [0] -> Delhi
                  [1] -> Agra
                  [2] -> Kolkata
                  [3] -> Bengaluru
                  [4] -> Chennai

                  The sorted names are:
                  Agra
                  Bengaluru
                  Chennai
                  Delhi
                  Kolkata            
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

//declaration of function
void sort_names(char (*names)[20], int n);

int main()
{
    //declaration of variable
    int n;

    //getting input from user
    printf("Enter the size: ");
    scanf("%d", &n);

    // dynamically allocating memory for an array of n strings, each with a maximum length of 20 characters
    char (*names)[20] = malloc(sizeof(char[20]) * n); 

    //This checks if the memory allocation was successful. If the allocation failed, the malloc() function returns a NULL pointer, and the condition is true
    if (names == NULL) 
    {
        printf("Failed to allocate memory for names\n");
        return 1;
    }

    //printing a message
    printf("Enter the %d names of length max 20 characters in each\n",n);

    //getting input from user
    for (int i = 0; i < n; i++) 
    {   
        printf("[%d] -> ",i);
        scanf("%s", names[i]);
    }

    // clear the output buffer of stdout
    __fpurge(stdout); 

    // calling function to sort the names
    sort_names(names, n); 

    printf("The sorted names are:\n");
    for (int i = 0; i < n; i++) 
    {
        printf("%s\n", names[i]); // print the sorted names
    }

    // free the allocated memory
    free(names); 
    return 0;
}


//definition of the sort_names()
void sort_names(char (*names)[20], int n)
{
    // use bubble sort algorithm to sort the names

    // iterates n-1 times to perform n-1 passes over the array of names.
    for (int i = 0; i < n - 1; i++) 
    {
        //iterates over the unsorted part of the array of names in each pass.
        for (int j = 0; j < n - i - 1; j++) 
        {
            /*
              This compares two adjacent names in the array using the strcmp() function. If the first name is 
               greater than the second name, the condition is true.
            */
            if (strcmp(names[j], names[j + 1]) > 0) 
            {
                //declaration a temporary character array of length 20 to store a name during the swapping process.
                char temp[20];

                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }
}

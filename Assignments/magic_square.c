/*
Name                 : Sushant Patil
Date                 : 03/03/2023
Description          : WAP to generate a n*n magic square

                       In recreational mathematics, a magic square is an arrangement of distinct numbers (i.e. each number is used once), usually integers, in a square grid, where the numbers in each row, and in each column, and the numbers in the main and secondary diagonals, all add up to the same number
                       A magic square has the same number of rows as it has columns, and in conventional math notation, "n" stands for the number of rows (and columns) it has. Thus, a magic square always contains n2 numbers, and its size (the number of rows [and columns] it has) is described as being "of order n".
                       Example: if n = 3, the magic square
                       8   1   6     
                       3   5   7     
                       4   9   2     

                       Read an odd number n from user.
                       Do error checking.
                       Check the number is odd or not.
                       If not, continue step a.
                       Create an n X n matrix.
                       Insert 1 to (n * n) numbers into matrix.
                       Arrange the numbers in such a way that, adding the numbers in any direction, either row wise column wise or diagonal wise, should result in same answer.
                       Allocate the memory dynamically using calloc.
Sample execution     : -
                       Test Case 1:
                       user@emertxe] ./magic_square
                       Enter a number: 3
                       8      1      6
                       3      5      7
                       4      9      2

                       Test Case 2:
                       Enter a number: 6
                       Error : Please enter only positive values
*/
#include <stdio.h>
#include <stdlib.h>

void magic_square(int **, int);

int main()
{
    //declares integer pointer to pointer and variables n and i
    int **ptr, n, i;

    //getting number from user
    printf("Enter a number: ");
    scanf("%d", &n);

    /*If the input number is positive and odd, the code dynamically allocates 
      memory for a two-dimensional array of size n x n using calloc(). 
      If the allocation fails, the code prints an error message and returns 1.
    */
    if(n > 0 && n % 2 != 0)
    {
        ptr = calloc(sizeof(int *), n);
        if(ptr == NULL)
        {
            printf("Unable to allocate memory\n");
            return 1;
        }
        for(i = 0; i < n; i++)
        {
            ptr[i] = calloc(sizeof(int), n);
            if(ptr[i] == NULL)
            {
                printf("Unable to allocate memory\n");
                return 1;
            }
        }

        //function call
        magic_square(ptr, n);

        //freeing the memory that was allocated earlier for the 2D array.
        for(i = 0; i < n; i++)
        {
            free(ptr[i]);
        }
        free(ptr);
    }
    else
    {
        // If the input value for n was not valid (i.e., not an odd positive integer), an error message is printed.
        printf("Error : Please enter only positive odd numbers");
    }

    //indicate successful completion.
    return 0;
}

void magic_square(int **ptr, int n)
{
    //declaration of variables
    int i, j, ii, jj, num;

    //nested loop that initializes all the elements of the two-dimensional array pointed to by ptr to 0
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            ptr[i][j] = 0;
        } 
    }

    //i and j are initialized to the first row and middle column of the magic square, respectively, while num is set to 1, the starting value for the magic square.
    i = 0;
    j = n/2;
    num = 1;

    /*
    ->The loop continues as long as the value of 'num' is less than 
      or equal to the total number of cells in the magic square (n*n).
    ->For each iteration, the current value of 'num' is assigned to the cell at the 
      current position (i,j) in the magic square. The variables 'ii' and 'jj' 
      are then used to compute the position of the next cell to be assigned.
    ->If the cell at the next position is already assigned (i.e., not equal to zero), 
      the position is changed by moving down one row (i.e., adding 1 to 'i' and taking the result modulo n to wrap around to the first row if needed). Otherwise, 
      the position is changed by moving up one row and to the right one column (i.e., subtracting 1 from 
      'i' and adding 1 to 'j', and taking the results modulo n to wrap around to the last 
      row or first column if needed).
    */
    while(num <= n*n)
    {
        ptr[i][j] = num;
        num++;
        ii = (i - 1 + n) % n;
        jj = (j + 1 ) % n;
        if(ptr[ii][jj] == 0)
        {
            i = ii;
            j = jj;
        }
        else
        {
            i = (i + 1) % n;
        }
    }

    //printing the output
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d\t", ptr[i][j]);
        } 
        printf("\n");
    }
}

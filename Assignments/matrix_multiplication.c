/*
Name            : Sushant Patil
date            : 04/03/2023
Description     : WAP to find the product of given matrix.
                  Read no.of rows and columns for 2 arrays from user and allocate the memory dynamically using malloc or calloc (Assume Matrix A and Matrix B).
                  Read the Matrix A and B from user.
                  Find the product for matrix A with matrix B amd store the result in Matrix R.
                  Let say Name of the matrix is A and no. Of rows = columns = 3.
                  Matrix A
                  1    2    3     
                  1    2    3    
                  1    2    3    

                  Matrix B
                  1    1    1     
                  2    2    2
                  3    3    3
    

                  Final Result :
                  Result = A * B
                     1     2      3                 1         1      1
                  R= 1     2      3        x        2         2      2
                     1     2      3                 3         3      3
                  R1 = [(1 * 1) + (2 * 2) + (3 * 3)  (1 * 1) + (2 * 2) + (3 * 3)   (1 * 1) + (2* 2) + (3 * 3)]

                  Result matrix is
                  14   14  14
                  14   14  14
                  14   14  14    
        
Sample Execution: Test case1:
                  user@emertxe] ./transpose_product
                  Enter number of rows : 3
                  Enter number of columns : 3
                  Enter values for 3 x 3 matrix :
                  1      2      3
                  1      2      3
                  1      2      3
                  Enter number of rows : 3
                  Enter number of columns : 3
                  Enter values for 3 x 3 matrix :

                  1      1     1
                  2      2     2
                  3      3     3
                  Product of two matrix :
                  14      14      14
                  14      14      14
                  14      14      14

                  Test case 2:
                  user@emertxe] ./transpose_product
                  Enter number of rows : 3
                  Enter number of columns : 3
                  Enter values for 3 x 3 matrix :
                  1      2      3
                  1      2      3
                  1      2      3
                  Enter number of rows : 2
                  Enter number of columns : 3
                  Matrix multiplication is not possible
               
 */
#include <stdio.h>
#include <stdlib.h>

//function declaration
int matrix_mul(int **, int, int, int **, int, int, int **, int, int);

int main()
{
    //declaration of  pointers to pointers of integers  variables 
    int **mat_a, **mat_b, **result;

    //declaration of variables
    int r_a, c_a, r_b, c_b, r_r, c_r, i, j;

    //getting number of rows from user for matrix A
    printf("Enter number of rows: ");
    scanf("%d", &r_a);
 
    //getting number of col from user for matrix A
    printf("Enter number of columns: ");
    scanf("%d", &c_a);

    //allocation of memory for a 2D array(for matrix A) using dynamic memory allocation
    mat_a = calloc(r_a, sizeof(int *));
    if (mat_a == NULL)
    {
        //If the memory allocation fails, the code prints an error message and returns 1 indicating failure.
        fprintf(stderr,"Memory allocation failed\n");
        return 1;
    }
    for (i = 0; i < r_a; i++)
    {
        mat_a[i] = malloc(c_a * sizeof(int));
        if (mat_a[i] == NULL)
        {
            //If the memory allocation fails, the code prints an error message and returns 1 indicating failure.
            fprintf(stderr,"Memory allocation failed\n");
            return 1;
        }
    }

    //getting input values for a matrix A of size r_a x c_a.
    printf("Enter values for %d x %d matrix: \n", r_a, c_a);
    for (i = 0; i < r_a; i++)
    {
        for (j = 0; j < c_a; j++)
        {
            scanf("%d", &mat_a[i][j]);
        }
    }
    
    ////getting number of rows from user for matrix B
    printf("Enter number of rows: ");
    scanf("%d", &r_b);

    //getting number of col from user for matrix A
    printf("Enter number of columns: ");
    scanf("%d", &c_b);

    /*checks if matrix multiplication is possible by comparing the number of columns of matrix A 
    with the number of rows of matrix B. If they are equal, matrix multiplication is possible */
    if (c_a == r_b)
    {
        //allocation of memory for a 2D array(for matrix B) using dynamic memory allocation
        mat_b = calloc(r_b, sizeof(int *));
        if (mat_b == NULL)
        {
            //If the memory allocation fails, the code prints an error message and returns 1 indicating failure.
            fprintf(stderr,"Memory allocation failed\n");
            return 1;
        }
        for (i = 0; i < r_b; i++)
        {
            mat_b[i] = malloc(c_b * sizeof(int));
            if (mat_b[i] == NULL)
            {   
                //If the memory allocation fails, the code prints an error message and returns 1 indicating failure.
                fprintf(stderr,"Memory allocation failed\n");
                return 1;
            }
        }
        
        //getting input values for a matrix B of size r_b x c_b.
        printf("Enter values for %d x %d matrix: \n", r_b, c_b);
        for (i = 0; i < r_b; i++)
        {
            for (j = 0; j < c_b; j++)
            {
                scanf("%d", &mat_b[i][j]);
            }
        }

        //assigning row of matrix A to r_r and assigning columns of matrix B to c_r
        r_r = r_a;
        c_r = c_b;
         
        //function calling
        matrix_mul(mat_a, r_a, c_a, mat_b, r_b, c_b, result, r_r, c_r);

        //deallocating the memory that was allocated for the  matrix mat_b after it has been used.
        for (i = 0; i < r_b; i++)
        {
            free(mat_b[i]);
        }
        free(mat_b);
  
    }

    else
    {   
        //If matrix A's col and matrix B's row are not equal, matrix multiplication is not possible
        printf("Matrix multiplication is not possible\n");
    }

    //deallocating the memory that was allocated for the  matrix mat_a after it has been used.
    for (i = 0; i < r_a; i++)
    {
        free(mat_a[i]);
    }
    free(mat_a);

    return 0;
}

//function definition
int matrix_mul(int **mat_a, int r_a, int c_a, int **mat_b, int r_b, int c_b, int **result, int r_r, int c_r)
{

    //declaration of variables
    int i, j, k;
   
    //allocation of memory for a 2D array(for resultant matrix) using dynamic memory allocation
    result = calloc(r_r, sizeof(int *));
    if (result == NULL)
    {
        //If the memory allocation fails, the code prints an error message and returns 1 indicating failure.
        fprintf(stderr,"Memory allocation failed\n");
        return 1;
    }
    for (i = 0; i < r_r; i++)
    {
        result[i] = malloc(c_r * sizeof(int));
        if (result[i] == NULL)
        {
            //If the memory allocation fails, the code prints an error message and returns 1 indicating failure.
            fprintf(stderr,"Memory allocation failed\n");
            return 1;
        }
    }
   
   //performs the matrix multiplication of mat_a and mat_b and stores the result in the matrix result

   /*
    ->outermost loop iterates over the rows of the first matrix, mat_a, and the inner loop iterates over the columns of the second matrix, mat_b.
    ->result matrix is initialized to 0 in the innermost loop, which ensures that the previous result is not carried over to the next iteration.
    -> innermost loop calculates the  product of the i-th row of mat_a with the j-th column of mat_b, which is the sum of the product of corresponding elements of the two vectors.
    -> result of the dot product is stored in the i-th row and j-th column of result.
    -> loop terminates when all rows and columns of the matrices have been processed.
   */
   for( i = 0 ; i < r_a ; i++ )
   {
       for( j = 0 ; j < c_b ; j++ )
       {
           result[i][j] = 0;
           for( k = 0 ; k < c_a ; k++ )
           {
               result[i][j] += (mat_a[i][k] * mat_b[k][j]);
           }
       }
   }

   //printing Product of two matrix
   printf("Product of two matrix : \n"); 
	for ( i = 0 ; i < r_r ; i++ )
	{
		for ( j = 0 ; j < c_r ; j++ )
		{
			printf("%d\t", result[i][j]);
		}
	    printf("\n");
	}

    //deallocating the memory that was allocated for the result matrix result after it has been used.
    for (i = 0; i < r_r; i++)
    {
        free(result[i]);
    }
    free(result);
    return 1;
}

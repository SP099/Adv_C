/*
Name            : Sushant Patil
date            : 05/03/2023
Description     : WAP to define a macro SIZEOF(x), without using sizeof operator
                  ->Treat &x and &x + 1 as characters address.
                  ->Both addresses difference will be sizeof x 
Sample Execution: Test Case 1:
                  user@emertxe] ./sizeof
                  Size of int : 4 bytes
                  Size of char : 1 byte
                  Size of float : 4 bytes
                  Size of double : 8 bytes
                  Size of unsigned int : 4 bytes
                  Size of long int : 8 bytes
                  ----
                  ----
                  ----              
 */
#include <stdio.h>
#include <stdlib.h>

// Define a macro called SIZE that takes an argument x and calculates its size
#define SIZE(x) ((char *)(&x + 1) - (char *)&x)

int main()
{
    // Declare variables of various data types
    int x;
    char y;
    float a;
    double b;
    short int c;
    long int d;
    unsigned int e;
    long long f;
    unsigned short g;
    unsigned long h;
    unsigned long long i;
    long j;
    
    // Print the size of each variable using the SIZE macro
    printf("size of int: %zu bytes\n", SIZE(x));
    printf("size of char: %zu bytes\n", SIZE(y));
    printf("size of float: %zu bytes\n", SIZE(a));
    printf("size of double: %zu bytes\n", SIZE(b));
    printf("size of short int: %zu bytes\n", SIZE(c));
    printf("size of long int: %zu bytes\n", SIZE(d));
    printf("size of unsigned int: %zu bytes\n", SIZE(e));
    printf("size of long long: %zu bytes\n", SIZE(f));
    printf("size of unsigned short : %zu bytes\n", SIZE(g));
    printf("size of unsigned long: %zu bytes\n", SIZE(h));
    printf("size of unsigned long long : %zu bytes\n", SIZE(i));
    printf("size of long: %zu bytes\n", SIZE(j));
    
    return 0;
}

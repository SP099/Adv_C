/*
Name            : Sushant Patil
date            : 04/03/2023
Description     : WAP to convert Little Endian data to Big Endian
                  Check the memory assigning order of variables for checking whether little endian or big endian machine
                  Little Endian:
                  --------------
                  Say int i = 10; gets stored in memory at
                  1000
                  1001
                  1002
                  1003
                  where 1000 contains LSB of i and 1003 contains MSB of i
                  char *ptr = &i; the ptr will now contain 1000

                  Big Endian:
                  -----------
                  Say int i = 10; gets stored in memory at
                  1000
                  1001
                  1002
                  1003
                  where 1000 contains MSB of i and 1003 contains LSB of i
                  char *ptr = &i; the ptr will now contain 1000

                  Read 2 byte or 4 byte data according to given size(short or Int). Swap the bytes and convert the given data to Big Endian
Sample Execution: Test Case 1:
                  user@emertxe] ./endianness
                  Enter the size: 2
                  Enter any number in Hexadecimal: ABCD
                  After conversion CDAB
                  Test Case 2:
                  Enter the size: 4
                  Enter any number in Hexadecimal: 12345678
                  After conversion 78563412            
 */

#include <stdio.h>

//declaration of function
void convert_to_big_endian(char *, int);
void swap(char *, char *);

int main() 
{
    //declaration of variable
    int size;

    //getting size from user
    printf("Enter the size: ");
    scanf("%d", &size);

    //checking if the value of the variable size is equal to 2
    if(size == 2) 
    {
        //declaration of variable
        short num;

        //getting hexadecimal number from user
        printf("Enter any number in Hexadecimal: ");
        scanf("%hx", &num);

        /*calling a function named convert_to_big_endian() with two arguments i.e
          ->'(char *)&num':This is a typecast of the memory address of the 
            num variable to a char pointer.
          ->size:variable that specifies the size of the data in bytes.In this case, the size is 2 bytes
        */ 
        convert_to_big_endian((char *)&num, size);

        //printing result of conversion
        printf("After conversion %hX\n", num);
    } 

    //execute following code if the variable "size" is equal to 4.
    else if(size == 4) 
    {
        //declaration of variable
        int num;

        //getting number in hexadecimal format
        printf("Enter any number in Hexadecimal: ");
        scanf("%x", &num);

        /*calling a function named convert_to_big_endian() with two arguments i.e
          ->'(char *)&num':This is a typecast of the memory address of the 
            num variable to a char pointer.
          ->size:variable that specifies the size of the data in bytes.In this case, the size is 4 bytes
        */
        convert_to_big_endian((char *)&num, size);

        //printing result of conversion
        printf("After conversion %X\n", num);
    } 
    else 
    {
        //printing error msg
        printf("Invalid size.\n");
    }

    return 0;
}


//function definition
void convert_to_big_endian(char *num, int size) 
{
    //declaration of variable
    int i;

    // Loop through the first half of the input number
    for(i = 0; i < size / 2; i++) 
    {
        // Swap the i-th byte from the beginning with the i-th byte from the end
        swap(&num[i], &num[size - i - 1]);
    }
}

//function definition
void swap(char *num1, char *num2) 
{
    // Declare a temporary char variable called "temp" and set it to the value pointed to by num1
    char temp = *num1;

    // Set the value pointed to by num1 to the value pointed to by num2
         *num1 = *num2;

    // Set the value pointed to by num2 to the value of "temp"    
         *num2 = temp;
}

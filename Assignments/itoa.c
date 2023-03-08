 /*
 Name          : Sushant Patil
 date          : 19/2/2023
 Description   : WAP to implement itoa function
                 ->int itoa(int n, char *s)
                    Convert integer n into a string and store the string in s.
                 ->Return the length of string from the function. 
 sample input  : Enter the number : +1234
 sample output : Integer to string is 1234
 */

#include <stdio.h>

//function declaration
int itoa(int num, char str[]);

int main() 
{
    //dclaration of variables
    int num, len;

    //declaration of string
    char str[10];

    //getting number from user
    printf("Enter the number: ");
    scanf("%d", &num);

    //calling itoa function and storing reult in len variable
    len = itoa(num, str);

    //printing output
    printf("Integer to string is %s\n", str);
    return 0;
}


//function definition
int itoa(int num, char str[]) {
    int i = 0, sign = 1, len = 0;

    // Check if the number is negative
    if (num < 0)
    {
        sign = -1;
        num = -num;
    }

    // fetching digit of the number and store in str
    do
    {
        str[i++] = num % 10 + '0';
        num /= 10;
    } while (num > 0);

    //  add a '-' sign If number was negative
    if (sign == -1) 
    {
        str[i++] = '-';
    }
    //assign null to  str
    str[i] = '\0';
    len = i;

    // Reverse the string
    int j = 0, temp;
    i--;
    {
        for (; j < i; j++, i--)
        {
            temp = str[i];
            str[i] = str[j];
            str[j] = temp;
        }
    }
    //returning len to main
    return len;
}

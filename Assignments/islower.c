/*
Name          : Sushant Patil
Date          : 29/01/2023
Description   : WAP to implement your own islower() function
Sample Input  : user@emertxe] ./c_type_lib
Sample Output : Enter the character: a
                Entered character is lower case alphabet
*/

#include <stdio.h>

//declaration of funtion
int my_islower(int);

int main()
{
    //declaration of variables
    char ch;
    int ret;
    
    //getting character from user
    printf("Enter the character:");
    scanf("%c", &ch);
    
    //getting result of called my_islower function and stores in variable
    ret = my_islower(ch);

    //condition to check entered character is lowercase alphabet or not
    if(ret)
    {
        //if return value is non zero then printing  entered character is lowercase alphabet
        printf("Entered character is lower case alphabet");
    }
    else
    {
        //if return value is 0 then printing  entered character is not lowercase alphabet
        printf("Entered character is not lower case alphabet");
    }

    printf("\n");
    return 0;
}

int my_islower(int ch)
{   
    //condition for lowercase  alphabets(from 'a' to 'z'),if true then returning non zero value
    if( ch >= 'a' && ch <= 'z' )
    {
        return 1;
    }

    //if character is not lowercase letter then returning 0
    else
    {
        return 0;
    }
}

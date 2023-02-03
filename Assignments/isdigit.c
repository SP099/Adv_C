/*
Name          : Sushant Patil
Date          : 29/01/2023
Description   : WAP to implement your own isxdigit() function
Sample Input  : user@emertxe] ./is_xdigit
Sample Output : Enter the character:3
                Entered character is  an hexadecimal digit
*/

#include <stdio.h>

//declaration of function
int is_xdigit(int);

int main()
{
    //declaration of variables
    char ch;
    int ret;
    
    //getting character from user
    printf("Enter the character:");
    scanf("%c", &ch);
    
    //getting result of called is_xdigit function and stores in variable
    ret = is_xdigit(ch);

    //condition to check entered character is an hexadecimal digit or not
    if(ret)
    {   
        //if return value is non zero then printing  entered character is  an hexadecimal digit
        printf("Entered character is an hexadecimal digit");
    }
    else
    {
        //if return value is zero then printing entered character is not an hexadecimal digit
        printf("Entered character is not an hexadecimal digit");
    }

    printf("\n");
    return 0;
}

int is_xdigit(int ch)
{   
    //condition for small alphabets(from 'a' to 'f'),if true returning non zero value
    if( ch >= 'a' && ch <= 'f' )
    {
        return 1;
    }

    //condition for capital alphabets(from 'A' to 'F'),if true returning non zero value
    else if( ch >= 'A' && ch <= 'F' )
    {
        return 1;
    }

    //conditon for digits(from '0' to '9'),if true returning non zero value
    else if( ch >= '0' && ch <= '9' )
    {
        return 1;
    }

    //if character is not isxdigit then returning 0
    else
    {
        return 0;
    }
}

/*
Name          : Sushant Patil
Date          : 29/01/2023
Description   : WAP to implement your own isalnum() function
Sample Input  : user@emertxe] ./c_type_lib
Sample Output : Enter the character: a
                The character 'a' is an alnum character.
*/

#include <stdio.h>

//declaration of function
int my_isalnum(int);

int main()
{
    //declaration of variables
    char ch;
    int ret;
    
    //getting character from user
    printf("Enter the character:");
    scanf("%c", &ch);
    
    //getting result of called my_isalnum function and stores in variable
    ret = my_isalnum(ch);

    //condition to check entered character is isalnum or not
    if(ret)
    {   
        //if return value is non zero then printing character is alnum character
        printf("The character '%c' is an alnum character.",ch);
    }
    else
    {
        //if return value is zero then printing character is not alnum character
        printf("The character '%c' is not an alnum character.",ch);
    }

    printf("\n");
    return 0;
}

int my_isalnum(int ch)
{   
    //condition for small alphabets,if true then returning non zero value
    if( ch >= 'a' && ch <= 'z' )
    {
        return 1;
    }

    //condition for capital alphabets,if true then returning non zero value
    else if( ch >= 'A' && ch <= 'Z' )
    {
        return 1;
    }

    //conditon for digits,if true then returning non zero value
    else if( ch >= '0' && ch <= '9' )
    {
        return 1;
    }

    //if character is not isalnum then returning 0
    else
    {
        return 0;
    }
}

/*
Name          : Sushant Patil
Date          : 29/01/2023
Description   : WAP to implement your own ispunct() function
Sample Input  : user@emertxe] ./c_type_lib
Sample Output : Enter the character:$
                Entered character is punctuation character
*/

#include <stdio.h>

//declaration of funtion
int my_ispunct(int);

int main()
{
    //declaration of variables
    char ch;
    int ret;
    
    //getting character from user
    printf("Enter the character:");
    scanf("%c", &ch);
    
    //getting result of called my_ispunct function and stores in variable
    ret = my_ispunct(ch);

     //condition to check entered character is punctuation character or not
    if(ret)
    {
        //if return value is non zero then printing  entered character is punctuation character
        printf("Entered character is punctuation character");
    }
    else
    {
        //if return value is zero then printing  entered character is not punctuation character
        printf("Entered character is not punctuation character");
    }
    
    printf("\n");
    return 0;
}

int my_ispunct(int ch)
{
    //validating entered charater is punctuator or not,if true then returning non zero value else returning 0
    return ( ch >= 33 && ch <= 47) || ( ch >= 58 && ch <= 64 ) || ( ch >= 91 && ch <= 96 )||( ch >= 123 && ch <= 126 )?1:0;
  
}

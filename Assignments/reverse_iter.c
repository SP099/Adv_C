 /*
 Name          : Sushant Patil
 date          : 19/2/2023
 Description   : WAP to reverse the given string using iterative method
                 ->Read a string from user.
                 ->Implement using loops.
                 ->Do not print character by character.
 sample input  : Enter any string : hello
 sample output : Reversed string is : olleh
 */

#include <stdio.h>
#include<string.h>

//fuction declaraction
void reverse_iterative(char str[]);

int main()
{
    //initalisation of string
    char str[30];
    
    //getting string from user
    printf("Enter any string : ");
    scanf("%[^\n]", str);
     
    //fuction call
    reverse_iterative(str);
    
    //printing the reversed  string
    printf("Reversed string is %s\n", str);
    return 0;
}

void reverse_iterative(char *str)
{
    
    //initialization of variables 
    int i, j, temp, len;
    
    // using builtin strlen function to find length and stores in variable len
    len = strlen(str);
    
    //logic to reverse string
    for (i = 0, j = (len - 1) ; i < j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}


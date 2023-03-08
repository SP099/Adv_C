 /*
 Name          : Sushant Patil
 date          : 19/2/2023
 Description   : WAP to replace each string of one or more blanks by a single blank
                 ->Input string:
                   Pointers         are      sharp           knives.
                 ->Output String:
                   Pointers are sharp knives.
                 ->Blank can be spaces or tabs. (replace with single space).
 sample input  : Pointers     are               sharp     knives.
 sample output : Pointers are sharp knives.
 */
#include <stdio.h>

//declaration of function
void replace_blank(char str[]);

int main()
{
    //declaration of string
    char str[150];

    //getting string from user with more spaces in between
    //printf("Enter the string with more spaces in between two words\n");
    scanf("%[^\n]", str);

    //function call
    replace_blank(str);
    
    printf("%s\n", str);
    
    return 0;
}

// function definition
void replace_blank(char str[]) 
{
    //declaration of variables and initilising j equal to 0
     int i, j = 0;

    // initiate loop until it reaches null character
    for (i = 0; str[i] != '\0' ; i++) 
    {
    // if the first character and second character are spaces, then'continue' statements
        if (str[i] == ' ' && str[i+1] == ' ')
        {
           continue;
        }

        //else assigning str[i]  to the jth index of str
        else
        {
            str[j] = str[i];

            //incrementing  j 
            j = j + 1;
        }
    }

    // assign null to the end of the string
    str[j] = '\0';
}



/*
Name            : Sushant Patil
Date            : 24/02/2023
Description     : WAP to implement strtok function
                  ->Read string1 and string2 from user.
                  ->Call my_strtok (string1, string2);
                  ->Should treat string2 as delimitter in string1 and should return 1 st field.
                  ->If you call again my_strtok (NULL, string2), it should return second field in string1 treating string2 as delimitter.
Sample execution: -
                  Test Case 1:
                  user@emertxe] ./my_strtok
                  enter string1 : Bangalore;;::---Chennai:;Kolkata:;Delhi:-:Mumbai
                  Enter string2 : ;./-:
                  Tokens :
                  Bangalore
                  Chennai
                  Kolkata
                  Delhi
                  Mumbai

                  Test Case 2:
                  user@emertxe] ./my_strtok
                  Enter string1 : -;Bangalore;;::---Chennai:;Kolkata:;Delhi:-
                  Enter string2 : ;./-:
                  Tokens :
                  Bangalore
                  Chennai
                  Kolkata
                  Delhi
*/

#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>

//function declaration
char *my_strtok(char str[], const char delim[]);

int main()
{
    //string declaration
    char str[50], delim[50];
    
    //getting string from user
    printf("Enter the string  : ");
    scanf("%s", str);
    
    __fpurge(stdout);
 
    //getting delimeter from user
    printf("Enter the delimeter : ");
    scanf("\n%s", delim);

    __fpurge(stdout);
    
    //first time function call
    char *token = my_strtok(str, delim);

    //msg to user
    printf("Tokens :\n");
    
    //printing string until token not equal to NULL
    while (token)
    {
        printf("%s\n", token);
        
        //second time function call
        token = my_strtok(NULL, delim);
    }
    
    return 0;
}

//function definition
char *my_strtok(char *str,const char *delim)
{
    //declaration of static variables
    static char *token;
    static int pos;

    //initilization of variables
    int i = pos,j = 0;

    //if str is not equal to null then taking backup of str
    if( str != NULL )
        token = str;

    //initiate loop till character in string not equal to '\0'
    while( token[pos] != '\0' )
    {
        j = 0;

        //initiate loop till delemeters null character
        while(delim[j] != '\0')
        {
            //condition to compare  character in string with delimeter character
            if(token[pos] == delim[j])
            {
                //making char in string '\0'
                token[pos] = '\0';
                pos++;

                //checking for previous charater not equal to '\0'
                if(token[i] != '\0')
                {
                    //returning address of token
                    return &token[i];
                }
                else
                {
                    //if present char and previous character is equal to '\0' then assign pos to i
                    i = pos;
                    pos--;

                    //breaks the inner loop
                    break;
                }
            }
            j++;
        }
        pos++;
    }

    //if char in string not equal to '\0' then retuning the address else return NULL
    if(token[i] != '\0')

        //returning the adress
        return &token[i];
    else
        return NULL;
}

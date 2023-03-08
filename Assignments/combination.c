/*
Name            : Sushant Patil
Date            : 26/02/2023
Description     : WAP to print all possible combinations of given string.
                ->Read a string from the user, find and print all the possible combinations of given string.
Sample execution: -
                  Test Case 1:
                  user@emertxe] ./combinations
                  Enter a string: abc
                  All possible combinations of given string :abc
                  acb
                  bca
                  bac
                  cab
                  cba

                  Test Case 2:
                  Enter a string: abb
                  Error: please enter distinct characters.
*/
#include<stdio.h> 

// declaration of functions
void combination(char [],int ,int );

int my_strlen(char []);

void swap(char *a,char *b);

int main()

{
    //declaration of character string
    char str[100];

    //declaration of variables
    int n, i, j, flag = 0;
    int res;

    //getting string from user
    printf("Enter a string: ");
    scanf("%100[^\n]",str);  

    //calling my_strlen function and stores result in n variable
    n = my_strlen(str);

    //logic to check entered characters are unique or not
    for(i = 0 ; i < (n-1) ; i++)
    {
        for(j = (i+1) ; j < n ; j++)
        {
            if(str[i] == str[j])
            {
                flag = 1;
                break;
            }
        }
    }

    //if characters are unique then calling combination function
    if(flag == 0)
    {
        printf("All possible combinations of given string :");
        combination(str,0,n-1);
    }

    //if characters are not unique then printing error
    else
    {
        printf("Error: please enter distinct characters.");
    }                       
    return 0;
}

//logic to find length of string and returninig len to main
int my_strlen(char *str)
{
   int len = 0;
   while(*str != '\0')
   {
    len++;
    str++;
   }
   return len;
}

//function definition
void combination(char *str ,int start ,int end )
{
    //declaration of variable
    int i;

    //condition to compare starting and endind character
    if(start != end)
    {
        //initiate loop from statring character to ending character
        for(i = start ; i <= end ; i++)
        {
            //function calling for swapping the character
            swap((str + start),(str + i));

            //recursive function call for combination
            combination(str,start + 1,end);

            //again function calling for swapping the character
            swap((str + start),(str + i));
        }
    }

    //if starting and ending character same then printing output
    else
    {
        printf("%s\n",str);
    }
}

//function definition
void swap(char *a,char *b)
{
    //declaration of variable
    char t;

    //logic for swapping
    t = *a;
    *a = *b;
    *b = t;
}

 /*
 Name           : Sushant Patil
 date           : 19/02/2023
 Description    : WAP to implement getword function
                  :->int getword(char *word)
                  ~Create a function named getword.
                  ~Function will receive the string from main
                  ~Function should return the length of the first word.
Sample execution:-
                  Test Case 1:
                  user@emertxe] ./getword
                  Enter the string : Welcome to Emertxe
                  You entered Welcome and the length is 7

                  Test Case 2:
                  user@emertxe] ./getword
                  Enter the string : Hello
                  You entered Hello and the length is 5
 */

#include <stdio.h>

//function definition
int getword(char str[]);

int main()
{
    //initilization of variable   
    int len = 0;

    //declaration of of string
	char str[100];

    //getting string from user
	printf("Enter the string : ");
	scanf(" %[^\n]", str);
    
    //calling getword function and storing result in len variable
	len = getword(str);

    //printing output
    printf("You entered %s and the length is %d\n", str, len);

}

//function definition
int getword(char *str) 
{
    ////initilization of variable 
	int len = 0;

    //if there is space or null character then stoping the increamenting of len count
	while ( *str != ' ' && *str != '\0') 
	{
		*str++;
        len++;    //increamenting length count 
	}

    //condition to print first string and returning their length in the main function
	if (*str == ' ')
    { 
		*str = '\0';
    }
	return len;
}

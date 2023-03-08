 /*
 Name          : Sushant Patil
 date          : 19/2/2023
 Description   : WAP to check given string is Pangram or not 
                 ->Read a string from the user. Check whether the string is Pangram or not
                 ->A pangram is a sentence containing every letter in the English Alphabet.
                   Example 1 : "The quick brown fox jumps over the lazy dog ” is
                                a Pangram [Contains all the characters from ‘a’ to ‘z’] 
                   Example 2: “The quick brown fox jumps over the dog” is not a 
                              Pangram [Doesn’t contain all the characters from ‘a’ to ‘z’, as ‘l’, ‘z’, ‘y’ are missing]
Sample Execution:
                 Test Case 1:
                 Enter the string: The quick brown fox jumps over the lazy dog
                 The Entered String is a Pangram String

                 Test Case 2:
                 Enter the string: The quick brown fox jumps over the dog
                 The Entered String is not a Pangram String
 */

#include <stdio.h>

// function declaration
int pangram(char []);

int main()
{
    // declaration of string
    char str[100];

    //initilization of variable
    int count = 0;


    // getting input from user
    printf("Enter the string : ");
    scanf("%[^\n]", str);


    // function call and stores result in variable
    count = pangram(str);

    // if count is equal to 26 i.e(all 26 elements of array are set)
    if(count == 26)
    {
	// printing  string is pangram
	printf("The Entered string is a Pangram String\n");
    }
    else
    {
	// if condition is false print string is not pamgram
        printf("The Entered string is not a Pangram String\n");
    }
    return 0;
}
int pangram(char *str)
{
    // declearing  and initilization of variables and initilization of array
    int i, index, arr[26] = {0}, count = 0;

    // initiate loop till null detected in string
    for(i = 0; str[i] != '\0'; i++)
    {
	    // condition to check if the corspending element in string lies b/w 'a' to 'z'
	    if(str[i] >= 'a' && str[i] <= 'z')
	    {
	        // getting index number of array
	        index = str[i] - 'a';
	        // setting corespomding element to 1
	        arr[index] = 1;
	    }

	// condition to check if the corspending element in string lies b/w 'A' to 'Z'
	    else if(str[i] >= 'A' && str[i] <= 'Z')
	    {
	        // getting index number of array
	        index = str[i] - 'A';
            // setting coresponding element to 1
	        arr[index] = 1;
	    }
    }

    // using for loop to check array elements
    for(index = 0; index < 26; index++)
    {
	    // checking condition if array index is set 
	    if(arr[index] == 1)
	    {
	        // incrementing count
	        count++;
	    }
    }
    // returning value to main
    return count;
}

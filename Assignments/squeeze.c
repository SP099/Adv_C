/*
 Name          : Sushant Patil
 date          : 19/2/2023
 Description   : WAP to Squeeze the character in string1 that matches any character in the string2
                 ->Read two strings s1 and s2 from user.
                 ->Remove the characters in s1 that matches with s2.
                 ->Input string:
                      string 1: Dennis Ritchie
                      string 2: Linux
                 ->Output String:
                      After squeeze s1: Des Rtche
                 ->Should not use extra array or the pointer
Sample execution: -
                  Test Case 1:
                  user@emertxe] ./squeeze
                  Enter s1 : Dennis Ritchie
                  Enter s2 : Linux
                  After squeeze s1 : Des Rtche

                  Test Case 2:
                  user@emertxe] ./squeeze
                  Enter s1 : Welcome
                  Enter s2 : Emertxe
                  After squeeze s1 : Wlco
 */

#include <stdio.h>
#include<string.h>

//function declaration
void squeeze(char [], char []);

int main()
{
    //declaration of strings
    char str1[30], str2[30];
    
    //getting sting1 from user
    printf("Enter string1:");
    scanf("%[^\n]%*c", str1);
    
    //getting string2 from user
    printf("Enter string2:");
    scanf("%[^\n]", str2);
    
    //function call
    squeeze(str1, str2);
    
    //printing output
    printf("After squeeze s1 : %s\n", str1);
    
}

//function definition
void squeeze(char *str1, char *str2)     
{
    //declaration of variables
    int i, j, k = 0; 

    //initiate loop for string2 until null character
    for(i = 0; str2[i] != '\0'; i++)    
    {

        //initiate loop for string1 until null character,also initiate k values
	    for(j = k = 0; str1[j] != '\0'; j++)  
	    {
            //condition for string1 characters not equal to the string2 characters
	        if(str1[j] != str2[i])   
	        {
                // asiging string1 charcters to the k variable
		        str1[k++] = str1[j];  
	        }
	    }
         //assigning null character to the string1
	    str1[k] = '\0';   
    }
}

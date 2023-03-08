 /*
 Name          : Sushant Patil
 date          : 19/2/2023
 Description   : WAP to reverse the given string using recurse method 
                 ->Read a string from user.
                 ->Implement using recursive function without using any loops
                 ->Do not print character by character.
 sample input  : Enter a string : Hello World
 sample output : Reverse string is : dlroW olleH
 */
#include<stdio.h>
#include<string.h>

//Declaration of the function
void reverse_recursive(char *str,int ind , int len);

int main()
{
    //declaration of string
	char str[30];

    //declaration of variable
	int len;

	//getting string from user
	printf("Enter a string: ");
	scanf("%[^\n]s", str);
		
    //finding string length and stores in len variable    
	len = strlen(str);

	//Calling the reverse_recursive function
	reverse_recursive(str, 0, len);
		
	//printing output
	printf("Reversed string is %s\n", str);
    return 0;
    
}

//function definition
void reverse_recursive(char *str,int ind , int len)
{
    //declaration of variable
    char temp;

    //base condition
    if( ind < (len/2) )              
    {
        //swapping 
	    temp = str[ind];                  
	    str[ind] = str[(len - 1 - ind)]; 
    	str[(len - 1 - ind)] = temp;

	    ind++;
        
        //recursive function
     	reverse_recursive(str,ind,len);   
    }
}

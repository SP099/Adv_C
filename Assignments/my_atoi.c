 /*
 Name          : Sushant Patil
 date          : 19/2/2023
 Description   : WAP to implement atoi function
                 ->int my_atoi(const char *s)
                    -The function will recieve a string and covert the number stored in the string into exact integer number.
                    -Return the number.
 sample input  : Enter the numeric string : -123
 sample output : string to interger is -123
 */
#include <stdio.h>

//function declaration
int my_atoi(const char []);

int main()
{
    //declaration of string
    char str[20];
    
    //getting numeric string from user
    printf("Enter a numeric string : ");
    scanf("%s", str);
    
    //calling my_atoi(str) function and printing output
    printf("String to integer is %d\n", my_atoi(str));
}

//function definition
int my_atoi(const char *s)
{   
    //initilization of variables
    int num = 0, flag = 1;
    
    //initiate loop until null character( if null character loop terminate)
    while( *s )
    {
    
        /*condtion for the fisrt character i.e negative
        if first character is negative sign  then update flag value as -1
        and increamenting s
        */  
        if (*s == '-' )
        {
        
            flag = -1;
            s++;
        }
        
        //validation for positive sign
        else if(*s=='+')
        {
            s++;
        }
        //validation for numbers
        if(*s >= '0' && *s <='9')
        {
            //converting to integer
            num = ( num * 10 ) + ( *s - 48 );
            s++;
        }

       else 
       {
           break;
       }
    
    }
    //returning integer value to main
    return flag * num ;
}

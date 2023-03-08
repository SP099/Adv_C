/*
Name            : Sushant Patil
Date            : 26/02/2023
Description     : Generate consecutive NRPS of length n using k distinct character
                 ->Suppose k = 3 (say taking 3 distinct characters ).
                    :-Let 3 distinct characters be a , b, c.
                 ->Suppose ‘n’ is the string length to be formed using ‘k’ distinct words.
                    :-Let n be 6
                 ->The string should be formed in such a way that there should not be any consecutive repetitions of the strings.
Sample execution:-
                 Test Case 1:
                 user@emertxe] ./nrps
                 Enter the number characters C : 3
                 Enter the Length of the string N : 6
                 Enter 3 distinct characters : a b c
                 Possible NRPS is abcbca

                 Test Case 2:
                 Enter the number characters C : 3
                 Enter the Length of the string N : 7
                 Enter 3 distinct characters : a b a
                 Error : Enter distinct characters
*/


#include <stdio.h>

//declaration of function
void nrps(char [], int , int );

int main()
{
    //declaration of variables
    int c, n, i, j, k, flag = 0;
    
    //reading input from user
    printf("Enter the number characters C : ");
    scanf("%d",&c);

    //reading input from user
    printf("Enter the Length of the string N : ");
    scanf("%d",&n);

    //declaration of character string
    char str[c];

    //getting characters from user
    printf("Enter %d distinct characters :",c);
    for(k=0;k<c;k++)
    {
        scanf("\n%c",&str[k]);  
    }
    
    //logic to check entered characters are unique or not
    for(i=0;i<c-1;i++)
        {
            for(j=i+1;j<c;j++)
            {
                if(str[i]==str[j])
                {
                    flag=1;
                    break;
                }
            }
        }

        //if characters are unique then calling nrps function
        if(flag ==0)
        {
           nrps(str,c,n);
        }

        //if characters are not unique then printing error
        else
        {
            printf("Error: please enter distinct characters.");
        }

        printf("\n");
        return 0;

}


//function definition
void nrps (char *arr, int c, int n) 
{
    //declaration of variables
    int i = 0, j, k;  

    //declaration of character  
    char ar;

    //printing msg to user
    printf("Possible NRPS is: "); 

    //logic to print possible NRPS
    for(j = 0; i < n; j++)   
    {
        printf("%c",*(arr+j));
	    if( j == c-1) 
	    {
	        for(k = 0; k < c - 1; k++)  
	        {
		        ar = arr[k+1];
		        arr[k+1] = arr[k];
		        arr[k] = ar;
	        }

	        j = -1;           
	    }
	    else if( i == c * c )    
	    {
	        for(k = 0; k < c - 1; k++)   
	        {
		        ar = arr[k+1];
		        arr[k+1] = arr[k];
		        arr[k] = ar;
	        }
	    }

	    i++;
    }
}

/*
NAME          : Sushant Patil
DATE          : 05-03-2023
DESCRIPTION   : Provide a menu to manipulate or display the value of variable of type t
SAMPLE INPUT  : 
SAMPLE OUTPUT :
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

int main()
{
    // allocating 8 byte of memory
    void *ptr = malloc(8);
   
    if(ptr == NULL)
    {
	printf("Error : Memory allocation  failed\n");
    }
    // declearing variables
    int choice, char1_flag = 0, char2_flag = 0, short_flag = 0, int_flag = 0, float_flag = 0, double_flag = 0;
    // using do while loop
    do
    {
	
	// displaying the menu
	printf("Menu : \n1. Add element\n2. Remove element\n3. Display element\n4. Exit frim the programe\n\n");
	// reading choice from user
	printf("Choice---> ");
	scanf("%d", &choice);
        // using switch case to perform different operations
	switch (choice)
	{
	    // case 1 to add different elements to memory 
	    case 1:
		{
		    int ch;
		    // displaying another menu 
		    printf("Enter the type you have to insert :\n");
		    printf("1. int\n2. char\n3. short\n4. float\n5. double\n");
		    printf("Choice---> ");
		    scanf("%d", &ch);
		    // using another switch case to add different type of data in a memory 
		    switch (ch)
		    {
			// case 1 to add int
			case 1:
			    {
				printf("\n------------\n");
				// check if the memory of int type if filled or not
				if(int_flag == 0 && float_flag == 0 && double_flag == 0)
				{
				    // if above condition is true then add int
				    printf("Enter the int : ");
				    scanf("%d", ((int*)ptr+1));
				    // set the int_flag value to 1
				    int_flag = 1;
				}
				else
				{
				    // if above condition is false print error
				    printf("\nError : memory not avilable\n");
				}
				break;
			    }
			// case 2 to add char
			case 2:
			    {
				// check if the memory char type is filled or not
				if(char1_flag == 0 && double_flag == 0)
				{
				    printf("Enter the char : ");
				    __fpurge(stdin);
				    scanf("%c", ((char*)ptr));
				    char1_flag = 1;
				}
				else if(char2_flag ==0 && double_flag == 0)
				{
				    printf("Enter the char : ");
				    __fpurge(stdin);
				    scanf("%c", ((char*)ptr+1));
				    char2_flag = 1;

			        }
				else
				{
				    // if above conditions are false print error
				    printf("\nError : memory not avilable\n");
				}
				break;
			    }
			// case 3 to add short    
			case 3:
			    {
				// check if the memory short type is filled or not
				if(short_flag == 0 && double_flag == 0)
				{
				    // if condition is true then add short
				    printf("Enter the short : ");
				    scanf("%hi", ((short*)ptr+1));
				    short_flag = 1;
				}
				else
				{
				    // if the condition is false print error
				    printf("\nError : memory not avilable\n");
				}
				break;
			    }
			// case 4 to add float    
			case 4:
			    {
				// check if the memory float type is filled or not
				if(float_flag == 0 && int_flag == 0 && double_flag == 0)
				{
				    // if the condition is true then add float
				    printf("Enter the float : ");
				    scanf("%f", ((float*)ptr+1));
				    float_flag = 1;
				}
				else
				{
				    // if the condition is false print error
				    printf("\nError : memory not avilable\n");
				}
				break;
			    }
			// case 5 to add double    
			case 5:
			    {
				// check if the memory double type is filled or not
				if(double_flag == 0 && float_flag == 0 && int_flag == 0 && short_flag == 0 && char1_flag == 0 && char2_flag == 0)
				{
				    // if the condition is true then add double
				    printf("Enter the double : ");
				    scanf("%le", ((double*)ptr));
				    double_flag = 1;
				}
				else
				{
				    // if the condition is false then print error
				    printf("\nError : memory not avilable\n");
				}
				break;
			    }
		    }
		    printf("\n------------\n");
		    break;
		}
	    // case 2 to remove elements from memory	
	    case 2:
		{

		    printf("\n------------\n");
		    int i;
		    // read the index value from user 
		    printf("\nEnter the index value to be deleted : ");
		    scanf("%d", &i);
		    // check the index value and respective flag to remove elements
		    if(i == 0 && (char1_flag == 1 || double_flag ==1))
		    {
			char1_flag = 0;
			double_flag = 0;
			
			printf("\nIndex %d successfully deleted\n", i);
		    }
		    if(i == 1 && char2_flag == 1)
		    {
			char2_flag = 0;
			printf("\nIndex %d successfully deleted\n", i);
		    }
		    if(i == 2 && short_flag == 1)
		    {
			short_flag = 0;
			printf("\nIndex %d successfully deleted\n", i);
		    }
		    if(i == 4 && (int_flag == 1 || float_flag == 1))
		    {
			int_flag = 0;
			float_flag = 0;
			printf("\nIndex %d successfully deleted\n", i);
		    }
		    printf("\n------------\n");
		    break;
		}
	    // case 3 to display different (datatypes)elements stored in memory
	    case 3:
		{
		    printf("\n------------\n");
		    // check the condition  of respective flag to display the elements
		    if(char1_flag == 1)
		    {
			printf("0-> ");
			printf("%c", *((char*)ptr));
			printf(" (char)\n");
		    }
		    if(char2_flag == 1)
		    {
			printf("1-> ");
			printf("%c", *((char*)ptr+1));
			printf(" (char)\n");
		    }
		    if(short_flag == 1)
		    {
			printf("2-> ");
			printf("%hi", *((short*)ptr+1));
                        printf(" (short)\n");
		    }
		    if(int_flag == 1)
		    {
			printf("4-> ");
			printf("%d", *((int*)ptr+1));
			printf(" (int)\n");
		    }
		    if(float_flag == 1)
		    {
			printf("4-> ");
			printf("%f", *((float*)ptr+1));
			printf(" (float)\n");
		    }
		    if(double_flag == 1)
		    {
			printf("0-> ");
			printf("%le", *((double*)ptr));
			printf(" (double)\n");
		    }
		    printf("\n------------\n");
           
		}
		break;
	    // case 4 to exit from programe	
	    case 4:
            printf("Exiting the program\n");
            free(ptr);
            exit(0);

            default:
            printf("Invalid choice\n");
            break;
	  }
    }while(1);

    return 0;
}

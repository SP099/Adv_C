/*
Name          : Sushant Patil
Date          : 08/01/2023
Description   : WAP to find which day of the year
Sample Input  : user@emertxe] ./day_of_the_year
Sample Output : Enter the value of 'n' : 9
                Choose First Day :
                1. Sunday
                2. Monday
                3. Tuesday
                4. Wednesday
                5. Thursday
                6. Friday
                7. Saturday
                Enter the option to set the first day : 2
                The day is Tuesday
*/

#include<stdio.h>
int main()
{

    //declaration of variables
	int nth_day , first_day , res , rem ;


    //get nth day from user
	printf ("Enter the value of 'nth_day' :");  
	scanf ("%d", &nth_day);  

    //nth day must be in between 0 to 365
	if ( nth_day > 0 && nth_day <= 365 )  
	{ 

        //printing menu to user
	    printf ("Choose First Day :\n1.Sunday\n2.Monday\n3.Tuesday\n4.Wednesday\n5.Thursday\n6.Friday\n7.Saturday\n");

        //get the value from user to choose the first day from menu
        printf("Enter the option to set the first day : ");
	    scanf ("%d", &first_day);

        //checking the selected fisrt day is in between 0 to 7
	    if ( first_day > 0 && first_day <= 7) 
	    {

            //calculating the day
	        res = ( nth_day + first_day - 1 );

            //finding the day
		    rem = ( res % 7 );

            //displays nth day
		    switch ( rem )        
		    {

		        case 1:
			        printf ("The day is Sunday");     
			        break;
		        case 2:
			        printf ("The day is Monday");
			        break;
		        case 3:
		        	printf ("The day is Tuesday");
			        break;
		        case 4:
			        printf ("The day is Wednesday");
			        break;
		        case 5:
			        printf ("The day is Thursday");
			        break;
		        case 6:
			        printf ("The day is Friday");
			        break;
		        case 0:
			        printf ("The day is Saturday");
			        break;
		    }
	    }

	    else 

            //printing error if fist day is not in between 0 and 7
		    printf ("Error: Invalid input, first day should be > 0 and <= 7");
	    
	}

	else

        //printing error if nth day not in between 0 to 365 
	    printf ("Error: Invalid Input, n value should be > 0 and <= 365");

    printf("\n");
    return 0;
}


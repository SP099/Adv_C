/*
Name          : Sushant Patil
Date          : 10/01/2023
Description   : WAP to generate AP, GP, HP series
Sample Input  : user@emertxe] ./progressions
Sample Output : Enter the First Number 'A': 2
                Enter the Common Difference / Ratio 'R': 3
                Enter the number of terms 'N': 5
                AP = 2, 5, 8, 11, 14
                GP = 2, 6, 18, 54, 162
                HP = 0.500000, 0.200000, 0.125000, 0.090909, 0.071428
*/

#include<stdio.h>
int main()
{
    //declaration of variables
    int A,R,N,i,j,res;
    float HP;

    //get starting number from user
    printf("Enter the First Number 'A':");
    scanf("%d",&A);

    //get common difference number between numbers from user
    printf("Enter the Common Difference / Ratio 'R': ");
    scanf("%d",&R);

    //get nth term of series from user
    printf("Enter the number of terms 'N': ");
    scanf("%d",&N);


    //first number,comman difference and nth term should be greater than 0
    if( A > 0 && R > 0 && N > 0 )
    {

        /******************************** **Arithmetic Progression*********************************/
        //printing first term of AP series
        printf("AP = %d",A);


        //printing 2nd to nth terms of the AP series
        res = A ;
        for( i = 1 ; i<N ; i++ )
        {
            res = res + R;
            printf(", %d",res);
        }
        printf("\n");


        /***********************************Geometric Progression ***********************************/
        //printing first term of GP series
        printf("GP = %d",A);

        //printing 2nd to nth terms of the GP series
        res = A ;
        for( i = 1 ; i<N ; i++ )
        {
            res = res * R;
            printf(", %d",res);
        }
        printf("\n");


        /*************************************Harmonic Progression************************************/
        //printing first term of HP series
        printf("HP = %f",(float) 1 / A );


        //printing 2nd to nth terms of the HP series
        res = A + R ;
        for( i = 1 ; i<N ; i++ )
        {
            HP = (float) 1 / res ;
            printf(", %f",HP);
            res = res + R ;
        }
        printf("\n");
     }


     //if first number,comman difference and nth any one of this 0 then print error
     else
         printf("Invalid input");

    printf("\n");
    return 0;
}


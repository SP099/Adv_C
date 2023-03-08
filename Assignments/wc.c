/*
Name            : Sushant Patil
Date            : 19/02/2023
Description     : WAP to count no. of characters, words and lines, entered through stdin
                  ->Read characters from user till EOF
                  ->If EOF received, print the character count, word count, and line count.
                  ->Code should exactly work like wc command.
Sample execution:
                  Test Case 1:
                  user@emertxe] ./my_wc
                  Hello world
                  Dennis Ritchie
                  Linux
                  Character count : 33
                  Line count : 3
                  Word count : 5

                  Test Case 2:
                  Hello         world
                  Dennis    Ritchie
                  Linux
                  Character count : 39
                  Line count : 3
                  Word count : 5


*/

#include<stdio.h>

#include<stdio.h>
int main()
{
    /*variable declaration and initiLisation*/
    int char_count=0,word_count=0,line_count=0;
    char ch;
    int prev='\0';
   /*reads the input till end of file*/
    while( ( ch = getchar() ) != EOF )
    {
        /*increase character count till EOF*/
        char_count++;
        /*if there is space increase word count*/
        if(( ch == ' '||ch=='\t'||ch=='\n' ||ch==EOF ) && prev!=' ' && prev !='\t' && prev !='\n' && prev != EOF )  
        {
            word_count++;
        }
        /*if there is space or enter increase word and line count*/
        else if( ch =='\n')
        {
            word_count++;
            ++line_count;
        }

    }
    /*printing the output*/
    printf("\nCharacter count : %d\nLine count : %d\nWord count : %d\n",char_count,line_count,word_count);
}

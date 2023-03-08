/*
Name            : Sushant Patil
date            : 05/03/2023
Description     : WAP to Implement the student record using array of structures
Sample Execution: 
                  Test Case 1:
                  user@emertxe] ./student_record
                  Enter no.of students : 2
                  Enter no.of subjects : 2
                  Enter the name of subject 1 : Maths
                  Enter the name of subject 2 : Science
                  ----------Enter the student datails-------------
                  Enter the student Roll no. : 1
                  Enter the student 1 name : Nandhu
                  Enter Maths mark : 99
                  Enter Science mark : 91
                  ----------Enter the student datails-------------
                  Enter the student Roll no. : 2
                  Enter the student 2 name : Bindhu
                  Enter Maths mark : 88
                  Enter Science mark : 78
                  ----Display Menu----
                  1. All student details
                  2. Particular student details
                  Enter your choice : 2

                  ----Menu for Particular student----
                  1. Name.
                  2. Roll no.
                  Enter you choice : 1
                  Enter the name of the student : Nandhu
                  Roll No.   Name           Maths         Science       Average       Grade
                  1              Nandhu        99               91                95                  A
                  Do you want to continue to display(Y/y) : n              
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student
{
    int roll_no;
    char name[20];
    int* marks;
    float average;
    char grade;
};
int main()
{ 

    // declearing variables
    int num_students, num_subjects, Roll_no, ch, option;
    char name[30],ch1;

    // reading number of students and number of sublects from user
    printf("Enter the number of students : ");
    scanf("%d", &num_students);

    printf("Enter the number of subjects : ");
    scanf("%d", &num_subjects);

    // reading subject names from user
    char subjectnames[num_subjects][30];

    for(int i = 0; i < num_subjects; i++)
    {
	    printf("Enter the name of subject %d: ", i+1);
        scanf("%s", subjectnames[i]);
    }
    // allocating memory for the student array
    struct student* students = (struct student*)malloc(num_students * sizeof(struct student));
    // reading student details from user
    for(int i = 0; i < num_students; i++)
    {
	    printf("\n----------Enter the student [%d] details----------\n", i+1);
	    printf("\nEnter the student Roll no. : ");
	    scanf("%d", &students[i].roll_no);
	    printf("Enter the student %d name : ", i+1);
        scanf("%s", students[i].name);
	    // allocating memory for the marks array
	    students[i].marks = (int*)malloc(num_subjects * sizeof(int));
	    // reading the mnarks from user
	    for(int j = 0; j < num_subjects; j++)
	    {
	        printf("\nEnter %s marks : ", subjectnames[j]);
	        scanf("%d", &students[i].marks[j]);
	    }
	    // calculating average
	    int total_marks = 0;
	    for(int j = 0; j < num_subjects; j++)
	    {
	        total_marks += students[i].marks[j];
    	}
	    students[i].average = (float)total_marks / num_subjects;
	    // checking  condition for grades
	    if(students[i].average >= 90)
	    {
	        students[i].grade = 'A';
    	}
	    else if(students[i].average >= 80)
	    {
	        students[i].grade = 'B';
	    }
	    else if(students[i].average >= 70)
	    {
	        students[i].grade = 'C';
	    }
	    else if(students[i].average >= 50)
	    {
	        students[i].grade = 'D';
	    }
	    else
	    {
	        students[i].grade = 'F';
	    }
    }
    do
    {

	    // displaying menu
	    printf("\n----------Display Menu----------\n");
	    printf("1. All student details\n");
	    printf("2. Particular student details\n");
    	int choice;
    	printf("Enter your choice : ");
    	scanf("%d", &choice);

    	switch (choice)
     	{
	        case 1:
		    {
		        printf("---------------------------------------------------------------------------");

		        // print all student details
		        printf("\nRoll no.   Name           ");
		        for(int i = 0; i < num_subjects; i++)
		        {
			        printf("%-15s", subjectnames[i]);
		        }
		        printf("%-15s %-15s\n", "Average","Grade");
		        printf("---------------------------------------------------------------------------\n");

		        for(int i = 0; i < num_students; i++)
		        {
			        printf("%-10d %-15s", students[i].roll_no,students[i].name);
			        for(int j = 0; j < num_subjects; j++)
			        {
			            printf("%-15d", students[i].marks[j]);
			        }
			        printf("%-15g %-15c\n", students[i].average,students[i].grade);
		        }
		        break;
		    }
	        case 2:
		    {
		        // displaying menu for particular student
		        int c;
		        printf("\n----------Menu for particular student----------\n");
		        printf("1. Name.\n2. Roll no.\n");
		        printf("Enter your choice : ");
		        scanf("%d", &c);

		        switch (c)
		        {
			    case 1:
			    {
	
				    // printing particular student details by entering name
	    		  	printf("\nEnter the name of student : ");
	  			    scanf("%s", name);

				    printf("---------------------------------------------------------------------------");
				    for(int i = 0; i < num_students; i++)
				    {
					    if(strcmp(students[i].name,name) == 0)
					    {
				            printf("\nRoll no.   Name           ");
					        for(int i = 0; i < num_subjects; i++)
					        {
					        	printf("%-15s", subjectnames[i]);
					        }
					        printf("%-15s %-15s\n", "Average","Grade");
				    	    printf("---------------------------------------------------------------------------\n");

					        printf("%-10d %-15s", students[i].roll_no,students[i].name);
					        for(int j = 0; j < num_subjects; j++)
					        {
					            printf("%-15d",students[i].marks[j]);
					        }
					        printf("%-15g %-15c\n", students[i].average,students[i].grade);
					    }
		   	    	}
				    break;
			    }
			    case 2:
			    {
				    // printing particular student details by entering  Roll no.
				    printf("\nEnter the Roll no. of student : ");
				    scanf("%d", &Roll_no);

				    printf("---------------------------------------------------------------------------");
				    for(int i = 0; i < num_students; i++)
		  	        {
					    if(students[i].roll_no == Roll_no)
					    {
					        printf("\nRoll no.   Name           ");
					        for(int i = 0; i < num_subjects; i++)
					        {
						        printf("%-15s", subjectnames[i]);
					        }
					        printf("%-15s %-15s\n", "Average","Grade");
					        printf("---------------------------------------------------------------------------\n");

					        printf("%-10d %-15s", students[i].roll_no,students[i].name);
					        for(int j = 0; j < num_subjects; j++)
					        {
					            printf("%-15d",students[i].marks[j]);
					        }
					        printf("%-15g %-15c\n", students[i].average,students[i].grade);
					    }
				    }
				    break;
			    }

			}
		}
	}
	// ask the user whether to continue or not
	printf("Do you want to continue to display(y/Y): ");  
	scanf("\n%c",&ch1);                   //<---- reading the choice from user

    }while (ch1 == 'Y' || ch1 == 'y'); 

    return 0;
}

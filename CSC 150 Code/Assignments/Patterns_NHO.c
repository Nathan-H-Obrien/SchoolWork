// Name: Nathan O'Brien; Due Date: April 2nd, 2023
// Course: CSC 150 S03 TTh 11-1215; Assignment: Program 5
// Description: This program is print a menu in which the user inputs
// which will cause an array of numbers to be displayed as a pattern.

#include <stdio.h>
#include <stdlib.h>

int pattern1(int size);     //Take size and print pattern 1 design
int pattern2(int size);     //Take size and print pattern 2 design
int pattern3(int size);     //Take size and print pattern 3 design
int pattern4(int size);     //Take size and print 4 design
void printWelcome();        //Print welcome message
int printMenu(void);        //Print pattern menu
int printPattern(void);     //Print pattern size menu



int main()
{
    //Variables
    int size;
    int done = 0;
    int option;
    int result;

    //Call welcome message
    printWelcome();

    //statements
   	while (!done)
	  {
	   option = printMenu();
	   if (option == 0)
	      done = 1;
	   else
	     size = printPattern();

    //Use option to determine pattern and size
    switch (option)
    {
        case 1: result = pattern1 (size);
            break;
        case 2: result = pattern2 (size);
            break;
        case 3: result = pattern3 (size);
            break;
        case 4: result = pattern4 (size);
            break;
    }

	     }
        //Print farewell message after exiting the program
        printf ("\nThank you for using the program!!\n");

return 0;
}


void printWelcome ()
{
    printf ("\nWelcome! This program is to create an array of numbers\n");
    printf ("into four different patterns!\n\n");

    return;
}

int printMenu ()
{
//	Local Declarations
	int option;

//	Statements
	do
	  {
	   printf("\n*******************");
	   printf("\n*       MENU      *");
	   printf("\n*                 *");
	   printf("\n*  1. Pattern 1   *");
	   printf("\n*  2. Pattern 2   *");
	   printf("\n*  3. Pattern 3   *");
	   printf("\n*  4. Pattern 4   *");
	   printf("\n*  0. EXIT        *");
	   printf("\n*                 *");
	   printf("\n*******************");

	   printf("\n\n\nPlease type your choice ");
	   printf("and press the return key : ");
	   scanf("%d", &option);

	   if (option < 0 || option > 4)
	      printf("Invalid option. Please re-enter.\n");

	 } while (option < 0 || option > 4);
	return option;
}	// getOption

int printPattern (void)
{
//	Local Declarations
	int size;

//	Statements
	do
	  {
	   printf("\n*******************");
	   printf("\n*       MENU      *");
	   printf("\n*                 *");
	   printf("\n*  5. SIZE 5      *");
	   printf("\n*  6. SIZE 6      *");
	   printf("\n*  7. SIZE 7      *");
	   printf("\n*  8. SIZE 8      *");
       printf("\n*  9. SIZE 9      *");
	   printf("\n*                 *");
	   printf("\n*******************");

	   printf("\n\n\nPlease type your choice ");
	   printf("and press the return key : ");
	   scanf("%d", &size);

	   if (size < 5 || size > 9)
	      printf("Invalid option. Please re-enter.\n");

	 } while (size < 5 || size > 9);

	return size;
}	// getOption

int pattern1 (int size)
{
    //Local declarations
    int row, col;

    // loop through the rows
    for (row=1; row <= size; row++)
    {
        // print one row
        for (col=1; col <= size; col++)
        {
            if (row == col)
                printf(" *");
            else
                printf("%2d", size);        }
        printf("\n");
    }

    return 0;
}


int pattern2 (int size)
{
    //Local declarations
    int row, col;

    // loop through the rows
    for (row=1; row <= size; row++)
    {
        // print one row
        for (col=1; col <= size; col++)
        {
            if (((row == 2 || row == size - 1) && (2 <= col && col <= size - 1)) || (col == 2 || col == size - 1) && (2 <= row && row <= size - 1))
                printf("%2d", size);
            else
                printf(" *");        }
        printf("\n");
    }

    return 0;
}

int pattern3 (int size)
{
    //Local declarations
    int row, col;

    // loop through the rows
    for (row=1; row <= size; row++)
    {
        // print one row
        for (col=1; col <= size; col++)
        {
            if (((row == 2 || row == size - 1) && (2 <= col && col <= size - 1)) || (col == 2 || col == size - 1) && (2 <= row && row <= size - 1))
                printf(" *");
            else
                printf("%2d", size);        }
        printf("\n");
    }

    return 0;
}

int pattern4 (int size)
{
    //Local declarations
    int row, col;

    // loop through the rows
    for (row=1; row <= size; row++)
    {
        // print one row
        for (col=1; col <= size; col++)
        {
            if (col + row == size + 1)
                printf(" *");
            else
                printf("%2d", size);        }
        printf("\n");
    }

    return 0;
}





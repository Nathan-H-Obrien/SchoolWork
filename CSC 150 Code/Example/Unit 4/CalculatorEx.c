/*	This program uses a menu to allow the user to add,
	multiply, subtract, or divide two integers.
	   Written by:
	   Date:
*/
#include <stdio.h>
#include <stdlib.h>

#define INT_MAX 1999999999

typedef enum {ADD=1, SUB, MULT, DIV} op_t;  // ADD=1, SUB=2, MULT=3, DIV=4

//	Function Declarations
int   getOption (void);
void  getData   (int* num1, int* num2);
float calc      (int option, int num1, int num2);
float add       (int num1,   int num2);
float sub       (int num1,   int num2);
void  printResults (int option, int num1, int num2, float result);

int main (void)
{
//	Local Declarations
	int   option;
	int   num1;
	int   num2;
	float result;

//	Statements
    do
    {
        option = getOption();   // updated to return 1 through 5
        if (option >= ADD && option <= DIV)  // validate the option
        {
            getData (&num1, &num2);  // pass by reference with pointers
            result = calc (option, num1, num2);
            if (result != INT_MAX)
                printResults(option, num1, num2, result);
        }
    } while (option != 5);    // if condition evaluates to true, repeat the logic

	return 0;
}	// main

/*	==================== getOption ====================
	This function shows a menu and reads the user option.
	   Pre    Nothing
	   Post   returns the option
*/
int getOption (void)
{
//	Local Declarations
	int option;

        // print menu
    printf  ("\t**********************************");
    printf("\n\t*              MENU              *");
    printf("\n\t*                                *");
    printf("\n\t*  1. ADD                        *");
    printf("\n\t*  2. SUBTRACT                   *");
    printf("\n\t*  3. MULTIPLY                   *");
    printf("\n\t*  4. DIVIDE                     *");
    printf("\n\t*  5. EXIT                       *");
    printf("\n\t*                                *");
    printf("\n\t**********************************");

    // read the choice
    printf("\n\nPlease type your choice ");
    printf("and key return: ");
    scanf ("%d", &option);

	return option;
}	// getOption

/* ====================== getData ====================
	This function reads two integers from the keyboard.
	   Pre   Parameters a and b are addresses
	   Post  Data read into parameter addresses
*/
void getData (int* a, int* b)
{
	printf("Please enter two integer numbers: ");
	scanf("%d %d", a, b);
	return;
}	// getData

/*	==================== calc ====================
	This function determines the type of operation
	and calls a function to perform it.
	   Pre   option contains the operation
	         num1 & num2 contains data
	   Post  returns the results
*/
float calc (int option, int num1, int num2)
{
    // Local Declarations
    float result;

    //	Statements
	switch(option)
    {
	     case ADD:  result = add (num1, num2);
                    break;
	     case SUB:  result = sub (num1, num2);
	              break;
	     case MULT:  result = 3.0;              // Multiply
	              break;
	     case DIV:  if (num2 == 0.0)           // Divide
                  {
	                  printf("\n\a\aError: ");
	                  printf("division by zero ***\n");
	                  result = INT_MAX;
                  } // if
	              else
	                  result = 4.0;
	              break;
	     /* Better structured programming would validate
	        option in getOption. However, we have not
	        yet learned the technique to code it there.
	     */
	     default: printf("\aOption not available\n");
	              exit (101);
    } // switch
//printf("**In calc result is: %6.2f\n", result);
	return result;
}	// calc

/* ====================== add ======================
	This function adds two numbers and returns the sum.
	   Pre   a and b contain values to be added
	   Post  Returns a + b
*/
float add (int a, int b)
{
//	Local Definitions
	float sum;

//	Statements
	sum = a + b;
	return sum;
}	// add

/* ====================== sub ======================
	This function subtracts two numbers
	   Pre   a and b contain values to be subtracted
	   Post  Returns a + b
*/
float sub (int a, int b)
{
//	Local Definitions
	float dif;

//	Statements
	dif = a - b;
//printf("**In sub result is:  %6.2f\n", dif);
	return dif;
}	// sub


void printResults (int option, int num1, int num2, float result)
{
    printf ("\t%3d", num1);

    switch (option)
    {
        case ADD:
            printf (" + ");
            break;
        case SUB:
            printf (" - ");
            break;
        case MULT:
            printf (" * ");
            break;
        case DIV:
            printf (" / ");
            break;
        default:
            printf ("Invalid Operation\n");
    }
    printf ("%d = %.1f\n\n", num2, result);
}



/*	Results:
    **********************************
    *              MENU              *
    *                                *
    *  1. ADD                        *
    *  2. SUBTRACT                   *
    *  3. MULTIPLY                   *
    *  4. DIVIDE                     *
    *                                *
    **********************************

Please type your choice and key return: 2
Please enter two integer numbers: 13 8
**In sub result is:    5.00
**In calc result is:   5.00
**In main result is:   5.00
*/

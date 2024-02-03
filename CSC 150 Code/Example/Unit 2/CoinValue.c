/* Figure 2.13 */
/*
 * Determines the value of a collection of coins.
 */
#include <stdio.h>

int
main(void)
{
     char first, middle, last;	/* input - 3 initials     	*/
     int pennies, nickels;  /* input - count of each coin type	*/
     int dimes, quarters;   /* input - count of each coin type	*/
     int change; 	        /* output - change amount    	*/
     int dollars;        	/* output - dollar amount   	*/
	 int total_dollars;  	/* total dollars            */
     int total_cents;  	    /* total cents             	*/
 
     /* Get and display the customer's initials. */ 
     printf("Type in your 3 initials and press return> "); 
     scanf("%c%c%c", &first, &middle, &last);
     printf("%c%c%c, please enter your coin information.\n",
            first, middle, last);
 
     /* Get the count of each kind of coin. */ 
	 printf("Number of $ coins> "); 
     scanf("%d", &dollars); 
     printf("Number of quarters> "); 
     scanf("%d", &quarters); 
     printf("Number of dimes   > "); 
     scanf("%d", &dimes); 
     printf("Number of nickels > "); 
     scanf("%d", &nickels); 
     printf("Number of pennies > "); 
     scanf("%d", &pennies); 
 
     /* Compute the total value in cents. */
     total_cents = 25 * quarters + 10 * dimes +
                    5 * nickels + pennies;
 
     /* Find the value in dollars and change. */
     total_dollars = total_cents / 100; 
     change = total_cents % 100; 
 
     /* Display the credit slip with values in dollars and change. */
     printf("\n\n%c%c%c Coin Credit\nDollars: %d\nChange: %d cents\n",
	        first, middle, last, total_dollars, change);
 
     return (0);
}

/*
Type in your 3 initials and press return> BMC
BMC, please enter your coin information.
Number of $ coins> 2
Number of quarters> 14
Number of dimes   > 12
Number of nickels > 25
Number of pennies > 131


BMC Coin Credit
Dollars: 7
Change: 26 cents
*/


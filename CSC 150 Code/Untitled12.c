/* The goal of this program is to find the length of the hypotenuse
This is going to be done by using functions to understand how they work
and operate in C.*/


#include <stdio.h>
#include <math.h>

/* use a function name 3 time:
Declaration (prototype) tells the compiler the function's name
    - parameter list and return type*/
void printWelcome();
float getLegLength ();
void printHyp (float l1, float l2, float h);    //format and output the hypotenuse
float calcHyp (float l1, float l2); // Calculate and return the hypotenuse




int main ()
{
    float leg1, leg2, hyp;
/*Call tells the function to run, sends in any needed data, catches
any return value with an = and stores it into main's variable*/
    printWelcome();

    leg1 = getLegLength ();
    leg2 = getLegLength ();

    hyp = calcHyp(leg1, leg2);

    printHyp(leg1, leg2, hyp);

    return 0;
}

/*Definition - starts with the prototype but goes on to give
    the statements that are the function*/

void printWelcome()
{
    printf("\n\tWelcome to Pythagorean's Theorem! \n\n");

    return;
}

void printHyp (float l1, float l2, float h)
{
    printf ("\n\nMeasures for your right triangle:\n");
    printf ("Leg1:    %6.2f\n", l1);
    printf ("Leg2:    %6.2f\n", l2);
    printf ("Hypotenuse: %6.2f\n", h);

    return;
}

/* value returning function
Make a local variable to hold the value until we can return*/

float calcHyp (float l1, float l2)
{
    float sumOfSquares;     //local variable to hold intermediate value
    float h;

    sumOfSquares = pow(l1,2) + pow(l2,2);

    h = sqrt(sumOfSquares);

    return h;
}

// a function to read and return the length of
//  a leg in a right triangle
float getLegLength ()
{
    float leg;

    printf ("Enter the length of a leg in a right triangle: ");
    scanf ("%f", &leg);

    return leg;
}

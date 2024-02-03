//Loops Practice!
// 03/21/2023
//

#include <stdio.h>


int main()
{
    int x;

    // print 1 through 100

    //initialize
    x = 1;
    while (x<= 100)     //check
    {
        printf ("%4d", x);

        //update
        x++;

    }

    printf ("\n\nFinal x: %d\n\n\n", x);


    //equivalent for loop
    for (x=1; x <= 100; x++)
    {
        printf ("%4d", x);
    }

    printf ("\n\nFinal x: %d\n\n\n", x);


    do
    {
        printf ("&4d", x);
        x++;
    } while (x <= 100);



    return 0;
}

// This is a code example to learn how
// else statements are matched with
// their corresponding if statements

#include <stdio.h>

int main()
{
    int a, b, c;

    printf ("Enter 3 integers: ");
    scanf ("%d %d %d", &a, &b, &c);

    if (a > b)
    {
        if (a > c)
            c += 5;
        else
        c-= 5;
    }

    printf ("c: %d\n", c);
    return 0;

}

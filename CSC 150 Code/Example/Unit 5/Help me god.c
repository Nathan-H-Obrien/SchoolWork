#include <stdio.h>

int main()
{
    int size = 8;
    int row, col;

    // loop through the rows
    for (row=1; row <= size; row++)
    {
        // print one row
        for (col=1; col <= size; col++)
        {
            if (row *2 == col)
                printf(" *");
            else
                printf("%2d", size);        }
        printf("\n");
    }

    return 0;
}

#include <stdio.h>

int main()
{

int day = 3;

switch (day)
{
    case 0:
    case 1:
        day = day + 1;
        break;

    case 2:
    case 3:
    case 4:


    case 5:
    case 6:
        day = day - 2;
        break;

    default: printf ("Error finding day\n");
    break;
}
    printf ("The day is %d", day);
    return 0;
}

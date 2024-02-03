/* Rectangle Program - Calculate and display the area of a rectangle*/

#include <stdio.h>

int main()
{
    //define variables
    int l;
    int w;
    int area;

    //statements
    printf("\nWelcome\n");
    printf("\nThis program calculates the area of a given width and length\n");
    printf("\nEnter two numbers in the form of nnn nnn <return>\n");
    scanf("%d %d", &l, &w);

    //calculate area
    area = l * w;

    //display area
    printf("The area is: %d\n\n", area);

    return 0;
}

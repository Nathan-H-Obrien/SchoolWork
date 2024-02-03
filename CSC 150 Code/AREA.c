#include <stdio.h>
#include <math.h>

#define PI 3.14159

int main()
{
    float area,
    radius;

    printf("Enter the radius of the circle.");
    scanf("%f", &radius);

    area = PI * radius * radius;

    printf("The area of the circle is %.1f", area);

    return 0;
}

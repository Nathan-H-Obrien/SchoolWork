// Name: Nathan O'Brien; Due Date: January 30th 2023
// Course: CSC 150 S03 TTh 11-1215; Assignment: Program 2
// Description: This program is to take user inputs of a depth in inches and a diameter in yards
// and calculate the volume of water needed to create an ice rink with the given dimensions.

#include <stdio.h>
#define Gal_Per_CuFoot 7.48 //Gallons per Cubic Foot
#define Inch_Per_Foot 12.0 //Inches per Foot
#define Foot_Per_Yard 3.0 //Feet per yard
#define PI 3.14159    //Digits of PI

int main()
{
    // Define variables
    float depth, //Depth of ice rink in inches
    diameter,   //Diameter of ice rink in yards
    DiaFoot,   //Diameter of ice rink in feet
    radius,     //Radius of ice rink in feet
    volume,     //Amount of water in gallons
    depthFeet,  //Depth of ice rink in Feet
    area;    //Area of the ice rink

    //Get depth and diameter
    printf ("\nThis program is to calculate the amount\n");
    printf ("\nof water needed to fill an ice rink with given dimensions.\n");
    printf ("\nEnter the depth in inches and enter the diameter in yards. <return>\n");
    scanf ("%f %f", &depth, &diameter);

    //Convert depth into feet
    depthFeet = depth / Inch_Per_Foot;

    //Convert yards into feet
    DiaFoot = Foot_Per_Yard * diameter;

    //Convert diameter into radius
    radius = DiaFoot / 2.0;

    //Calculate area
    area = radius * radius * PI;

    //Calculate total volume of ice rink and water needed
    volume = area * depthFeet * Gal_Per_CuFoot;

    //Display total with depth and diameter
    printf ("\n%.1f gallons of water are needed for an ice rink with\n", volume);
    printf ("\nthe depth of %.1f inches and diameter of %.1f yards\n", depth, diameter);

    return (0);

}

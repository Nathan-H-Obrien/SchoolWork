// Name: Nathan O'Brien; Due Date: January 30th 2023
// Course: CSC 150 S03 TTh 11-1215; Assignment: Program 2
// Description: This program is to take user inputs of a depth in inches and a diameter in yards
// and calculate the volume of water needed to create an ice rink with the given dimensions.

#include <stdio.h>
#define Gal_Per_CuFoot 7.48 //Gallons per Cubic Foot
#define Inch_Per_Foot 12.0 //Inches per Foot
#define Foot_Per_Yard 3.0 //Feet per yard
#define PI 3.14159    //Digits of PI

//prototypes
void printDirections (); // print the directions
float readDiameter (); // read diameter from user
float readDepth (); // read depth from user
float calcGal (float Dep, float Dia); // calculate gallons needed from dimensions given
void printResults (); // print out results for the user to see


int main()
{
    // Define variables
    float depth, //Depth of ice rink in inches
    diameter,   //Diameter of ice rink in yards
    volume;     //Amount of water in gallons

    //Get depth and diameter
    printDirections ();
    diameter = readDiameter ();
    depth = readDepth ();
    volume = calcGal(depth, diameter);

    //Display total with depth and diameter
    printf ("\n%.1f gallons of water are needed for an ice rink with\n", volume);
    printf ("\nthe depth of %.1f inches and diameter of %.1f yards\n", depth, diameter);

    return (0);

}



void printDirections ()
{
    printf ("Welcome!!\n");
    printf ("\nThis program is to calculate the amount\n");
    printf ("of water needed to fill an ice rink with given dimensions.\n");

    return;
}


float readDiameter ()
{
    float Dia;

    printf ("\nEnter the diameter in yards.\n");
    scanf ("%f", &Dia);

    return Dia;
}

float readDepth ()
{
    float Dep;

    printf ("\nEnter the depth in inches.\n");
    scanf ("%f", &Dep);

    return Dep;
}


float calcGal (float Dep, float Dia)
{
    float DiaFoot,   //Diameter of ice rink in feet
    radius,     //Radius of ice rink in feet
    Vlume,      //Volume of inc rink
    depthFeet,  //Depth of ice rink in Feet
    area;

    //Convert depth into feet
    depthFeet = Dep / Inch_Per_Foot;

    //Convert yards into feet
    DiaFoot = Foot_Per_Yard * Dia;

    //Convert diameter into radius
    radius = DiaFoot / 2.0;

    //Calculate area
    area = radius * radius * PI;

    //Calculate total volume of ice rink and water needed
    Vlume = area * depthFeet * Gal_Per_CuFoot;

    return Vlume;
}

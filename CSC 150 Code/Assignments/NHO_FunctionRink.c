// Name: Nathan O'Brien; Due Date: February 2023
// Course: CSC 150 S03 TTh 11-1215; Assignment: Program 3
// Description: This program is to take user inputs of a depth in inches and a diameter in yards
// and calculate the volume of water needed to create an ice rink with the given dimensions
// while utilizing functions.

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
void printResults (float volume, float depth, float diameter); // print out results for the user to see


int main()
{
    // Define variables
    float depth, //Depth of ice rink in inches
    diameter,   //Diameter of ice rink in yards
    volume;     //Amount of water in gallons

    printDirections();      //Print out welcome message
    diameter = readDiameter ();     //Read the diameter from the user
    depth = readDepth ();           // Read the depth from the user
    volume = calcGal (depth, diameter);     //Calculate the volume of the ice rink
    printResults(volume, depth, diameter);  //Display the results to the user

    return (0);

}

//Welcome message and explain the purpose of program
void printDirections ()
{
    printf ("Welcome!!\n");
    printf ("\nThis program is to calculate the amount\n");
    printf ("of water needed to fill an ice rink with given dimensions.\n");

    return;
}

//Read the diameter from user input
float readDiameter ()
{
    float Dia;

    printf ("\nEnter the diameter in yards.\n");
    scanf ("%f", &Dia);

    return Dia;
}

//Read the depth from user input
float readDepth ()
{
    float Dep;

    printf ("\nEnter the depth in inches.\n");
    scanf ("%f", &Dep);

    return Dep;
}

//Take the depth and diameter to determine the volume of the ice rink
float calcGal (float Dep, float Dia)
{
    float DiaFoot;   //Diameter of ice rink in feet
    float radius;     //Radius of ice rink in feet
    float Vlume;      //Volume of ice rink
    float depthFeet;  //Depth of ice rink in feet
    float area;       //Area of ice rink in feet

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

//Print the results back to the user while restating the given dimensions
void printResults (float volume, float depth, float diameter)
{
    printf ("\n%.1f gallons of water are needed for an ice rink with\n", volume);
    printf ("the depth of %.1f inches and diameter of %.1f yards\n", depth, diameter);

    return;
}

// Name: Nathan O'Brien; Due Date: April 17th, 2023
// Course: CSC 150 S03 TTh 11-1215; Assignment: Program 6
// Description: This program is to read a file and then
// output the contents within while also calculating the revenue
// and total revenue.

#include <stdio.h>

//	Function Declarations
int getBand     (FILE* spBand,
                int* stgID, float*  Cost,
                float*  Quant);
int writeRep  (FILE* spReport, int  stgID,
               float  Cost, float Quant, float Rev);
float calcRev (float   Cost, float   Quant);

int main (void)
{
//	Local Declarations
	FILE* spBand;
	FILE* spReport;

	int stgID;
	float Cost;
	int Quant;
	float Rev;


//	Statements
	printf("Begin report writing\n");
	if (!(spBand = fopen ("bands.txt", "r")))
	   {
	    printf("\aError opening band file\n");
	    return 100;
	   } // if open input

	if (!(spReport = fopen ("revenue_report.txt", "w")))
	   {
	    printf("\aError opening report file\n");
	    return 102;
	   } // if open output

	while (getBand (spBand, &stgID, &Cost, &Quant))
	   {
	    calcRev (Cost, Quant);
	    writeRep  (spReport, stgID, Cost, Quant, Rev);
	   } // while

	fclose (spBand);
	fclose (spReport);

	printf("End report writing\n");
	return 0;
}	// main



int getBand (FILE* spBand, int* stgID, float*  Cost, float*  Quant)
{
//	Local Declarations
	int ioResult;

//	Statements
	ioResult = fscanf(spBand, "%d%f%d", stgID,
	                  Cost, Quant);
	if (ioResult == EOF)
	    return 0;
	else if (ioResult != 3)
	   {
	    printf("\aError reading data\n");
	    return 0;
	   } // if
	else
	   return 1;
}	// getStu


int writeRep  (FILE* spReport, int  stgID,
               float  Cost, float Quant, float Rev)
{
//	Statements
	fprintf(spReport, "%d %.2f %d %.2f\n",
	                   stgID, Cost, Quant, Rev);
	return 0;
}	// writeStu


float calcRev (float Cost, float  Quant)
{
    float Rev;

    Rev = Cost * Quant;

    return Rev;
}

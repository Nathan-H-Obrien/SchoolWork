/*	Create a grades file for transmission to Registrar.
	   Written by:
	   Date:
*/
#include <stdio.h>

//	Function Declarations
int getRep     (FILE* spBand,
                int* stgID, float*  cost,       //Function to get the stage, cost, and quantity from file
                int*  quant);
int writeRep  (FILE* spReport, int  stgID,
               float   cost,  int quant, float rev);    //Function to print stage, cost, quantity and revenue into a file

float getRev (float cost, int quant);     //Function to calculate the revenue of a single concert.

int main (void)
{
//	Local Declarations
	FILE* spBand;
	FILE* spReport;

	int stgID;
	float cost;
	int quant;
	float rev;
    float total = 0;

//	Statements
	printf("Writing revenue report\n");
	if (!(spBand = fopen ("bands.txt", "r")))
	   {
	    printf("\aError opening bands file\n");
	    return 100;
	   } // if open input

	if (!(spReport = fopen ("Report.txt", "w")))
	   {
	    printf("\aError opening report file\n");
	    return 102;
	   } // if open output

    fprintf (spReport, "|Stg|Cost|Qty|Rev|\n");    //Give the numbers headers of stage, cost, quantity, revenue

	while (getRep (spBand, &stgID, &cost, &quant))
	   {
        rev = getRev (cost, quant);
	    writeRep  (spReport, stgID, cost, quant, rev);
	    total = total + rev;                            //Calculate the total revenue generated
	   } // while

    fprintf (spReport, "The total revenue is: %.2f\n", total);  //Print out the total revenue

	fclose (spBand);
	fclose (spReport);

	printf("Finished writing report\n");
	return 0;
}	// main


int getRep (FILE* spBand, int* stgID, float* cost,
            int*  quant)
{
//	Local Declarations
	int ioResult;

//	Statements
	ioResult = fscanf(spBand, "%d%f%d", stgID,          //Ensure that 2 ints and a float are read from the file otherwise print an error message
	                  cost, quant);
	if (ioResult == EOF)
	    return 0;
	else if (ioResult != 3)
	   {
	    printf("\aError reading data\n");
	    return 0;
	   } // if
	else
	   return 1;
}	// getRep


int writeRep  (FILE* spReport, int  stgID,
               float   cost,  int quant, float rev)
{
//	Statements
	fprintf(spReport, "%d %.2f %d %.2f\n",          //print the stage, cost, quantity and revenue to the report file
	                   stgID, cost, quant, rev);
	return 0;
}	// writeRep


float getRev (float cost, int quant)
{

    float rev;

    rev = cost * quant;

    return rev;
}

//Program to learn about file I/O
//

#include <stdio.h>


const int SENTINEL = -99;

int main()
{
    int value;  //to hold values read from user

    FILE * inFile;      // read from numbers.txt file
    FILE * outFile;     // used to store to a data.txt file

    //create a connection for input to numbers.txt
    // file is in same folder as program
    inFile = fopen ("numbers.txt", "r");
    if (!inFile)
    {
        printf ("Error opening numbers.txt, exiting program!\n");
        exit(102);
    }


    // create a connection for output to data.txt
    // this file is created in the same folder
    // as my program
   outFile = fopen ("data.txt", "w");
   printf ("Copying numbers.txt to data.txt\n");
   fprintf (outFile, "Your numbers are: \n");
    // sentinel controlled loop
    // read values from user and write them
    // to the data.txt file
    while (fscanf (inFile, " %d", &value) != EOF)
    {
        fprintf (outFile, "%d\n", value);

    }

    fclose(inFile);
    fclose(outFile);

    return 0;
}

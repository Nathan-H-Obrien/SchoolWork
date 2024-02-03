//array processing program
//04/18/2023

#include <stdio.h>
#include <stdbool.h>
#define SIZE 8

void calcAryTotalAvg (const int ary[], int size, double * total, double * avg);   //function to calculate the average and total of the array

int findHighLoc (const int ary[], int size);      //function to find the location of the largest value of the array
int findLowLoc (const int ary[], int size);       //function to find the location of the smallest value of the array
void bubbleSort (int ary[], int size);

int main()
{

    int data[SIZE];
    double total, average;
    int large_loc, small_loc;

    FILE * inFile;

    inFile = fopen ("dogs.txt", "r");
    if (!inFile)
    {
        printf ("Error opening dogs.txt!\n");
        exit (102);
    }

    for (int i = 0; i < SIZE; i++)
    {
        fscanf (inFile, " %d ", &data[i] );
    }

    for (int i = 0; i < SIZE; i++)
    {
        printf ("%5d", data[i]);
    }

    calcAryTotalAvg (data, SIZE, &total, &average);
    large_loc = findHighLoc (data, SIZE);
    small_loc = findLowLoc (data, SIZE);

    printf ("\n\nTotal:     %12.2f\n", total);
    printf ("Average:   %12.2f\n", average);
    printf ("Largest Value:%6d\n", data[large_loc]);
    printf ("Largest Location:%3d\n", large_loc);
    printf ("Smallest Value:%5d\n", data[small_loc]);
    printf ("Smallest Location:%2d\n", small_loc);


    bubbleSort (data, SIZE);
     for (int i = 0; i < SIZE; i++)
    {
        printf ("%5d", data[i]);
    }
    printf ("\n\n");

    return 0;
}

void calcAryTotalAvg (const int ary[], int size, double * total, double * avg)
{
    *total = 0;

    for (int i = 0; i < SIZE; i++)
    {
        *total = *total + ary[i];
    }
    *avg = *total / SIZE;

    return;
}

int findHighLoc (const int ary[], int size)
{
    int large_loc;

    //look through the values to find the largest
    //remember the largest value last read
    large_loc = 0;      //start with first item and move through the rest

    for (int i = 1; i < SIZE; i++)
    {   // if item 1 > 0
        if (ary[i] > ary[large_loc])
        {
            large_loc = i;
        }

    }

    return large_loc;

}

int findLowLoc (const int ary[], int size)
{
    int small_loc;

    //look through the values to find the smallest
    //remember the smallest value last read
    small_loc = 0;      //start with first item and move through the rest

    for (int i = 1; i < SIZE; i++)
    {   // if item 1 < 0
        if (ary[i] < ary[small_loc])
        {
            small_loc = i;
        }

    }

    return small_loc;
}

void bubbleSort (int ary[], int size)
{
    bool swap;
    int temp;

    //continue making passes until
    // a pass with no swaps occurs
    do
    {
        swap = false;

        //do a pass
        for (int i = 0; i < size - 1; i++)
        {
            if (ary[i] > ary[i+1])
            {
                //set swap to true when I swap to values
                temp = ary[i];
                ary[i] = ary[i+1];
                ary [1+i] = temp;
                swap = true;
            }
        }

    } while (swap == true);


}

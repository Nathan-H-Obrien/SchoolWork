// Name: Nathan O'Brien; Due Date: April 29thth, 2023
// Course: CSC 150 S03 TTh 11-1215; Assignment: Program 7
// Description: This program is to read a file and then
// enter the values into an array which then totals
// averages, finds the smallest and largest value, sorts and finds the median.

#include <stdio.h>
#include <stdbool.h>
#define SIZE 15

void calcAryTotalAvg (const int ary[], int size, double * total, double * avg);   //function to calculate the average and total of the array
void printData (const int ary[], double average, double total, int large_loc, int small_loc, int num_items);    //function to print out all of the different values
int findHighLoc (const int ary[], int size);      //function to find the location of the largest value of the array
int findLowLoc (const int ary[], int size);       //function to find the location of the smallest value of the array
void bubbleSort (int ary[], int size);          //function to sort the values into ascending value
int readData (int ary[], int max_size);         //function to read into a partially filled array from safety.txt and return items
float getMedian (const int ary[], int size);    //function to find the middle value of the sorted data
void displayData (const int ary[], int num_items);  //function to display the unsorted values

int main()
{

    int data[SIZE] = {0};
    double total, average;
    int large_loc, small_loc;
    int num_items;
    int median;

    num_items = readData (data, SIZE);

    displayData (data, num_items);

    calcAryTotalAvg (data, num_items, &total, &average);
    large_loc = findHighLoc (data, num_items);
    small_loc = findLowLoc (data, num_items);
    printData (data, average, total, large_loc, small_loc, num_items);
    return 0;
}

void calcAryTotalAvg (const int ary[], int size, double * total, double * avg)
{
    *total = 0;

    for (int i = 0; i < size; i++)
    {
        *total = *total + ary[i];
    }
    *avg = *total / size;

    return;
}

int findHighLoc (const int ary[], int size)
{
    int large_loc;

    //look through the values to find the largest
    //remember the largest value last read
    large_loc = 0;      //start with first item and move through the rest

    for (int i = 1; i < size; i++)
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

    for (int i = 1; i < size; i++)
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
//Function read up to maz_size items from dogs.txt
int readData (int ary[], int max_size)
{
    int count;
     FILE * inFile;

    inFile = fopen ("safety.txt", "r");
    if (!inFile)
    {
        printf ("Error opening safety.txt!\n");
        exit (102);
    }

    count = 0;
    while (count < max_size && (fscanf (inFile, " %d ", &ary[count]) == 1))
    {
        count++;
    }
    return count;
}

void printData (const int ary[], double average, double total, int large_loc, int small_loc, int num_items)
{
    int median;


    printf ("\n\nTotal:     %12.2f\n", total);
    printf ("Average:   %12.2f\n", average);
    printf ("Largest Value:%6d\n", ary[large_loc]);
    printf ("Largest Location:%3d\n", large_loc);
    printf ("Smallest Value:%5d\n", ary[small_loc]);
    printf ("Smallest Location:%2d\n", small_loc);


    bubbleSort (ary, num_items);
     for (int i = 0; i < num_items; i++)
    {
        printf ("%5d", ary[i]);
    }
    printf ("\n\n");

    median = getMedian (ary, num_items);

    printf ("The median is: %d", median);

    return;
}

float getMedian (const int ary[], int size)
{
    float median;

    if (size % 2 == 0)
    {
        median = (ary[size/2] + ary[size/2-1])/2.00;
    }
    else
    {
        median = ary[size/2];
    }

    return median;
}


void displayData (const int ary[], int num_items)
{
    for (int i = 0; i < num_items; i++)
    {
        printf ("%5d", ary[i]);
    }
    return;
}

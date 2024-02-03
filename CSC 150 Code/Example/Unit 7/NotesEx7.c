// Program to test the bubbleSort function

#include <stdio.h>

#define SIZE 8

void bubbleSort (int list [], int n);
void printAry (const int list[], int n);
void selectionSort (int data[], int size);

int main ()
{
    int ary[SIZE] = {27, 83, 11, 75, 62, 59, 43, 19};

    printAry(ary, SIZE);

    selectionSort(ary, SIZE);

    printAry(ary, SIZE);

    return 0;
}



/*	==================== bubbleSort ====================
	Sort list using bubble sort. Adjacent elements are
	compared and exchanged until list is ordered.
	   Pre  the list must contain at least one item
	        last contains index to last element in list
	   Post list rearranged in sequence low to high
*/
void bubbleSort (int list [], int n)
{
//	Local Declarations
	int temp;
	int i;
	int swap;

//	Statements
	// Outer loop
	do
	{
	    swap = 0;

	    // Inner loop: Bubble down one element each pass
	    for (i = 0; i < n-1; i++)
	    {
	        if (list[i]  > list[i+1])
            {
	            temp = list[i];
	            list[i] = list[i+1];
	            list[i+1] = temp;

	            swap = 1;
            } // if
	    }
    } while (swap == 1);

	return;
}	// bubbleSort


/*	==================== printAry ====================
	Print the array elements, with a space between each one
*/
void printAry (const int list[], int n)
{
    int i;

    for (i=0; i < n; i++)
    {
        printf("%d ", list[i]);
    }
    printf("\n");

    return;
}


void selectionSort (int data[], int size)
{
    int wall, smallest, small_loc, i;

    for (wall=0; wall < size-1; wall++)
    {
        smallest = data[wall];
        small_loc = wall;
        for (i=wall+1; i < size; i++)
        {
            if (data[i] < smallest)
            {
                smallest = data[i];
                small_loc = i;
            }
        }

        // finish the swap
        data[small_loc] = data[wall];
        data[wall] = smallest;
    }
}

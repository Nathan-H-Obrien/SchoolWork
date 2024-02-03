/* **********************************************************************
 * ***                                                                ***
 * ***     NAME     : Nathan O'Brien                                  ***
 * ***     ASSIGN # : 3                                               ***
 * ***     DUE DATE : June 14th, 2023                                 ***
 * ***     CLASS    :  CSC 250                                        ***
 * ***     INSTR    :  HAMER                                          ***
 * ***                                                                ***
 * **********************************************************************
 * ***                                                                ***
 * ***     PROGRAM DESCRIPTION : This program is meant sort an array  ***
 * ***     of names by using selection sort and then find a given     ***
 * ***     name from the user. This name is to be found by using      ***
 * ***     binary search.                                             ***
 * *********************************************************************/

#include <iostream>
#include <string>
using namespace std;

// Function prototype
int binarySearch(string[], int, string);    //function to search the array through binary search
void selectionSort(string[], int);          //function to sort the names into order
string getValue();                          //function to search for a wanted name

int main()
{
    const int SIZE = 20;
    string names[SIZE] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
                                  "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
                             "Taylor, Terri", "Johnson, Jill",
                                  "Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
                            "James, Jean", "Weaver, Jim", "Pore, Bob",
                             "Rutherford, Greg", "Javens, Renee",
                            "Harrison, Rose", "Setzer, Cathy",
                            "Pike, Gordon", "Holland, Beth" };

	string value;
	int result;

	selectionSort(names, SIZE);

	value = getValue();

	result = binarySearch(names, SIZE, value);

	if (result == -1)
		cout << "Name is not in list.\n";
	else
		cout << names[result] << " was found in subscript #" << result << ".\n";

	return 0;
}
//function to sort the array into order
void selectionSort(string array[], int size)
{
    int minIndex;
    string minValue;

    for (int start = 0; start < (size - 1); start++)
    {
       minIndex = start;
       minValue = array[start];
       for (int index = start + 1; index < size; index++)
      {
          if (array[index] < minValue)                  //find the lowest value of the array
          {
             minValue = array[index];
             minIndex = index;
          }
       }
       swap(array[minIndex], array[start]);     //swap the components of the array
    }
}
//function to search for a wanted name
string getValue()
{
	string input;
	cout << "Enter the name you would like to search for: ";
	getline(cin, input);
	return input;
}


int binarySearch(string array[], int size, string value)
{
	int first = 0,						// First array element
		last = size - 1,				// Last array element
		middle,							// Midpoint of search
		position = -1;					// Position of search value
	bool found = false;					// Flag

	while (!found && first <= last)
	{
		middle = (first + last) / 2; 	// Calculate midpoint
		if (array[middle] == value)		// If value is found at mid
		{
			found = true;
			position = middle;
		}
		else if (array[middle] > value) // If value is in lower half
			last = middle - 1;
		else
			first = middle + 1;			// If value is in upper half
	}
	return position;
}

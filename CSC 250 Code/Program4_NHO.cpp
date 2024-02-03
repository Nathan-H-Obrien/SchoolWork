/* **********************************************************************
 * ***                                                                ***
 * ***     NAME     : Nathan O'Brien                                  ***
 * ***     ASSIGN # : 4                                               ***
 * ***     DUE DATE : June 19th, 2023                                 ***
 * ***     CLASS    :  CSC 250                                        ***
 * ***     INSTR    :  HAMER                                          ***
 * ***                                                                ***
 * **********************************************************************
 * ***                                                                ***
 * ***     PROGRAM DESCRIPTION : This program is to read a file for   ***
 * ***     an integer which will then set the size of an array which  ***
 * ***     will then store long long ints into the array which will   ***
 * ***     then be sorted into ascending order which will then will   ***
 * ***     allow the user to search for the value they want through   ***
 * ***     binary search.                                             ***
 * *********************************************************************/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//Function prototype
int binarySearch(long long[], int, long long);    //function to search the array through binary search
void selectionSort(long long[], int);          //function to sort the names into order
long long getValue();                          //function to get the value from the user
int readData();                                //function to read the first value of the file for size
long long storeData(int);                      //function to allocate memory for an array
int main()
{

    int SIZE;
    SIZE = readData();
    SIZE++;
    storeData(SIZE);

    return 0;

}

//function to sort the array into order
void selectionSort(long long array[], int SIZE)
{
    long long minIndex;
    long long minValue;

    for (long long start = 0; start < (SIZE - 1); start++)
    {
       minIndex = start;
       minValue = array[start];
       for (long long index = start + 1; index < SIZE; index++)
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
//function to search the array through binary search
int binarySearch(long long array[], int SIZE, long long value)
{
	int first = 0;						// First array element
    int last = SIZE - 1;				// Last array element
	int	middle;							// Midpoint of search
    int position = -1;					// Position of search value
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
//function to get value from user and store it
long long getValue()
{
	long long input;
	cout << "Enter the ISBN you would like to search for: ";
	cin >> input;
	return input;
}
//function to read the first value of the file for size
int readData()
{
    int size;
    ifstream myfile;
    myfile.open("books.txt");
    myfile >> size;
    myfile.close();
    return size;
}
//function to allocate memory for an array
long long storeData(int SIZE)
{
    long long value;
    long long* myIBSNS = new long long[SIZE];   //creates a dynamic array to store values
    int result;
    ifstream myfile;
    myfile.open("books.txt");               //opens file
  for (int j = 0; j< SIZE; j++)             //scans file and stores values into the array
    {
      myfile >> myIBSNS[j];
    }
    myfile.close();                         //close file
    selectionSort(myIBSNS, SIZE);
    value = getValue();
    result = binarySearch(myIBSNS, SIZE, value);
    if (result == -1)
		cout << "ISBN is not in list.\n";
	else
		cout << myIBSNS[result] << " was found in subscript #" << result << endl;       //display if the value was found or not within the list
    delete [] myIBSNS;                      // deletes the dynamic array

  return 0;
}

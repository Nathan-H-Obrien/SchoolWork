/* *******************************************************************
 * ***                                                                ***
 * ***     NAME     : Nathan O'Brien                                  ***
 * ***     ASSIGN # : 1                                               ***
 * ***     DUE DATE : June 4th, 2023                                  ***
 * ***     CLASS    :  CSC 250                                        ***
 * ***     INSTR    :  HAMER                                          ***
 * ***                                                                ***
 * **********************************************************************
 * ***                                                                ***
 * ***     PROGRAM DESCRIPTION : This program is to read a file and   ***
 * ***  then enter the temperatures into an array which will then     ***
 * ***  allow the user to search for a temperature and sort them in   ***
 * ***  ascending order while also displaying the average temperature.***
 * *********************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
//#include <cstdlib>
//#include <cstdbool>
using namespace std;

const int SIZE = 150;

void calcAryTotalAvg (int ary[], int size, double &avg);   //function to calculate the average and total of the array
void bubbleSort (int ary[], int size);          //function to sort the values into ascending value
void readData (int ary[], int max_size, int &count);         //function to read into a partially filled array from temps.txt and return items
float getTemp (int ary[], int num_items, int userTemp);    //function to find wanted temperature from the user
void displayData (int ary[], int num_items);  //function to display the unsorted values
void printData (int ary[], double average, int num_items); //function to print out the data

int main()
{
    int count = 0;
    int data[SIZE] = {0};
    double average;
    int num_items;
    int userTemp;

    readData (data, SIZE, count);
    printData (data, average, count);
    calcAryTotalAvg (data, count, average);
    return 0;
}

void calcAryTotalAvg (int ary[], int size, double &avg)
{
    double total = 0;

    for (int i = 0; i < size; i++)
    {
        total = total + ary[i];
    }
    avg = total / size;

    cout << setprecision (2) << fixed << ("The average temperature is: ") << avg;

    return;
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
                //set swap to true when I swap two values
                temp = ary[i];
                ary[i] = ary[i+1];
                ary [1+i] = temp;
                swap = true;
            }
        }

    } while (swap == true);


}
//Function read up to max_size items from temps.txt
void readData (int ary[], int max_size, int& count)
{

  ifstream fin;
  int value;

  fin.open("Temps.txt");
  while(fin>>value){
    ary[count++]=value;
    if(count==SIZE)break;
  }
  if(count==SIZE)
    cout <<"Warning more data in file than the array can handle"<<endl;
  fin.close();
}

void printData (int ary[], double average, int num_items)
{
    float temp, userTemp;

    cout << ("Enter a temperature you wish to find!") << endl;
    cin >> userTemp;


    bubbleSort (ary, num_items);
     for (int i = 0; i < num_items; i = num_items)
   {
    for (int i = 0; i < num_items; i++)
    {
        if (i % 5 == 0)
        {
            cout << endl;
            cout << left << setw (3) << ("%d", ary[i]);
        }
        else
        {
        cout << left << setw (3) << ("%d", ary[i]);
        }
    }
    }
    cout << endl;

    temp = getTemp (ary, num_items, userTemp);

    if (temp == -1)
    {
        cout << "Temperature was not found in the data set" << endl;
    }
    else
    {
        cout << "Temperature was found in the data set" << endl;
    }


    return;
}

float getTemp (int ary[], int num_items, int userTemp)
{
    for (int i = 0; i < num_items; i++)
    {
        if (ary[i] == userTemp)
            return i;
    }
        return -1;
}

void displayData (int ary[], int num_items)
{

   for (int i = 0; i < num_items; i = num_items)
   {
    for (int i = 0; i < num_items; i++)
    {
        if (i % 5 == 0)
        {
            cout << endl;
            cout << left << setw (3) << ("%d", ary[i]);
        }
        else
        {
        cout << left << setw (3) << ("%d", ary[i]);
        }
    }
    }
    cout << endl;
    return;

}

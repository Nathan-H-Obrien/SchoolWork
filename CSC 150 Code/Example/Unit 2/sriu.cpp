#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

const int ROWS = 5, COLS = 7;
int sumArray (int myArray [][7], const int ROWS, const int COLS);

int main()
{
    int myArray[ROWS][COLS];

    cout << sumArray(myArray, ROWS, COLS);

    return 0;
}

int sumArray (int myArray[][7], const int ROWS, const int COLS)
{
    int total;

    for (int row = 0; row < ROWS; row++)
 {
   for (int col = 0; col < COLS; col++)
    total += myArray[row][col];
 }
    return total;
}

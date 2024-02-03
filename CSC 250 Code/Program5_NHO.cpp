/* **********************************************************************
 * ***                                                                ***
 * ***     NAME     : Nathan O'Brien                                  ***
 * ***     ASSIGN # : 5                                               ***
 * ***     DUE DATE : June 22nd, 2023                                 ***
 * ***     CLASS    :  CSC 250                                        ***
 * ***     INSTR    :  HAMER                                          ***
 * ***                                                                ***
 * **********************************************************************
 * ***                                                                ***
 * ***     PROGRAM DESCRIPTION : This program is to take in the       ***
 * ***     user's first, middle and last name into an array which     ***
 * ***     it will then store into a fourth array in the order of     ***
 * ***     last, first middle and display it to the user.             ***
 * *********************************************************************/

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

const int SIZE = 100;

int main()
{
	string First[SIZE], Middle[SIZE], Last[SIZE], FullName[SIZE];     //creates arrays for the user's name

	// Ask for user's first, middle and last name.
	cout << "Enter your first name: ";
    getline(cin, First);
	cout << "Enter your middle name: ";
	cin  >> Middle;
	cout << "Enter your Last name: ";
	cin  >> Last;

	strcpy(FullName, Last);     //copy the user's last name into the Name array
	strcat(FullName, ", ");
	strcat(FullName, First);    //copy the user's first name into the Name array
	strcat(FullName, " ");
	strcat(FullName, Middle);   //copy the user's middle name into the Name array

	cout << endl << FullName << endl;       //display the user's full name to the screen in last, first middle

	return 0;
}

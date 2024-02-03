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
 * ***     PROGRAM DESCRIPTION : This program is meant to create an   ***
 * ***     array of structures for the given number of students. It   ***
 * ***     will then allocate memory for an array which will hold the ***
 * ***     test scores of the given students. It will then find the   ***
 * ***     average and the student's grade which will then display to ***
 * ***     the screen for the user.                                   ***
 * *********************************************************************/

#include <iostream>
#include <string>
using namespace std;

struct StudentInfo
{
    string stdName;
    int stdID;
    int *stdTest;
    float stdAvg;
    char stdGrade;
};

void getData ();                    //function to get data from the user
void getGrade(StudentInfo *, int);  //function to find the grade of the student


int main()
{
    getData();
}
//function to get data from the user
void getData()
{
    int SIZE;
    int TESTS;
    int total;

    cout << "How many students are there? ";
    cin >> SIZE;

    cout << endl << "How many tests are there? ";
    cin >> TESTS;

    StudentInfo *stdptr = nullptr;
    stdptr = new StudentInfo[SIZE];     //allocate an array of structures for each student

    for (int i = 0; i < SIZE; i++)
    {
        stdptr[i].stdTest = new int[TESTS];     //allocate an array for the tests scores for each student

        //prompt the user to enter the student's name and store the name into the structure
        cout << endl << "Student " << i + 1 << "'s name: ";
        cin.ignore();
        getline(cin, stdptr[i].stdName);

        //prompt the user to enter the student's ID and store the ID into the structure
        cout << endl << "Student " << i + 1 << "'s ID: ";
        cin >> stdptr[i].stdID;

    total = 0;  //set the total to zero after each pass

    for (int j = 0; j < TESTS; j++)
    {
        //prompt the user to enter the student's test scores and store the scores into the structure
        cout << endl << "Enter student " << i + 1 << "'s " << j + 1 << " test score: ";
        cin >> (*(stdptr + i)).stdTest[j];

        total += (*(stdptr + i)).stdTest[j];
    }

    (stdptr + i)->stdAvg = (total / TESTS); //use the total and amount of tests to find the average and store the average into the structure

    getGrade(stdptr, i);

    }

    //print out all the information of the students to the user
    for (int i = 0; i < SIZE; i++)
	{
		cout << endl << "Student " << (i + 1) << endl;
		cout << "Name: " << (stdptr + i)->stdName << endl;
		cout << "ID: " << (stdptr + i)->stdID << endl;
		cout << "Average Test Score: " << (stdptr + i)->stdAvg << endl;
		cout << "Course Grade: " << (stdptr + i)->stdGrade << endl;
    }

    delete[] stdptr;
}
//function to find the grade of the student
void getGrade(StudentInfo *stdptr, int student)
{
    char grade;

    //uses a pointer to the structure to store the grade into the structure
    if ((stdptr + student)->stdAvg >= 91 && (stdptr + student)->stdAvg <= 100)
		(stdptr + student)->stdGrade = 'A';

	else if ((stdptr + student)->stdAvg >= 81 && (stdptr + student)->stdAvg <= 90)
		(stdptr + student)->stdGrade = 'B';

    else if ((stdptr + student)->stdAvg >= 71 && (stdptr + student)->stdAvg <= 80)
		(stdptr + student)->stdGrade = 'C';

    else if ((stdptr + student)->stdAvg >= 61 && (stdptr + student)->stdAvg <= 70)
		(stdptr + student)->stdGrade = 'D';

    else if ((stdptr + student)->stdAvg >= 0 && (stdptr + student)->stdAvg <= 60)
		(stdptr + student)->stdGrade = 'F';
}

/*********************************************************************
 * ***                                                                ***
 * ***     NAME     : Nathan O'Brien                                  ***
 * ***     ASSIGN # : 2                                               ***
 * ***     DUE DATE : June 11th, 2023                                  ***
 * ***     CLASS    :  CSC 250                                        ***
 * ***     INSTR    :  HAMER                                          ***
 * ***                                                                ***
 * **********************************************************************
 * ***                                                                ***
 * ***     PROGRAM DESCRIPTION : This program is to read inputs from  ***
 * ***  the user which will then store them into an array then it     ***
 * ***  will calculate from the inputs the averages of the numbers    ***
 * ***  inputted to find the students grade.                         .***
 * *********************************************************************/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void getAvg_Grd (string names[], double score[][4], char grades[]);     //function to find the average score and find the letter grade; display results to user
void getData (string names[], double score[][4]);                       // function to get the data from user input and store the data into the correct array

int main()
{
    string Names[5];    //array to hold strings for names
    char Grades[5];     //array to hold characters for grades
    double Scores[5][4];    //array with 5 rows and 4 columns

    getData (Names, Scores);
    getAvg_Grd (Names, Scores, Grades);


    return 0;
}

// function to get the data from user input and store the data into the correct array
void getData (string names[], double score[][4])
{
    //loop to store five names into the names array
    for (int i = 0; i < 5; i++)
    {
        cout << ("Enter student's name: ");
        //storing the user input into the Names array
        cin >> names[i];
    //loop to store the given students test scores
        for (int k = 0; k < 4; k++)
            do
        {
            cout << "Enter student's test " << k+1 << " score: ";
            //storing the user input into the students name by using a 2D array
            cin >> score[i][k];
        }   while (score[i][k] > 100 || score[i][k] < 0);   //ensure that the score entered falls within 0 and 100
    }
    return;
}

//function to find the average score and find the letter grade; display results to user
void getAvg_Grd (string names[], double score[][4], char grades[])
{
    //
    for (int i = 0; i < 5; i++)
    {
        double avg = 0;
        //loop to find the average which each of the 5 students
        for (int k = 0; k < 4; k++)

            avg += score[i][k];
            avg /= 4;
            //if statement to sort the avg to find the correct letter grade
            if (avg <= 100 && avg >= 90) grades[i] = 'A';
            if (avg < 90 && avg >= 80) grades[i] = 'B';
            if (avg < 80 && avg >= 70) grades[i] = 'C';
            if (avg < 70 && avg >= 60) grades[i] = 'D';
            if (avg < 60 && avg >= 0) grades[i] = 'F';
            //display the results to the user
            cout << names[i] << " got an average of: " << avg << " and a letter grade of: " << grades[i] << endl;

    }

    return;
}

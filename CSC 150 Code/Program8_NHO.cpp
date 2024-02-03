/* ***********************************************************************
 * ***                                                                 ***
 * ***     NAME     : Nathan O'Brien                                   ***
 * ***     ASSIGN # : 7                                                ***
 * ***     DUE DATE : July 6th, 2023                                   ***
 * ***     CLASS    :  CSC 250                                         ***
 * ***     INSTR    :  HAMER                                           ***
 * ***                                                                 ***
 * ***********************************************************************
 * ***                                                                 ***
 * ***     PROGRAM DESCRIPTION : This program is meant to create a     ***
 * ***     class which will be able to store length and width through  ***
 * ***     its member functions. It will get the length and width      ***
 * ***     from the user which it will then take the values given and  ***
 * ***     find the area of the room and total all of the areas of the ***
 * ***     rooms and display the total to the user.                    ***
 * **********************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

class Room
{
    private:            //sets the length and width private to ensure that only member function can access them
        double length;
        double width;
    public:             //sets the member function public to ensure that the private variables can be altered
        void setWidth(double);
        void setLength(double);
        double getWidth() const;
        double getLength() const;
        double getArea() const;
};

void getData(); //function to get the data from the user

int main()
{
    getData();
}

void Room::setWidth(double w)   //passes in a float value into the member function to store the value into width
{
      width = w;
}

void Room::setLength(double len)    //passes in a float value into the member function to store the value into length
{
      length = len;
}


double Room::getArea()  const       //uses the width and length to find the area; doesn't store the value to ensure no stale data
{
      return width * length;
}
//function to get the data from the user
void getData()
{
    Room *bedroom = nullptr;    //creates a pointer for bedroom and makes it a nullptr
    Room *kitchen = nullptr;    //creates a pointer for kitchen and makes it a nullptr
    Room *den = nullptr;        //creates a pointer for den and makes it a nullptr
    Room *bathroom = nullptr;   //creates a pointer for bathroom and makes it a nullptr
    double totalArea, holder;   //create variables to hold the total area and the inputs from the user

    bedroom = new Room;         //dynamically allocate memory for bedroom
    kitchen = new Room;         //dynamically allocate memory for kitchen
    den = new Room;             //dynamically allocate memory for den
    bathroom = new Room;        //dynamically allocate memory for bathroom


    cout << "What is the length of the bedroom? ";  //prompt the user to enter the bedroom length
    cin >> holder;                                  //store the length in the holder variable
    bedroom->setLength(holder);                     //store the length into the class variable for length
    cout << "What is the width of the bedroom? ";   //prompt the user to enter the bedroom width
    cin >> holder;                                  //store the length in the holder variable
    bedroom->setWidth(holder);                      //store the length into the class variable for width

    cout << "What is the length of the kitchen? ";  //prompt the user to enter the kitchen length
    cin >> holder;                                  //store the length in the holder variable
    kitchen->setLength(holder);                     //store the length into the class variable for length
    cout << "What is the width of the kitchen? ";   //prompt the user to enter the kitchen width
    cin >> holder;                                  //store the width in the holder variable
    kitchen->setWidth(holder);                      //store the width into the class variable for width

    cout << "What is the length of the den? ";      //prompt the user to enter the den length
    cin >> holder;                                  //store the length in the holder variable
    den->setLength(holder);                         //store the length into the class variable for length
    cout << "What is the width of the den? ";       //prompt the user to enter the den width
    cin >> holder;                                  //store the width in the holder variable
    den->setWidth(holder);                          //store the width into the class variable for width

    cout << "What is the length of the bathroom? "; //prompt the user to enter the bathroom length
    cin >> holder;                                  //store the length in the holder variable
    bathroom->setLength(holder);                    //store the length into the class variable for length
    cout << "What is the width of the bathroom? ";  //prompt the user to enter the bathroom width
    cin >> holder;                                  //store the width in the holder variable
    bathroom->setWidth(holder);                     //store the width into the class variable for width

    totalArea = bathroom->getArea() + bedroom->getArea() +      //calculates the total area of the house
                kitchen->getArea() + den->getArea();

    cout << "The total area of the house is: " << totalArea;    //displays the total area of the house to the user

    delete kitchen;     //deletes the dynamically allocate memory for kitchen
    delete bedroom;     //deletes the dynamically allocate memory for bedroom
    delete bathroom;    //deletes the dynamically allocate memory for bathroom
    delete den;         //deletes the dynamically allocate memory for den

    kitchen = nullptr;      //makes the kitchen pointer back into a nullptr
    bedroom = nullptr;      //makes the bedroom pointer back into a nullptr
    bathroom = nullptr;     //makes the bathroom pointer back into a nullptr
    den = nullptr;          //makes the den pointer back into a nullptr

}

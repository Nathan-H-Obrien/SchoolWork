/* ***********************************************************************
 * ***                                                                 ***
 * ***     NAME     : Nathan O'Brien                                   ***
 * ***     ASSIGN # : 8c                                               ***
 * ***     DUE DATE : July 14th, 2023                                  ***
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
#include "Room_C.h"
using namespace std;

void getRoom(string roomName, Room *room);
void getData(); //function to get the data from the user

int main()
{
    getData();
}

Room::Room() : width(w), length(len)
    {

    }


//function to get the data from the user
void getData()
{
    Room *bedroom = nullptr;         //creates a pointer for bedroom and makes it a nullptr
    Room *kitchen = nullptr;         //creates a pointer for kitchen and makes it a nullptr
    Room *den = nullptr;             //creates a pointer for den and makes it a nullptr
    Room *bathroom = nullptr;        //creates a pointer for bathroom and makes it a nullptr
    Room *guestBathroom = nullptr;   //creates a pointer for guest bathroom and makes it a nullptr
    Room *guestBedroom = nullptr;    //creates a pointer for guest bedroom and makes it a nullptr
    double totalArea, holder;        //create variables to hold the total area and the inputs from the user

    bedroom = new Room;         //dynamically allocate memory for bedroom
    kitchen = new Room;         //dynamically allocate memory for kitchen
    den = new Room;             //dynamically allocate memory for den
    bathroom = new Room;        //dynamically allocate memory for bathroom
    guestBathroom = new Room;   //dynamically allocate memory for guest bathroom
    guestBedroom = new Room;   //dynamically allocate memory for guest bedroom

    getRoom("bedroom", bedroom);
    getRoom("kitchen", kitchen);
    getRoom("den", den);
    getRoom("bathroom", bathroom);
    getRoom("guest bathroom", guestBathroom);
    getRoom("guest bedroom", guestBedroom);

    totalArea = bathroom->getArea() + bedroom->getArea() +      //calculates the total area of the house
                kitchen->getArea() + den->getArea() +
                guestBathroom->getArea() + guestBedroom->getArea();

    cout << "The total area of the house is: " << totalArea;    //displays the total area of the house to the user

    delete kitchen;         //deletes the dynamically allocated memory for kitchen
    delete bedroom;         //deletes the dynamically allocated memory for bedroom
    delete bathroom;        //deletes the dynamically allocated memory for bathroom
    delete den;             //deletes the dynamically allocated memory for den
    delete guestBathroom;   //deletes the dynamically allocated memory for guest bathroom
    delete guestBedroom;    //deletes the dynamically allocated memory for guest bedroom

    kitchen = nullptr;          //makes the kitchen pointer back into a nullptr
    bedroom = nullptr;          //makes the bedroom pointer back into a nullptr
    bathroom = nullptr;         //makes the bathroom pointer back into a nullptr
    den = nullptr;              //makes the den pointer back into a nullptr
    guestBathroom = nullptr;    //makes the guest bathroom pointer back into a nullptr
    guestBedroom = nullptr;     //makes the guest bedroom pointer back into a nullptr

}



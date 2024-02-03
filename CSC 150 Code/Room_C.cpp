#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Room_C.h"
using namespace std;

void getRoom(string roomName, Room *room)
{
    double holder;

    cout << "What is the length of the " << roomName << "? ";
    cin >> holder;
    room->setLength(holder);
    cout << "What is the width of the " << roomName << "? ";
    cin >> holder;
    room->setWidth(holder);
}

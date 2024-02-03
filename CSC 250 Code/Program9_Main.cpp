/* ***********************************************************************
 * ***                                                                 ***
 * ***     NAME     : Nathan O'Brien                                   ***
 * ***     ASSIGN # : 9                                                ***
 * ***     DUE DATE : July 24th, 2023                                  ***
 * ***     CLASS    :  CSC 250                                         ***
 * ***     INSTR    :  HAMER                                           ***
 * ***                                                                 ***
 * ***********************************************************************
 * ***                                                                 ***
 * ***     PROGRAM DESCRIPTION : This program is meant to create a     ***
 * ***     linked list which is there copied into a new list which     ***
 * ***     should show all the different operations possible such as   ***
 * ***     append, insertion, deletion and reversing the order.        ***
 * **********************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Program9_Header.h"
using namespace std;

int main()
{
    // Creating object l1 of linked list
    IntList l1;

    l1.appendNode(1.1);
    l1.appendNode(9.3);
    l1.appendNode(5.6);
    l1.appendNode(7.3);

    cout << "Linked list 1:" << endl;
    l1.displayList();

    // Copying l1 into l2
    IntList l2 = l1;
    cout << "Linked list 2:" << endl;
    l2.displayList();
    l2.insertNode(3.7);     //insert a 3 into the list
    cout << "Linked list 2 with inserted 3:" << endl;
    l2.displayList();
    l2.deleteNode(5.2);    //delete node with the value of 5 from the list
    cout << "Linked list 2 with a deleted node:" << endl;
    l2.displayList();
    l2.reverseList();   //reverse list to where last node is the first node
    cout << "Linked list 2 in reverse order:" << endl;
    l2.displayList();
    l1.displayList();

    return 0;
}

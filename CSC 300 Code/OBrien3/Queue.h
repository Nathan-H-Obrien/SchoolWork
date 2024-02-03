/* ***********************************************************************
 * ***                                                                 ***
 * ***     NAME     : Nathan O'Brien                                   ***
 * ***     ASSIGN # : 3                                                ***
 * ***     DUE DATE : October 18th, 2023                               ***
 * ***     CLASS    :  CSC 300                                         ***
 * ***     INSTR    :  Gamradt                                         ***
 * ***                                                                 ***
 * ***********************************************************************
 * ***                                                                 ***
 * ***     PROGRAM DESCRIPTION : This program is meant to create a     ***
 * ***     circular queue that allows the user to enqueue an element,  ***
 * ***     dequeue an element and view the queue                       ***
 * **********************************************************************/

// General description of the ADT and supported operations – exportable operations only
// Do not include any implementation details
#ifndef _QUEUE_H // Guard
#define _QUEUE_H
#include <iostream>
#include <iomanip>
#include <string>
typedef int Element;
typedef Element * ElementPtr;
class Queue 
{
public: // exportable
// General description of each of the ADT operations/functions – exportable operations only
explicit Queue( const short size = 3); //create default queue with a size of 3 or creates a user defined sized queue
Queue( Queue & ); // copy constructor that utilizes enqueue and dequeue to copy a queue into another
~Queue(); // destructor that utilizes dequeue to deallocate any memory used for the queue
void enqueue( const Element );  // function to store an element into the tail of the queue
void dequeue( Element & );  // function to remove an element from the head of the queue
void view(); // function to display the queue to the user that utilizes enqueue and dequeue to keep data in the queue
private: // non-exportable
// No private member documentation – implementation details are hidden/abstracted away
const short QUEUE_SIZE; // requires initialization
ElementPtr queueArray;
short head, tail;
bool isEmpty() const;
bool isFull() const;
};
#endif // Guard
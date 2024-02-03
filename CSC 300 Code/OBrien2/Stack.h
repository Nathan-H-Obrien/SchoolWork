/* ***********************************************************************
 * ***                                                                 ***
 * ***     NAME     : Nathan O'Brien                                   ***
 * ***     ASSIGN # : 2                                                ***
 * ***     DUE DATE : October 6th, 2023                                ***
 * ***     CLASS    :  CSC 300                                         ***
 * ***     INSTR    :  Gamradt                                         ***
 * ***                                                                 ***
 * ***********************************************************************
 * ***                                                                 ***
 * ***     PROGRAM DESCRIPTION : This program is meant to create a     ***
 * ***     stack that allows the user to push an element to the stack, ***
 * ***     pop an element from the stack, see the top element of the   ***
 * ***     stack, or display the current stack                         ***
 * **********************************************************************/

// General description of the ADT and supported operations – exportable operations only
// Do not include any implementation details
#ifndef _STACK_H // Guard
#define _STACK_H
#include <iostream>
#include <iomanip>
#include <iostream>
#include <string>
typedef std::string Element;
typedef Element * ElementPtr;
class Stack {
public: // exportable
// General description of each of the ADT operations/methods/functions – exportable operations only
explicit Stack( const int value = 2);   //creates a default stack of a size of two or allows the user to input stack size
Stack( Stack & );   //constructor that copies on stack into another
~Stack();   //destructor meant to delete elements that are popped and to delete stacks when finished
void push( const Element );     //push elements into the stack and give feedback if stack is full
Element pop( );     //pop elements out of the stack and give feedback if stack is empty
Element peek( );    //display the top element of the stack to the user without deleting the element
void view( );       //displat the entire stack to the user while also preserving the stack
private: // non-exportable
// No private member documentation – implementation details are hidden/abstracted away
const int STACK_SIZE; // requires initialization
ElementPtr stackArray;
int top;
};
#endif // Guard
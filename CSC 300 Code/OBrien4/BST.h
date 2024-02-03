/* ***********************************************************************
 * ***                                                                 ***
 * ***     NAME     : Nathan O'Brien                                   ***
 * ***     ASSIGN # : 4                                                ***
 * ***     DUE DATE : November 8th, 2023                               ***
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
#pragma once // alternative Guard format
#include <iostream>
#include <iomanip>
#include <string>
typedef int Element;
struct Node;
typedef Node * NodePtr;
struct Node {
Element element;
NodePtr left, right;
};
class BST {
public: // exportable
// General description of each of the ADT operations/functions – exportable operations only
BST();  //default constructor
BST( const BST & ); //copy constructor
~BST(); //destructor
void insert( const Element );   // function to insert a value
void remove( const Element );   // function to remove a value
NodePtr search( const Element ) const;  // function to search for a value
void preorderView() const;  // display BST in preorder
void inorderView() const;   // display BST inorder
void postorderView() const; // display BST in postorder
private: // non-exportable
// No private member documentation – implementation details are hidden/abstracted away
NodePtr root;
void copy( const NodePtr );
void destroy( NodePtr & );
void removeNode( NodePtr & );
void findMaxNode( NodePtr &, NodePtr & );
void insert( NodePtr &, const Element );
void remove( NodePtr &, const Element);
NodePtr search( const NodePtr, const Element) const;
void preorderView( const NodePtr ) const;
void inorderView( const NodePtr ) const;
void postorderView( const NodePtr ) const;
};
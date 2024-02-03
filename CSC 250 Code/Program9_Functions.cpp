#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Program9_Header.h"
using namespace std;


void IntList::appendNode(const Element x)
    {
        // Allocate the temp Node and
        // put x as data into it
        Node* temp = new Node(x);

        // Check if the head is NULL
        if (head == NULL) {
            head = temp;
            return;
        }
        else {
            Node* t = head;
            while (t->next != NULL) {
                t = t->next;
            }
            t->next = temp;
        }
    }

void IntList::displayList() const
{
      float count = 0;
      Node *nodePtr; // To move through the list

      // Position nodePtr at the head of the list.
      nodePtr = head;

      // While nodePtr points to a node, traverse
      // the list.
      while (nodePtr)
      {
          // Display the value in this node.
          cout << nodePtr->value << " is in node: " << count << endl;
          count++;

          // Move to the next node.
          nodePtr = nodePtr->next;
      }
}

void IntList::insertNode(const Element num)
{
      Node *newNode;                // A new node
      Node *nodePtr;                // To traverse the list
      Node *previousNode = nullptr; // The previous node

      // Allocate a new node and store num there.
      newNode = new Node(num);
      newNode->value = num;

      // If there are no nodes in the list
      // make newNode the first node
      if (!head)
      {
          head = newNode;
          newNode->next = nullptr;
      }
      else // Otherwise, insert newNode
      {
          // Position nodePtr at the head of list.
          nodePtr = head;

          // Initialize previousNode to nullptr.
          previousNode = nullptr;

          // Skip all nodes whose value is less than num.
          while (nodePtr != nullptr && nodePtr->value < num)
          {
              previousNode = nodePtr;
              nodePtr = nodePtr->next;
          }

          // If the new node is to be the 1st in the list,
          // insert it before all other nodes.
          if (previousNode == nullptr)
          {
              head = newNode;
              newNode->next = nodePtr;
          }
          else // Otherwise insert after the previous node.
          {
              previousNode->next = newNode;
              newNode->next = nodePtr;
          }
      }
}

void IntList::deleteNode(const Element num)
{
      Node *nodePtr;      // To traverse the list
      Node *previousNode;  // To point to the previous node

      // If the list is empty, do nothing.
      if (!head)
          return;

      // Determine if the first node is the one.
      if (head->value == num)
      {
          nodePtr = head->next;
          delete head;
          head = nodePtr;
      }
      else
      {
          // Initialize nodePtr to head of list
          nodePtr = head;

          // Skip all nodes whose value member is
          // not equal to num.
          while (nodePtr != nullptr && nodePtr->value != num)
          {
              previousNode = nodePtr;
              nodePtr = nodePtr->next;
          }

          // If nodePtr is not at the end of the list,
          // link the previous node to the node after
          // nodePtr, then delete nodePtr.
          if (nodePtr)
          {
              previousNode->next = nodePtr->next;
              delete nodePtr;
          }
      }
}

void IntList::reverseList()
{
    Node *current = head;   //initialize current pointer
    Node *prev = NULL;      //initialize previous pointer
    Node *next = NULL;      //initialize next pointer

    while (current != NULL)
    {
        next = current->next;   //store next
        current->next = prev;   //swap current node's pointer
        prev = current;         //move pointer one position ahead
        current = next;         //move pointer one position ahead
    }
    head = prev;
}

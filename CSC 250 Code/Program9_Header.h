#ifndef Program9_Header_H
#define Program9_Header_H

typedef float Element;

class Node {
public:
    Element value;
    Node* next;
    Node(Element x)
    {
        value = x;
        next = NULL;
    }
};

// A linked list class
class IntList {

public:
    // Non-parameterized constructor
    IntList() { head = tail = NULL; }

    // Copy constructor to copy the data
    // members of one list into another
    IntList(const IntList& list)
    {
        if (list.head == NULL) {
            head = tail = NULL;
            return;
        }

        // Make a Node pointer temp and
        // initialize it to the head of list
        Node* temp = list.head;

        // This loop is creating the new
        // linked list by copying the
        // data of list
        while (temp != NULL) {
            Node* newNode = new Node(temp->value);

            if (head == NULL) {
                head = newNode;
                tail = newNode;
            }
            else {
                tail->next = newNode;
                tail = newNode;
            }
            temp = temp->next;
        }
    }

     // Destructor
     ~IntList()
     {

     };

     // Linked list operations
     void appendNode(Element);
     void insertNode(const Element);
     void deleteNode(const Element);
     void displayList() const;
     void reverseList();

     private:
    Node* head = NULL;
    Node* tail = NULL;
};
  #endif

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
#include <iostream>
#include <string>
#include "Queue.h"

using namespace std;
        

/******************************************************************** 
*** FUNCTION Queue::Queue( const short size): QUEUE_SIZE{size}    *** 
********************************************************************* 
*** DESCRIPTION : This is the constructor for the queue class.    ***
                  It defaults to creating a queue of a size of 3  ***
                  but also allows user input to create a queue of ***
                  a different size if desired                     ***
*** INPUT ARGS : size (const short) - user inputted queue size    *** 
*** OUTPUT ARGS : None                                            *** 
*** IN/OUT ARGS : size (const short) - user inputted queue size   *** 
*** RETURN : Creates Queue                                        *** 
********************************************************************/ 
Queue::Queue( const short size): QUEUE_SIZE{size}
{
    if (QUEUE_SIZE <= 0)
    {
        cout << "ERROR: Queue size should be greater than zero" << endl;
    }
    else
    {
        queueArray = new Element[QUEUE_SIZE];
        head = -1;
        tail = -1;
    }
}
/******************************************************************************* 
*** FUNCTION Queue::Queue( Queue & original):QUEUE_SIZE(original.QUEUE.SIZE) *** 
******************************************************************************** 
*** DESCRIPTION : This is the copy constructor for the Queue class.          ***
                  It takes in the original Queue created and then copies     ***
                  the elements contained into another Queue                  ***
*** INPUT ARGS : original (Queue &) - The stack meant to be copied           *** 
*** OUTPUT ARGS : None                                                       *** 
*** IN/OUT ARGS : original (Queue &) - The stack meant to be copied          *** 
*** RETURN : Copied Queue                                                    *** 
********************************************************************************/ 
Queue::Queue( Queue & original):QUEUE_SIZE(original.QUEUE_SIZE)
{
    queueArray = new Element[original.QUEUE_SIZE];            
    head = -1;     
    tail = -1;
            
    Element value;

    Queue copyQueue(original.QUEUE_SIZE);   
    copyQueue.head = -1;    
    copyQueue.tail = -1;

    while(!original.isEmpty())      
        {
            original.dequeue(value);          
            copyQueue.enqueue(value);         
        }
            
    while(!copyQueue.isEmpty())     
        {
            copyQueue.dequeue(value);         
            original.enqueue(value);          
            enqueue(value);                   
        }
}
/******************************************************************** 
*** FUNCTION Queue::~Queue                                        *** 
********************************************************************* 
*** DESCRIPTION : This is the destructor for the Queue class.     ***
                  It deallocates all the memory in which the      ***
                  Queue occupied with its elements                ***
*** INPUT ARGS :                                                  *** 
*** OUTPUT ARGS : None                                            *** 
*** IN/OUT ARGS : None                                            *** 
*** RETURN : None                                                 *** 
********************************************************************/ 
Queue::~Queue()
{
    Element value;

    if(head == -1)
        {
            queueArray = nullptr;
        }
    else
        while(!isEmpty())
            {
                value = queueArray[head];
                dequeue(value);
            }
        
    delete [] queueArray;
    queueArray = nullptr;
}
/******************************************************************** 
*** FUNCTION Queue::enqueue                                       *** 
********************************************************************* 
*** DESCRIPTION : This is the enqueue function which queues the   ***
                  element given from the user to be placed into   ***
                  queue at the tail and will also give feedback   ***
                  if full                                         ***
*** INPUT ARGS : value (const Element) - user-inputted element    *** 
*** OUTPUT ARGS : None                                            *** 
*** IN/OUT ARGS : value (const Element) - user-inputted element   *** 
*** RETURN : void                                                 *** 
********************************************************************/ 
void Queue::enqueue(const Element value)
{
    if(isFull())
        {
            cout << "Queue is full; could not add: " << value << endl;
        }  
    else if (head == -1)
        {   
            head = tail = 0;
            queueArray[tail] = value;
        }
    else if (tail == QUEUE_SIZE - 1 && head != 0)
    {
        tail = 0;
        queueArray[tail] = value;
    }
    else
    {
        tail++;
        queueArray[tail] = value;
    }
}
/******************************************************************** 
*** FUNCTION Queue::dequeue                                       *** 
********************************************************************* 
*** DESCRIPTION : This is the deqeueue function which removes the ***
                  head element given from the user from the queue ***
                  and wiil give feedback if empty                 ***
*** INPUT ARGS :  Element & value                                 *** 
*** OUTPUT ARGS : Element & value                                 *** 
*** IN/OUT ARGS : Element & value                                 *** 
*** RETURN : void                                                 ***
********************************************************************/ 
 void Queue::dequeue( Element &value )
 {
    if(isEmpty())
        {
            cout << "Queue is empty" << endl;
        }
    else if (head == tail)
        {  
            value = queueArray[head];
            head = tail = -1;
        }  
    else
        {
            value = queueArray[head];
            head = (head + 1) % QUEUE_SIZE;
        }
}
/******************************************************************** 
*** FUNCTION Queue::view                                          *** 
********************************************************************* 
*** DESCRIPTION : This is the view function which is used to      ***
                  display the entire queue from head to tail to   ***
                  the user while also making sure the elements    ***
                  are not deleted from being removed from the     ***
                  queue                                           ***
*** INPUT ARGS :  None                                            *** 
*** OUTPUT ARGS : None                                            *** 
*** IN/OUT ARGS : None                                            *** 
*** RETURN : void                                                 *** 
********************************************************************/ 
void Queue::view() 
{ 
    Element holder;
    Queue tempQueue(QUEUE_SIZE);

    cout << "HEAD -> ";

    while(!isEmpty())
        {
            dequeue(holder);
            cout << holder << " -> ";
            tempQueue.enqueue(holder);
        }

    while(!tempQueue.isEmpty())
        {
            tempQueue.dequeue(holder);
            enqueue(holder);
        }

    cout << "TAIL" << endl;
}
/******************************************************************** 
*** FUNCTION Queue::isFull                                        *** 
********************************************************************* 
*** DESCRIPTION : This is the isFull function which checks to see ***
                  if the queue is full                            ***
*** INPUT ARGS :  None                                            *** 
*** OUTPUT ARGS : None                                            ***
*** IN/OUT ARGS : None                                            *** 
*** RETURN : true or false                                        *** 
********************************************************************/
bool Queue::isFull() const
{
    if((head == (tail + 1) % (QUEUE_SIZE)))
        {
            return true;
        }
    else
        {
            return false;
        }
}   
/******************************************************************** 
*** FUNCTION Queue::isEmpty                                       *** 
********************************************************************* 
*** DESCRIPTION : This is the isEmpty function which checks to    ***
                  see if the queue is empty                       ***
*** INPUT ARGS :  None                                            *** 
*** OUTPUT ARGS : None                                            ***
*** IN/OUT ARGS : None                                            *** 
*** RETURN : true or false                                        *** 
********************************************************************/
bool Queue::isEmpty() const
{
    if(head == -1 && tail == -1) 
        {
            return true;
        }
    else
        { 
            return false;
        }
}       
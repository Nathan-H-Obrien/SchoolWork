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
#include <iostream>
#include <iomanip>
#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;
        

/******************************************************************** 
*** FUNCTION Stack::Stack( const int size): STACK_SIZE{size}      *** 
********************************************************************* 
*** DESCRIPTION : This is the constructor for the Stack class.    ***
                  It defaults to creating a stack of a size of 2  ***
                  but also allows user input to create a stack of ***
                  a different size if desired                     ***
*** INPUT ARGS : size (const int) - user inputted stack size      *** 
*** OUTPUT ARGS : None                                            *** 
*** IN/OUT ARGS : None                                            *** 
*** RETURN : None                                                 *** 
********************************************************************/ 
Stack::Stack( const int size): STACK_SIZE{size}
{
    
    if(STACK_SIZE <= 0)
        { cout << "Invalid size; Stack size should be greater than zero." << endl;}
    else
        stackArray = new Element[STACK_SIZE];
        top = -1;
}
/******************************************************************************* 
*** FUNCTION Stack::Stack( Stack & original):STACK_SIZE(original.STACK_SIZE) *** 
******************************************************************************** 
*** DESCRIPTION : This is the copy constructor for the Stack class.          ***
                  It takes in the original stack created and then copies     ***
                  the elements contained into another stack                  ***
*** INPUT ARGS : original (Stack &) - The stack meant to be copied           *** 
*** OUTPUT ARGS : None                                                       *** 
*** IN/OUT ARGS : None                                                       *** 
*** RETURN : None                                                            *** 
********************************************************************************/ 
Stack::Stack( Stack & original):STACK_SIZE(original.STACK_SIZE)
{

    stackArray = new Element[STACK_SIZE];
    if(top > -1)
        {
            top = -1;
                
            Element holder;
            Stack copyStack(STACK_SIZE);

           
        for (int i = 0; i <= original.STACK_SIZE; i++) 
            {
                holder = original.pop();
                copyStack.push(holder);
            }
        
        for(int i = 0; i<= STACK_SIZE - 1; i++)
                {
                    holder = copyStack.pop();
                    push(holder);
                    original.push(holder);
                }
        }
    else
        {
            top = -1;
        }

}
/******************************************************************** 
*** FUNCTION Stack::~Stack                                        *** 
********************************************************************* 
*** DESCRIPTION : This is the destructor for the Stack class.     ***
                  It deallocates all the memory in which the      ***
                  stack occupied with its elements                ***
*** INPUT ARGS : size (const int)                                 *** 
*** OUTPUT ARGS : None                                            *** 
*** IN/OUT ARGS : None                                            *** 
*** RETURN : None                                                 *** 
********************************************************************/ 
Stack::~Stack()
{

    if(top == -1)
        {
            stackArray = nullptr;
        }
    else
        while(top >= 0)
            {
                pop();
                top--;
            }
        
        
    delete [] stackArray;
}
/******************************************************************** 
*** FUNCTION Stack::push                                          *** 
********************************************************************* 
*** DESCRIPTION : This is the push function which inserts the     ***
                  element given from the user to be placed into   ***
                  stack and will give feedback if full            ***
*** INPUT ARGS : word (const Element) - user-inputted element     *** 
*** OUTPUT ARGS : None                                            *** 
*** IN/OUT ARGS : None                                            *** 
*** RETURN : None                                                 *** 
********************************************************************/ 
void Stack::push(const Element word )
{
        
    if(top >= STACK_SIZE - 1)
              {cout << "Stack Full, word not added" << endl;}
        else
        {
                top++;
                stackArray[top] = word;
            }
}
/******************************************************************** 
*** FUNCTION Stack::pop                                           *** 
********************************************************************* 
*** DESCRIPTION : This is the pop function which removes out the  ***
                  element given from the user from the stack and  ***
                  wiil give feedback if empty                     ***
*** INPUT ARGS :  None                                            *** 
*** OUTPUT ARGS : None                                            *** 
*** IN/OUT ARGS : None                                            *** 
*** RETURN : word (Element) - user-inputted element                *** 
********************************************************************/ 
Element Stack::pop()
{

    Element word;
    if(top <= -1)
        {
            cout << "Stack Empty, word not removed" << endl;
        }
    else
        {
                
            word = stackArray[top];
            top--;
        }

    return word;
}
/******************************************************************** 
*** FUNCTION Stack::peek                                          *** 
********************************************************************* 
*** DESCRIPTION : This is the peek function which is to allow the ***
                  user to display the top element of the stack    ***
                  while also making sure the element does not get ***
                  deleted from being removed from the stack       ***
*** INPUT ARGS :  None                                            *** 
*** OUTPUT ARGS : None                                            ***
*** IN/OUT ARGS : None                                            *** 
*** RETURN : holder (Element) - top of the stack element          *** 
********************************************************************/ 
Element Stack::peek()
{
    Element holder;
    if(top<=-1)
        {
            cout << "Stack Underflow" << endl;
        }
    else
        {
            holder = pop();
            cout<< "The top word is " << holder << endl;
            push(holder);
        }

    return holder;
}
/******************************************************************** 
*** FUNCTION Stack::view                                          *** 
********************************************************************* 
*** DESCRIPTION : This is the view function which is used to      ***
                  display the entire stack from top to bottom to  ***
                  the user while also making sure the elements    ***
                  are not deleted from being removed from the     ***
                  stack                                           ***
*** INPUT ARGS : size (const int)                                 *** 
*** OUTPUT ARGS : None                                            *** 
*** IN/OUT ARGS : None                                            *** 
*** RETURN : None                                                 *** 
********************************************************************/ 
void Stack::view()
{

    Element holder;
    Stack tempstack(STACK_SIZE);
    cout << "TOP -> ";

    if(top >= 0 ) 
        {
            for(int i = STACK_SIZE-1; i >= 0; i--)
                {
                    holder = pop();
                    cout << holder <<" -> ";
                    tempstack.push(holder);
                }
        
            for(int i = 0; i <= STACK_SIZE - 1; i++)
                {
                    holder = tempstack.pop();
                    push(holder);
                }
                
        } 
            
    cout<< "BOTTOM" << endl;

}
/* ***********************************************************************
 * ***                                                                 ***
 * ***     NAME     : Nathan O'Brien                                   ***
 * ***     ASSIGN # : 4                                                ***
 * ***     DUE DATE : November 8th, 2023                               ***
 * ***     CLASS    :  CSC 300                                         ***
 * ***     INSTR    :  Gamradt                                         ***
 * ***                                                                 ***
 * ***********************************************************************
 * ***     PROGRAM DESCRIPTION : This program is meant to create a     ***
 * ***     Binary Search Tree which allows for inserting, removing,    ***
 * ***     and searching for elements as well as being able to         ***
 * ***     display the tree in pre-order, in-order, and post-order     ***
 * **********************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include "BST.h"

using namespace std;
        

/******************************************************************
*** FUNCTION BST::BST() : root(nullptr)                         *** 
******************************************************************* 
*** DESCRIPTION : This is the constructor for the BST class.    ***
                  It intializes root to a nullptr.              ***
*** INPUT ARGS : None                                           *** 
*** OUTPUT ARGS : None                                          *** 
*** IN/OUT ARGS : None                                          *** 
*** RETURN : None                                               *** 
******************************************************************/ 
BST::BST() : root(nullptr)
{

}
/***************************************************************************** 
*** FUNCTION BST::BST( BST & original): root(nullptr)                      *** 
****************************************************************************** 
*** DESCRIPTION : This is the copy constructor for the BST class.          ***
                  It takes in the original BST created and then copies     ***
                  the elements contained into another BST                  ***
*** INPUT ARGS : original (BST &) - The BST meant to be copied             *** 
*** OUTPUT ARGS : None                                                     *** 
*** IN/OUT ARGS : original (BST &) - The BST meant to be copied            *** 
*** RETURN : None                                                          *** 
*****************************************************************************/ 
BST::BST( const BST &original) : root(nullptr)
{
    copy(original.root);
}
/******************************************************************************* 
*** FUNCTION BST::copy ( const NodePtr original )                            *** 
******************************************************************************** 
*** DESCRIPTION : This is the copy function for the BST class.               ***
                  It takes in the original BST elements and then copies      ***
                  the elements into another BST                              ***
*** INPUT ARGS : const NodePtr original                                      *** 
*** OUTPUT ARGS : None                                                       *** 
*** IN/OUT ARGS : None                                                       *** 
*** RETURN : None                                                            *** 
********************************************************************************/ 
void BST::copy(const NodePtr original) 
{
    if (original != nullptr) 
    {
        insert(original->element); // Insert the element to the current tree
        copy(original->left);      // Copy left subtree
        copy(original->right);     // Copy right subtree
    }
}
/******************************************************************** 
*** FUNCTION BST::~BST                                            *** 
********************************************************************* 
*** DESCRIPTION : This is the destructor for the BST class.       ***
                  It deallocates all the memory in which the      ***
                  BST occupied with its elements                  ***
*** INPUT ARGS : None                                             *** 
*** OUTPUT ARGS : None                                            *** 
*** IN/OUT ARGS : None                                            *** 
*** RETURN : None                                                 *** 
********************************************************************/ 
BST::~BST()
{
    destroy(root);
    root = nullptr;
}
/*********************************************************************** 
*** FUNCTION BST::destory(NodePtr &root)                             *** 
************************************************************************ 
*** DESCRIPTION : This is the destroy function for the BST class.    ***
                  It recurvisvely removes all key nodes from the BST ***
*** INPUT ARGS :  NodePtr &root                                      *** 
*** OUTPUT ARGS : None                                               *** 
*** IN/OUT ARGS : None                                               *** 
*** RETURN : None                                                    *** 
************************************************************************/
void BST::destroy(NodePtr &root) 
{
    if (root == nullptr) 
        {
            cout << "The BST is empty" << endl;
        }

    else 
        {
            if (root->left != nullptr) 
                {
                    destroy(root->left);
                }
            if (root->right != nullptr) 
                {
                    destroy(root->right);
                }
            root = nullptr;
            delete root;
        }
}
/******************************************************************** 
*** FUNCTION BST::insert                                          *** 
********************************************************************* 
*** DESCRIPTION : This is the insert function. It is meant to     ***
                  insert a new key node into the BST              ***
*** INPUT ARGS : value (const Element) - user-inputted element    *** 
*** OUTPUT ARGS : None                                            *** 
*** IN/OUT ARGS : value (const Element) - user-inputted element   *** 
*** RETURN : None                                                 *** 
********************************************************************/ 
void BST::insert(const Element value)
{
    insert(root, value);
}
/*********************************************************************** 
*** FUNCTION BST::remove (NodePtr &root, const Element value)        ***                                     *** 
************************************************************************ 
*** DESCRIPTION : This is the recursive insert function.             ***
                  It recursively inserts a new key node into the BST ***
*** INPUT ARGS : NodePtr &root, const Element value                  *** 
*** OUTPUT ARGS : None                                               *** 
*** IN/OUT ARGS : None                                               *** 
*** RETURN : None                                                    ***
***********************************************************************/
void BST::insert( NodePtr &root, const Element value)
{
    if (root == nullptr)
        {
            root = new Node;
            root->element = value;
            root->left = root->right = nullptr;
        }
    else if (value < root->element)
        {
            insert(root->left, value);
        }
    else if (value > root->element)
        {
            insert(root->right, value);
        }
    else if (value == root->element)
    {
        cout << "Value already exists within the BST" << endl;
    }
}
/******************************************************************** 
*** FUNCTION BST::remove                                          *** 
********************************************************************* 
*** DESCRIPTION : This is the remove function. It is meant to     ***
                  remove a key node from the BST                  ***
*** INPUT ARGS : value (const Element) - user-inputted element    *** 
*** OUTPUT ARGS : None                                            *** 
*** IN/OUT ARGS : value (const Element) - user-inputted element   *** 
*** RETURN : None                                                 *** 
********************************************************************/ 
 void BST::remove( const Element value )
{
    remove(root, value);
}
/******************************************************************** 
*** FUNCTION BST::remove (NodePtr &root, const Element value)     ***                                     *** 
********************************************************************* 
*** DESCRIPTION : This is the recursive remove function.          ***
                  It recursively removes an existing key node     ***
                  from the BST                                    ***
*** INPUT ARGS : NodePtr &root, const Element value               *** 
*** OUTPUT ARGS : None                                            *** 
*** IN/OUT ARGS : None                                            *** 
*** RETURN : None                                                 ***
********************************************************************/ 
 void BST::remove( NodePtr &root, const Element value )
{
    if (root == nullptr)
        {
            cout << "The BST is empty; Node cannot be removed" << endl;
        }
    else if (root->element == value)
        {
            removeNode(root);
        }
    else if (value < root->element && root->left != nullptr)
        {
            remove(root->left, value);
        }
    else if (value > root->element && root->right != nullptr)
        {
            remove(root->right, value);
        }
    else
        {
            cout << "Value not contained within the BST" << endl;
        }

}
/******************************************************************** 
*** FUNCTION BST::removeNode(NodePtr &root)                       *** 
********************************************************************* 
*** DESCRIPTION : This is the removeNode function. It removes an  ***
                  existing key node from the BST                  ***
*** INPUT ARGS :  NodePtr &root                                   *** 
*** OUTPUT ARGS : None                                            *** 
*** IN/OUT ARGS : None                                            *** 
*** RETURN : None                                                 ***
********************************************************************/ 
void BST::removeNode(NodePtr &root) 
{
    if (root == nullptr)
        {
            cout << "BST is empty" << endl;
        }
    else 
        {
            if (root->left == root->right)
                {
                    delete root;
                    root = nullptr;
                }
            else if (root->right == nullptr)
                {
                    NodePtr holder = root;
                    root = root->left;
                    delete holder;
                }
            else if (root->left == nullptr)
                {
                    NodePtr holder = root;
                    root = root->right;
                    delete holder;
                }
            else if (root->left != nullptr && root->right != nullptr)
                {
                    NodePtr holder, newParent;
                    holder = root;
                    newParent = root->left;
                    findMaxNode(holder, newParent);
                    if (holder != root)
                        {
                            holder->right = newParent->left;
                        }
                    root->element = newParent->element;

                    newParent = nullptr;
                    holder = nullptr;
                    delete newParent;
                    delete holder;
                }
            
        }
}
/********************************************************************** 
*** FUNCTION BST::findMaxNode(NodePtr& holder, NodePtr& newParent)  *** 
*********************************************************************** 
*** DESCRIPTION : This is the findMaxNode function which is used to ***
                  find the maximum key node in the left subtree of  ***
                  the BST                                           ***
*** INPUT ARGS : NodePtr& holder, NodePtr& newParent                *** 
*** OUTPUT ARGS : None                                              *** 
*** IN/OUT ARGS : None                                              *** 
*** RETURN : None                                                   *** 
**********************************************************************/
void BST::findMaxNode(NodePtr& holder, NodePtr& newParent) 
{
    while (newParent->right != nullptr)
        {
            holder = newParent;
            newParent = newParent->right;
        }
}
/******************************************************************** 
*** FUNCTION BST::search                                          *** 
********************************************************************* 
*** DESCRIPTION : This is the search function which is used to    ***
                  find a value in the BST                         ***
*** INPUT ARGS :  None                                            *** 
*** OUTPUT ARGS : None                                            *** 
*** IN/OUT ARGS : None                                            *** 
*** RETURN : None                                                 *** 
********************************************************************/
NodePtr BST::search( const Element value) const
{ 
    return search(root,value);
}
/*************************************************************************** 
*** FUNCTION BST::search( const NodePtr root, const Element value) const *** 
****************************************************************************
*** DESCRIPTION : This is the recursive search function                  ***
                  which is used recursively to find a                    ***
                  value in the BST                                       ***
*** INPUT ARGS : const NodePtr root, const Element value                 ***
*** OUTPUT ARGS : None                                                   ***
*** IN/OUT ARGS : None                                                   ***
*** RETURN : None                                                        ***
***************************************************************************/
NodePtr BST::search( const NodePtr root, const Element value) const
{
    if (root == nullptr)
        {
            cout << "Value does not exist within the BST" << endl;
            return nullptr;
        }
    else if (value == root->element)
        {
            cout << "Value found within the BST" << endl;
            return root;
        }
    else if (value < root->element)
        {
            return search(root->left, value);
        }
    else if (value > root->element)
        {
            return search(root->right, value);
        }
    else
        {
            cout << "Value does not exist within the BST" << endl;
            return nullptr;
        }
}
/******************************************************************** 
*** FUNCTION BST::preorderView                                    *** 
********************************************************************* 
*** DESCRIPTION : This is the preorderView function which is used ***
                  to display the entire BST from top to bottom    ***
                  by going left to right down the BST             ***
*** INPUT ARGS :  None                                            *** 
*** OUTPUT ARGS : None                                            *** 
*** IN/OUT ARGS : None                                            *** 
*** RETURN : None                                                 *** 
********************************************************************/
void BST::preorderView() const
{
    cout << "BEGIN -> ";
    preorderView(root);
    cout << "END" << endl;
}
/******************************************************************** 
*** FUNCTION BST::preorderView(const NodePtr root) const          *** 
********************************************************************* 
*** DESCRIPTION : This is the recursive preorderView function     ***
                  which is used recursively to display the        ***
                  entire BST from top to bottom by going left to  ***
                  right down the BST                              ***
*** INPUT ARGS : const NodePtr root                               ***
*** OUTPUT ARGS : None                                            ***
*** IN/OUT ARGS : None                                            ***
*** RETURN : None                                                 ***
********************************************************************/
void BST::preorderView(const NodePtr root) const
{
    if (root == nullptr)
        {
            cout << "The BST is empty" << endl;
        }
    else
        {
            cout << root->element << " -> ";

            if (root->left != nullptr)
                {
                    preorderView(root->left);
                }
            
            if (root->right != nullptr)
                {
                    preorderView(root->right);
                }
        }
}
/******************************************************************** 
*** FUNCTION BST::inorderView                                     *** 
********************************************************************* 
*** DESCRIPTION : This is the inorderView function which is used  ***
                  to display the entire BST from top to bottom    ***
                  by going in ascending order                     ***
*** INPUT ARGS :  None                                            *** 
*** OUTPUT ARGS : None                                            *** 
*** IN/OUT ARGS : None                                            *** 
*** RETURN : None                                                 *** 
********************************************************************/
void BST::inorderView() const
{
    cout << "BEGIN -> ";
    inorderView(root);
    cout << "END" << endl;
}
/******************************************************************** 
*** FUNCTION BST::inorderView(const NodePtr root) const          *** 
********************************************************************* 
*** DESCRIPTION : This is the recursive inorderView function      ***
                  which is used recursively to display the        ***
                  entire BST from top to bottom by going in       ***
                  ascending order                                 ***
*** INPUT ARGS : const NodePtr root                               ***
*** OUTPUT ARGS : None                                            ***
*** IN/OUT ARGS : None                                            ***
*** RETURN : None                                                 ***
********************************************************************/
void BST::inorderView(const NodePtr root) const
{
    if (root != nullptr)
        {
            inorderView(root->left);
            cout << root->element << " -> ";
            inorderView(root->right);
        }
}
/******************************************************************** 
*** FUNCTION BST::postorderView                                   *** 
********************************************************************* 
*** DESCRIPTION : This is the postorderView function.             ***
                  which is used to display the entire BST from    ***
                  bottom to top by going right to left up the BST ***
*** INPUT ARGS : None                                             ***
*** OUTPUT ARGS : None                                            ***
*** IN/OUT ARGS : None                                            ***
*** RETURN : None                                                 ***
********************************************************************/
void BST::postorderView() const
{
    cout << "BEGIN -> ";
    postorderView(root);
    cout << "END" << endl;
}
/******************************************************************** 
*** FUNCTION BST::preorderView(const NodePtr root) const          *** 
********************************************************************* 
*** DESCRIPTION : This is the recursive postorderView function    ***
                  which is used recursively to display the        ***
                  entire BST from bottom to top by going right to ***
                  left up the BST                                 ***
*** INPUT ARGS : const NodePtr root                               ***
*** OUTPUT ARGS : None                                            ***
*** IN/OUT ARGS : None                                            ***
*** RETURN : None                                                 ***
********************************************************************/
void BST::postorderView(const NodePtr root) const
{
    if (root == nullptr)
        {
            cout << "The BST is empty" << endl;
        }
    else
        {
            if (root->right != nullptr)
                {
                    postorderView(root->right);
                }

            cout << root->element << " -> ";

            if (root->left != nullptr)
                {
                    postorderView(root->left);
                }
        }
}
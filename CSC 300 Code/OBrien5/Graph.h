/* ************************************************************************
 * ***                                                                  ***
 * ***     NAME     : Nathan O'Brien                                    ***
 * ***     ASSIGN # : 5                                                 ***
 * ***     DUE DATE : November 29th, 2023                               ***
 * ***     CLASS    :  CSC 300                                          ***
 * ***     INSTR    :  Gamradt                                          ***
 * ***                                                                  ***
 * ************************************************************************
 * ***     PROGRAM DESCRIPTION : This program is used to create a Graph ***
 * ***                           by using an adjecnt matrix while       ***
 * ***                           utlizing Dijkstra's algorithm          ***
 * ***********************************************************************/

//Guard
#pragma once

//Header files
#include <string>
#include <iostream>
#include <fstream>
#include <climits>

using namespace std;

//user defined element
typedef unsigned short Element;

class Graph 
{
    public: // exportable
        // General description of each of the ADT operations/functions – exportable operations only
        explicit Graph(const string = "graph.dat");     //constructor
        ~Graph();       //destructor
        void dijkstra();        //dijkstra
        
    private: // non-exportable
        // No private member documentation – implementation details are hidden/abstracted away
        enum GraphLimit {GRAPH_LIMIT = 15};       
        Graph(const Graph &) = delete;          
        void setGraph(const string);       
        void setVisited();          
        unsigned short setStart() const;          
        void view() const;          
        bool restart() const;      
        Element adjMatrix[GRAPH_LIMIT][GRAPH_LIMIT];
        Element distArray[GRAPH_LIMIT];
        bool visitedSet[GRAPH_LIMIT];
        unsigned short nodeCount;
};
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
#include "Graph.h"
/******************************************************************
*** FUNCTION Graph::Graph(const string file)                    *** 
******************************************************************* 
*** DESCRIPTION : This is the constructor for the graph class.  ***
*** INPUT ARGS : const string file                              *** 
*** OUTPUT ARGS : None                                          *** 
*** IN/OUT ARGS : None                                          *** 
*** RETURN : None                                               *** 
******************************************************************/ 
Graph::Graph(const string file)
{
    setGraph(file); 
}
/******************************************************************** 
*** FUNCTION Graph::~Grpah                                        *** 
********************************************************************* 
*** DESCRIPTION : This is the destructor for the Graph class.     ***
*** INPUT ARGS : None                                             *** 
*** OUTPUT ARGS : None                                            *** 
*** IN/OUT ARGS : None                                            *** 
*** RETURN : None                                                 *** 
********************************************************************/ 
Graph::~Graph()
{
    
}
/******************************************************************** 
*** FUNCTION Graph::setGraph                                      *** 
********************************************************************* 
*** DESCRIPTION : This function brings in the file name and opens ***
                  it up to make sure it exists, then it grabs the ***
                  first value to see how large the array will be  ***
                  and prepares it for that size and then runs a   ***
                  for loop to input all the values into it.       ***
*** INPUT ARGS : const string file                                *** 
*** OUTPUT ARGS : None                                            *** 
*** IN/OUT ARGS : None                                            *** 
*** RETURN : None                                                 *** 
********************************************************************/
void Graph::setGraph(const string File)
{
    ifstream inFile;            

    inFile.open(File);          
    if(!inFile)                 
        {
            cout << "Error Opening " << File << " File!" << endl;    
            return;         
        }

    inFile >> nodeCount;           

    if(nodeCount > GRAPH_LIMIT)          
        {
            cout << "Data too large, setting size of array to 15 by 15" << endl; 
            nodeCount = GRAPH_LIMIT;         
        }

    for(int i = 0; i < nodeCount; ++i)         
        for(int j = 0; j < nodeCount; ++j)         
            {
                inFile >> adjMatrix[i][j];                  
                distArray[i] = 0;
            }

    inFile.close();             
}
/**********************************************************************
*** FUNCTION Graph::dijkstra                                        *** 
*********************************************************************** 
*** DESCRIPTION : This functions helps create a dijkstra algorithms ***
*** INPUT ARGS : None                                               *** 
*** OUTPUT ARGS : None                                              *** 
*** IN/OUT ARGS : None                                              *** 
*** RETURN : None                                                   *** 
**********************************************************************/ 
void Graph::dijkstra()
{
do
    {    
        Element Beginning = setStart();            
        setVisited();           

        visitedSet[Beginning] = true;           

        for(int i = 0; i < nodeCount; ++i)
            distArray[i] = adjMatrix[Beginning][i];         

        Element location;       

        for(int count = 0 ; count < nodeCount - 1; ++count)       
            {
                Element disMin = USHRT_MAX;              

                for(int j = 0; j < nodeCount; ++j)
                    if(distArray[j] <= disMin && visitedSet[j] == false) 
                        {
                            disMin = distArray[j];   
                            location = j;            
                        }

                visitedSet[location] = true;       

                for(int node = 0; node < nodeCount; ++node)         
                    if(visitedSet[node] == false && (distArray[location] + adjMatrix[location][node] < distArray[node]) && adjMatrix[location][node] != USHRT_MAX && distArray[location] != USHRT_MAX)
                        distArray[node] = distArray[location] + adjMatrix[location][node];   
            }

        view();             
    } while(restart());         
}
/**********************************************************************
*** FUNCTION Graph::setStart()const                                 ***
***********************************************************************
*** DESCRIPTION : Asks the user where they want to start the search ***
*** INPUT ARGS : None                                               ***
*** OUTPUT ARGS : None                                              ***
*** IN/OUT ARGS : None                                              ***
*** RETURN : None                                                   ***
**********************************************************************/
unsigned short Graph::setStart()const
{
    Element Holder;             

    do
        {
            cout << "What is your starting node of Choice?(0-" << nodeCount - 1 << ") ";  
            cin >> Holder;           
        }while (Holder < 0 || Holder > nodeCount - 1);          

    return Holder;           
}
/********************************************************************
*** FUNCTION Graph::setVisited()                                  ***
*********************************************************************
*** DESCRIPTION : Asks the user where they want to search         ***
*** INPUT ARGS : None                                             ***
*** OUTPUT ARGS : None                                            ***
*** IN/OUT ARGS : None                                            ***
*** RETURN : None                                                 ***
********************************************************************/
void Graph::setVisited()
{
    for(int i = 0; i < nodeCount; ++i)        
        visitedSet[i] = false;              
}
/********************************************************************
*** FUNCTION Graph::view() const                                  ***
*********************************************************************
*** DESCRIPTION : Displays the results of the Dijkstra algorithm  ***
*** INPUT ARGS : None                                             ***
*** OUTPUT ARGS : None                                            ***
*** IN/OUT ARGS : None                                            ***
*** RETURN : None                                                 ***
********************************************************************/
void Graph::view() const
{
    for(int i = 0; i < nodeCount; ++i)         
        cout << "Distance[" << i << "] = " << distArray[i] << endl;    
}
/********************************************************************
*** FUNCTION Graph::restart() const                               ***
*********************************************************************
*** DESCRIPTION : Prompts the user if they wish to use the        ***
                  program again or not and takes in the input     ***
*** INPUT ARGS : None                                             ***
*** OUTPUT ARGS : None                                            ***
*** IN/OUT ARGS : None                                            ***
*** RETURN : None                                                 ***
********************************************************************/
bool Graph::restart() const
{
    char Answer;           

    do                 
        {
            cout << "Do you want to run again? (Y/N) ";        
            cin.ignore();           
            cin >> Answer;
        }while(Answer != 'y' && Answer != 'Y' && Answer != 'n' && Answer != 'N');       

    if(Answer == 'y' || Answer == 'Y')          
        return true;                
    else
        return false;               
}
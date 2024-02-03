/* **********************************************************************
 * ***                                                                ***
 * ***     NAME     : Nathan O'Brien                                  ***
 * ***     ASSIGN # : 7                                               ***
 * ***     DUE DATE : July 6th, 2023                                  ***
 * ***     CLASS    :  CSC 250                                        ***
 * ***     INSTR    :  HAMER                                          ***
 * ***                                                                ***
 * **********************************************************************
 * ***                                                                ***
 * ***     PROGRAM DESCRIPTION : This program is meant to create a    ***
 * ***     binary file which is to take in data from the user to      ***
 * ***     store in the file which will then allow the user to        ***
 * ***     display the data, find the total revenue, edit the data or ***
 * ***     add more data into the file.                               ***
 * *********************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

void editData();    //function to edit the file
void getData();     //function to add data to the file
int printMenu();    //function to prompt the user with a menu
void doOption(int); //function to pull up proper function for what the user wants
void displayData(); //function to display the data in the file
void displayRev();  //function to display the data in the file and find the revenue


struct Cookie
{
    char cookName[20];
    int cookQuant;
    float cookPrice;
};


int main ()
{
    int option;

   option = printMenu();
   doOption(option);

}
//function to add data to the file
void getData()
{
    Cookie theCookie;

    fstream theFile;
theFile.open("cookies.dat",ios::in|ios::binary); //attempt to open the file to see if it exists
if(theFile.fail())
    {
        theFile.open("cookies.dat",ios::out|ios::binary);//file does not exist, create the file
    }
else //file does exist, close the file to reopen in output and append mode.
    {
    theFile.close();
    theFile.open("cookies.dat",ios::out|ios::app|ios::binary);
    }

    cout << "Cookie name: ";    //prompts the user to enter the cookie name
    cin.ignore();
    cin.getline(theCookie.cookName, sizeof(theCookie.cookName)); //store the name into the structure
    theFile.write(theCookie.cookName, sizeof(theCookie.cookName));  //write the name into the file
    do    //ensure that the quantity is 0 or greater
    {
        cout << "Quantity Sold: ";  //prompts the user to enter the quantity sold
        cin >> theCookie.cookQuant; //store the quantity into the structure
    } while (theCookie.cookQuant < 0);
    theFile.write(reinterpret_cast<char *>(&theCookie.cookQuant), sizeof(theCookie.cookQuant)); //write the quantity into the file
    do    //ensure the price is greater than zero
    {
       cout << "Price of the cookie: "; //prompts the user to enter the price of the cookie
       cin >> theCookie.cookPrice;     //store the price into the structure
    } while (theCookie.cookPrice < 0);
    theFile.write( reinterpret_cast<char *>(&theCookie.cookPrice), sizeof(theCookie.cookPrice));    //write the price into the file

    theFile.close();
}


//function to prompt the user with a menu
int printMenu ()
{
//	Local Declarations
	int option;

//	Statements
	do  //displays the menu to the user
	  {
	   printf("\n********************");
	   printf("\n*       MENU       *");
	   printf("\n*                  *");
	   printf("\n*  1. Add Data     *");
	   printf("\n*  2. Edit Data    *");
	   printf("\n*  3. Total Rev    *");
	   printf("\n*  4. Display Data *");
	   printf("\n*  0. EXIT         *");
	   printf("\n*                  *");
	   printf("\n********************");

	   printf("\n\n\nPlease type your choice ");    //prompts the user to choose one of the given options
	   printf("and press the return key : ");
	   scanf("%d", &option);

	   if (option < 0 || option > 4)
	      printf("Invalid option. Please re-enter.\n");

	 } while (option < 0 || option > 4);    //ensures that the user enters a valid option
	return option;
}
//function to pull up proper function for what the user wants
void doOption(int option)
{
    switch (option)
    {
        case 1: getData();
            break;
        case 2: editData();
            break;
        case 3: displayRev();
            break;
        case 4: displayData();
            break;
    }
}
//function to edit the file
void editData()
{
   Cookie cookRecord;
   int bitnum;

    fstream theFile;
    theFile.open("cookies.dat",ios::in|ios::out|ios::binary);   //open the file for input and output
    if (!theFile)   //ensure the file is able to be open
    {
        cout << "Error opening file, closing program";
        return;
    }

    theFile.seekg(0, ios::end);     //find the end of the file
    int size = theFile.tellg();     //store the size of the file

    theFile.seekg(0, ios::beg);     //return to the beginning of the file

    while (theFile.tellg() < size)  //display all the data until the eof is found
    {
        theFile.read(cookRecord.cookName, sizeof(cookRecord.cookName));     //reads the file for the cookie name
        cout << "The end position of cookie " << cookRecord.cookName << " is: " << theFile.tellg() << endl;     //displays the cookie name with its end position
        theFile.read(reinterpret_cast<char *>(&cookRecord.cookQuant), sizeof(cookRecord.cookQuant));    //reads the file for the quantity
        cout << "The end position of the quantity " << cookRecord.cookQuant << " is: " << theFile.tellg() << endl;  //displays the quantity with its end position
        theFile.read(reinterpret_cast<char *>(&cookRecord.cookPrice), sizeof(cookRecord.cookPrice));    //reads the file for the price
        cout << "The end position of the price " << cookRecord.cookPrice << " is: " << theFile.tellg() << endl; //displays the price with its end position
    }

    cout << "Enter what position you want to edit: ";   //prompts the user to select what position to edit
    cin >> bitnum;                                      //stores the position number
    theFile.seekp(bitnum, ios::beg);                    //sets the position to the number the user entered

    int option;
    do              //menu to tell the program what type of edit it is
	  {
	   printf("\n*********************");
	   printf("\n*       MENU        *");
	   printf("\n*                   *");
	   printf("\n*  1. Edit Cookie   *");
	   printf("\n*  2. Edit Quantity *");
	   printf("\n*  3. Edit Price    *");
	   printf("\n*  0. EXIT          *");
	   printf("\n*                   *");
	   printf("\n*********************");

	   printf("\n\n\nPlease type your choice ");    //prompts the user to select what they are editing
	   printf("and press the return key : ");
	   scanf("%d", &option);

	   if (option < 0 || option > 3)    //ensure the user enters a valid number
	      printf("Invalid option. Please re-enter.\n");

	 } while (option < 0 || option > 3);

	 switch (option)        //switch case to ensure that the correct variable is changed
    {
        case 1: cout << "New name for the Cookie: ";    //prompts user for new name
                cin.ignore();
                cin.getline(cookRecord.cookName, sizeof(cookRecord.cookName));             //stores the name into the structure
                theFile.write(cookRecord.cookName, sizeof(cookRecord.cookName));    //writes the new name into the file
                cout << "The name for the cookie is now: " << cookRecord.cookName;  //displays the new name to the user
            break;
        case 2: do  //ensure the new quantity is not less than 0
                {
                cout << "New quantity for the Cookie: ";    //prompts user for new quantity
                cin >> cookRecord.cookQuant;                //stores the quantity into the structure
                } while (cookRecord.cookQuant < 0);
                theFile.write(reinterpret_cast<char *> (&cookRecord.cookQuant), sizeof(cookRecord.cookQuant));  //writes the new quantity into the file
                cout << "The quantity for the cookie is now: " << cookRecord.cookQuant;                         //displays the new quantity to the user
            break;
        case 3: do  //ensure the new price is not less than 0
                {
                cout << "New price for the Cookie: ";   //prompts user for new price
                cin >> cookRecord.cookPrice;            //stores the price into the structure
                } while (cookRecord.cookPrice < 0);
                theFile.write(reinterpret_cast<char *> (&cookRecord.cookPrice), sizeof(cookRecord.cookPrice));  //writes the new price into the file
                cout << "The price for the cookie is now: " << cookRecord.cookPrice;                            //displays the new price to the user
            break;
        case 0: return;
            break;
    }


}
//function to display the data in the file
void displayData()
{
    Cookie cookRecord;

    ifstream theFile;
    theFile.open("cookies.dat",ios::in|ios::binary);    //open the file for input only
    if (!theFile)   //checks to see if the file opens properly
    {
        cout << "Error opening file, closing program";
        return;
    }

    theFile.seekg(0, ios::end);     //finds the end of the file
    int size = theFile.tellg();     //stores the end of the file as the file size

    theFile.seekg(0, ios::beg); //finds the beginning of the file

    while (theFile.tellg() < size)  //displays the contents of the file to the user
    {
        theFile.read(cookRecord.cookName, sizeof(cookRecord.cookName));                                 //reads the file for the cookie name
        cout << "Cookie: " << cookRecord.cookName << endl;                                              //displays the cookie name
        theFile.read(reinterpret_cast<char *>(&cookRecord.cookQuant), sizeof(cookRecord.cookQuant));    //reads the file for the quantity
        cout << "Quantity: " << cookRecord.cookQuant << endl;                                           //displays the quantity
        theFile.read(reinterpret_cast<char *>(&cookRecord.cookPrice), sizeof(cookRecord.cookPrice));    //reads the file for the price
        cout << "Price: " << fixed << setprecision(2) << cookRecord.cookPrice << endl;                  //displays the price
    }

}
//function to display the data in the file and find the revenue
void displayRev()
{
        Cookie cookRecord;
        float rev, totalRev;

    ifstream theFile;
    theFile.open("cookies.dat",ios::in|ios::binary);    //open the file for input only
    if (!theFile)   //checks to see if the file opens properly
    {
        cout << "Error opening file, closing program";
        return;
    }

    theFile.seekg(0, ios::end);     //finds the end of the file
    int size = theFile.tellg();     //stores the end of the file as the file size

    theFile.seekg(0, ios::beg); //finds the beginning of the file

    totalRev = 0;   //sets the total revenue to 0

    while (theFile.tellg() < size)  //displays the contents of the file while also finding the revenue of each cookie and the total revenue
    {
        theFile.read(cookRecord.cookName, sizeof(cookRecord.cookName));                                 //reads the file for cookie name
        cout << "Cookie: " << cookRecord.cookName << endl;                                              //displays the cookie name
        theFile.read(reinterpret_cast<char *>(&cookRecord.cookQuant), sizeof(cookRecord.cookQuant));    //reads the file for the quantity
        cout << "Quantity: " << cookRecord.cookQuant << endl;                                           //displays the quantity
        theFile.read(reinterpret_cast<char *>(&cookRecord.cookPrice), sizeof(cookRecord.cookPrice));    //reads the file for the price
        cout << "Price: " << fixed << setprecision(2) << cookRecord.cookPrice << endl;                  //displays the price
        rev = cookRecord.cookQuant * cookRecord.cookPrice;                                              //calculates the revenue from price and quantity
        cout << "Revenue: " << fixed << setprecision(2) << rev << endl;                                 //displays the revenue
        totalRev = rev + totalRev;                                                                      //calculates the total revenue
    }

    cout << "Total revenue: " << fixed << setprecision(2) << totalRev;                                  //displays the total revenue
}

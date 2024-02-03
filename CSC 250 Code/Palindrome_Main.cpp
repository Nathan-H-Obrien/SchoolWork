#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
using namespace std;

void removeSpaces(char str[]);      //function to remove spaces in the sentence
bool isPalRec(char str[], int s, int e);    //function to compare parts of a word or sentence to see if they match
bool isPalindrome(char str[], int);         //function to see if the string is empty
int printMenu();                    //function to prompt the user to enter a palindrome or exit the program
void getData();                     //function to get palindrome from the user and also remove any special characters entered

int main()
{
    int option = 1;     //set option to 1 right away to ensure that the menu gets printed

    //loop to allow the user to enter palindromes until they enter 0
    while (option != 0)
    {
        option = printMenu();
        if (option == 0)
        {
            cout << "Exiting program";
            return option;
        }
        else
        {
            getData();
        }
    }
}


bool isPalRec(char str[],
              int s, int e)
{
    for(int i = 0; i < 100; i++)
    {
        str[i] = tolower(str[i]);   //sets all the letters to lowercase to ensure the program tells that the letters are the same
    }

    if (s == e)     //checks to see if there is only one letter in the word/sentence
    return true;

    if (str[s] != str[e])   //check to see if the first and last letter do not match
    return false;

    if (s < e + 1)      //check to see if the middle of the string is is also a palindrome
    return isPalRec(str, s + 1, e - 1);     //function calls itself

    return true;
}

bool isPalindrome(char str[])
{
int n = strlen(str);

if (n == 0)         //checks to see if the string is empty
    return true;

return isPalRec(str, 0, n - 1);
}

int printMenu ()
{
//	Local Declarations
	int option;

//	Statements
	do  //displays the menu to the user
	  {
	   printf("\n****************************");
	   printf("\n*          MENU            *");
	   printf("\n*                          *");
	   printf("\n*   1. Enter Palindrome    *");
	   printf("\n*   0. EXIT                *");
	   printf("\n*                          *");
	   printf("\n****************************");

	   printf("\n\n\nPlease type your choice ");    //prompts the user to choose one of the given options
	   printf("and press the return key : ");
	   scanf("%d", &option);

	   if (option < 0 || option > 1)
	      printf("Invalid option. Please re-enter.\n");

	 } while (option < 0 || option > 1);    //ensures that the user enters a valid option
	return option;
}

void getData()
{
    char s[100], str[100];      //creates to different character arrays
    int j = 0;
    cout << "Enter a palindrome: ";     //prompts the user to enter a palindrome
    cin.ignore();
    cin.getline(s, 100);        //stores the palindrome into the first character array

    for(int i = 0; s[i] != '\0'; ++i)   //loops until the end of the string
    {
        if ((s[i] >= 'a' && s[i]<='z') || (s[i] >= 'A' && s[i]<='Z'))   //checks to see if the value of the character entered is within the scope of the alphabet
        {
            str[j++] = s[i];    //removes the special character from the character array and stores it into the second character array

        }
    }
    str[j] = '\0';

    removeSpaces(str);

    if (isPalindrome(str))      //tells the user if the word/sentence is a palindrome or  not
    cout << "Sentence is a palindrome.";
    else
    cout << "Sentence is not a palindrome.";

    return;
}

void removeSpaces(char *str)
{
    // To keep track of non-space character count
    int count = 0;      //To track anything that is not a space character

    // Traverse the given string. If current character
    // is not space, then place it at index 'count++'
    for (int i = 0; str[i]; i++)        //go through the string and find all non-space characters within the string and remove the spaces
        if (str[i] != ' ')
            str[count++] = str[i];

    str[count] = '\0';
}


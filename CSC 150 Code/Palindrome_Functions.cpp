#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include "Palindrome_Header.h"
using namespace std;

    void removeSpaces(char str[]);
    bool isPalRec(char str[], int s, int e);
    bool isPalindrome(char str[], int);
    int printMenu();
    void getData();


// A recursive function that
// check a str[s..e] is
// palindrome or not.
bool isPalRec(char str[],
              int s, int e)
{
    for(int i = 0; i < 100; i++)
    {
        str[i] = tolower(str[i]);
    }

    // If there is only one character
    if (s == e)
    return true;

    // If first and last
    // characters do not match
    if (str[s] != str[e])
    return false;

    // If there are more than
    // two characters, check if
    // middle substring is also
    // palindrome or not.
    if (s < e + 1)
    return isPalRec(str, s + 1, e - 1);

    return true;
}

bool isPalindrome(char str[])
{
int n = strlen(str);

// An empty string is
// considered as palindrome
if (n == 0)
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
    char s[100], str[100];
    int j = 0;
    cout << "Enter a palindrome: ";
    cin.ignore();
    cin.getline(s, 100);

    for(int i = 0; s[i] != '\0'; ++i)
    {
        if ((s[i] >= 'a' && s[i]<='z') || (s[i] >= 'A' && s[i]<='Z'))
        {
            str[j++] = s[i];

        }
    }
    str[j] = '\0';

    removeSpaces(str);

    if (isPalindrome(str))
    cout << "Sentence is a palindrome.";
    else
    cout << "Sentence is not a palindrome.";

    return;
}

void removeSpaces(char *str)
{
    // To keep track of non-space character count
    int count = 0;

    // Traverse the given string. If current character
    // is not space, then place it at index 'count++'
    for (int i = 0; str[i]; i++)
        if (str[i] != ' ')
            str[count++] = str[i]; // here count is
                                   // incremented
    str[count] = '\0';
}

void removeCharacters(char *str)
{
    char alphabetString[100];
    int j = 0;

    for(int i = 0; str[i] != '\0'; ++i)
    {
        if ((str[i] >= 'a' || str[i]<='z') || (str[i] >= 'A' || str[i]<='Z'))
        {
            alphabetString[j++] = str[i];

        }
    }
    alphabetString[j] = '\0';
}

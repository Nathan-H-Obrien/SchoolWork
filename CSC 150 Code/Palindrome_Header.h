#ifndef PALINDROME_HEADER_H_INCLUDED
#define PALINDROME_HEADER_H_INCLUDED

class Palindrome
{
private:
    int option;

public:
    void removeSpaces(char str[]);
    bool isPalRec(char str[], int s, int e);
    bool isPalindrome(char str[], int);
    int printMenu();
    void getData();
};

#endif // PALINDROME_HEADER_H_INCLUDED

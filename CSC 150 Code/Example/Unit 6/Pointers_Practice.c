// Practice with parameters and return values
//
// 04/04/2023

#include <stdio.h>


void printNum(int num1, int num2);
void getNum (int* n1, int* n2);  // read 2 ints from users, store with pointer parameters

int main ()
{
    int num1, num2;

    getNum(&num1, &num2);

    printNum (num1, num2);



    return 0;
}


//print num to the monitor with a label
// num passes into the function by value
// In the printNum, new space is allocated for num and the
// number currently stored in main's num variable is
// the initial value for printNum's value variable
void printNum(int num1, int num2)
{
    printf ("num1: %d\n", num1);
    printf ("num2: %d\n", num2);
    return;
}

//reading an int from user and returning it
void getNum (int* n1, int* n2)
{

    printf ("Enter two integers: ");
    scanf("%d %d", n1, n2);

    return;
}

// Name: Nathan O'Brien; Due Date: March 9th 2023
// Course: CSC 150 S03 TTh 11-1215; Assignment: Program 4
// Description: This program is to roll three dice.
// The numbers on the dice will then determine if the player gets a prize.

#include <stdio.h>
#include <stdlib.h>

//Prototypes
void printWelcome (); //Print the welcome message
int getDice ();  //Find the dice rolls
int getPrize (int dieOne, int dieTwo, int dieThree); //Find the prize money
void printPrize (int prize); //Print prize results

int main ()
{
    int dieOne,     //Die one value
    dieTwo,         //Die two value
    dieThree,       //Die three value
    prize;          //Prize money

    srand(time(0));

    printWelcome();     //Call the print welcome message

    dieOne = getDice ();          //Call the dice value and store it into a die value
    dieTwo = getDice ();
    dieThree = getDice ();

    printf ("Your dice rolls are: %d %d %d\n", dieOne, dieTwo, dieThree);    //Print the dice rolls to the player

    prize = getPrize(dieOne, dieTwo, dieThree);         //Call the prize amount

    printPrize (prize);                                 //Call the prize amount statement

     return 0;
}


//Print welcome message
void printWelcome()
{
    printf ("Welcome to the Dice Game!!\n");
    printf ("\nThe game is simple, you roll three dice and hope you win a prize!\n");
    printf ("\nIf you roll three of the same number, you win $100!!\n");
    printf ("\nIf you roll in sequential order (1,2,3 or 6,5,4), you win $50!!\n");
    printf ("\nIf you roll two of the same number, you win $25!!\n");
    printf ("\nIf you don't roll anything listed above, you lose\n\n\n");

    return;
}


//Get the dice rolls
int getDice()
{
    int die;

    die = rand() % 6 + 1;

    return die;
}

//Take the dice rolls and determine the prize amount
int getPrize(int dieOne, int dieTwo, int dieThree)
{

    int prize;

    if (dieOne == dieTwo && dieOne == dieThree)   //The if statement if all three dice equal each other
    {
        prize = 100;
    }
    else if ((dieOne == dieTwo || dieOne == dieThree || dieTwo == dieThree))    //The if statement if two dice equal each other
    {
        prize = 25;
    }
    else if ((dieOne + 1 == dieTwo || dieOne + 1 == dieThree) && (dieOne - 1 == dieTwo || dieOne - 1 == dieThree) || //The if statement if the dice are in sequential order
            (dieTwo + 1 == dieOne || dieTwo + 1 == dieThree) && (dieTwo - 1 == dieOne ||dieTwo - 1 == dieThree) ||
            (dieThree + 1 == dieOne || dieThree + 1 == dieTwo) && (dieThree - 1 == dieOne || dieThree - 1 == dieTwo))
    {
        prize = 50;
    }

        return prize;

}

//Determine the prize winnings and print out a statement to the player
void printPrize(int prize)
{
    switch (prize)
    {
        case 100: printf ("\nCongratulations!!\n");   //If the player won $100
                  printf ("You have won $100!!!");
        break;

        case 50: printf ("\nCongratulations!!\n");    //If the player won $50
                 printf ("You have won $50!!!");
        break;

        case 25: printf ("\nCongratulations!!\n");    //If the player won $25
                 printf ("You have won $25!!!");
        break;

        default: printf ("\nOh no!\n");
                 printf ("Looks like your luck has run out!\n");    //If the player didn't win anything
                 printf ("Be sure to play again!!");
        break;
    }

    return;
}

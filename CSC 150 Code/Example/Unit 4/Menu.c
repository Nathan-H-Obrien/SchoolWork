//simple menu driven program
//


#include <stdio.h>

int getChoice ();   //print menu, read choice, return choice


int main ()
{
    int choice;

    //Call getChoice
    choice = getChoice ();
    //printf ("You chose %d\n", choice);  //debug

    printf ("\n\n");

    switch(choice)
    {
    case 1:
        printf ("Have fun with your friends!\n");
        break;
    case 2:
        printf ("That's nice of you!\n");
        break;
    case 3:
        printf ("Make that money!\n");
        break;

    default:
        printf ("Other activities are fun as well!\n");
    }

    return 0;
}


int getChoice ()
{
    int choice;

    //print menu
    printf ("What are you doing for spring break? \n");
    printf ("1: Hangout with friends\n");
    printf ("2: Help out your parents\n");
    printf ("3: Go to work and make money\n");

    //read choice
    printf ("Enter your choice: ");
    scanf ("%d", &choice);

    //return choice
    return choice;
}

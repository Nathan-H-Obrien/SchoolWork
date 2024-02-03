#include <stdio.h>

// function to read a score from user and return it
float getScore ();
char findGrade (float sc);
void printResults(float s, char g);


int main()
{
    float score;
    char grade = 'I';

    score = getScore();
    grade = findGrade(score);
    printResults(score, grade);
    return 0;
}


float getScore ()
{
    float s;
    printf ("Enter a score: ");
    scanf ("%f", &s);

    return s;
}

char findGrade (float sc)
{
    char gr;

    if (sc >= 90)
    {
        gr = 'A';
    }
    else
    {
        if (sc >= 80)
        {
            gr = 'B';
        }
        else
        {
            if (sc >= 70)
            {
                gr = 'C';
            }
            else
            {
                if (sc >= 60)
                {
                    gr = 'D';
                }
                else
                {
                    if (sc >= 0)
                    {
                        gr = 'F';
                    }
                    else
                        printf ("Invalid score!\n");
                    }
                }
            }
        }
return gr;
    }

void printResults(float s, char g)
{
    printf ("Score: %10.2f\n", s);
    printf ("Grade: %6c\n", g);

    return;
}

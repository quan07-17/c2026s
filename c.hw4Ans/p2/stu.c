#include <stdio.h>

#include "stu.h"

int isAlpha(char c)
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

int stuInput(stu_t *stu)
{
    printf("Name: ");
    scanf(" %[^\n]", stu->name);
    for (int i = 0; stu->name[i] != '\0'; i++)
    {
        if (!isAlpha(stu->name[i]) && stu->name[i] != ' ')
        {
            printf("Invalid name!\n");
            return -1;
        }
    }

    printf("Score: ");
    scanf(" %lf", &stu->score);
    if (stu->score < 0.0 || stu->score > 100.0)
    {
        printf("Invalid score!\n");
        return -1;
    }

    return 0;
}

void stuSort(stu_t *stus, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < (n - 1) - i; j++)
        {
            if (stus[j].score < stus[j + 1].score)
            {
                stu_t tmp = stus[j];
                stus[j] = stus[j + 1];
                stus[j + 1] = tmp;
            }
        }
    }
}

double stuAverage(stu_t *stus, int n)
{
    double sum = 0.0;
    for (int i = 0; i < n; i++)
    {
        sum += stus[i].score;
    }
    return sum / n;
}
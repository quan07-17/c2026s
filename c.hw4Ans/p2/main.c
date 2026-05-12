#include <stdio.h>

#include "stu.h"

void stuPrint(stu_t *list, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s: %.2lf\n", list[i].name, list[i].score);
    }
}

int main()
{
    int n = 0;
    
    printf("Number of students: ");
    scanf(" %d", &n);
    stu_t stus[n];

    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("Student %d:\n", i + 1);
        int stat = stuInput(&stus[i]);
        if (stat != 0)
        {
            return stat;
        }
    }

    stuSort(stus, n);
    
    printf("\n");
    printf("Students (Sorted by score, in descending order):\n");
    stuPrint(stus, n);

    printf("\n");
    printf("Average score: %lf\n", stuAverage(stus, n));

    return 0;
}
#include <stdio.h>

typedef struct
{
    char name[20];
    double score;
} stu_t;

int stuInput(stu_t *stus) {
    printf("Name: ");
    getchar();
    scanf("%[^\n]", stus->name);
    for (int i = 0; stus->name[i] != '\0'; i++) {
        if ((stus->name[i]< 'a' || stus->name[i] > 'z') && (stus->name[i] < 'A' || stus->name[i] > 'Z') && stus->name[i] != ' ') {
            printf("Invalid name!\n");
            return -1;
        }
    }
    getchar();
    printf("Score: ");
    scanf("%lf", &stus->score);
    if (stus->score < 0 || stus->score > 100) {
        printf("Invalid score!\n");
        return -1;
    }
        return 0;
}

void stuSort(stu_t stus[],int n) {
    for (int i = 0; i < n; i++) {
        if (stus[i].score < stus[i + 1].score) {
            stu_t temp = stus[i];
            stus[i] = stus[i + 1];
            stus[i + 1] = temp;
        }
    }
}

double stuAverage(stu_t stus[],int n) {
    double avg = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        sum += stus[i].score;
    }
    avg = sum / n;
    return avg;
}
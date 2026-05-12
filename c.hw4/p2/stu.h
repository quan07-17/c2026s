typedef struct
{
    char name[20];
    double score;
} stu_t;

int stuInput(stu_t *stus);
void stuSort(stu_t stus[],int n);
double stuAverage(stu_t stus[],int n);
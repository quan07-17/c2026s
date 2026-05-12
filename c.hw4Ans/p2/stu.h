typedef struct
{
    char name[21];
    double score;
} stu_t;

int stuInput(stu_t *stu);
void stuSort(stu_t *stus, int n);
double stuAverage(stu_t *stus, int n);
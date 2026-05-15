#define INIT_SIZE 2
#define GROWTH_RATE 2

typedef struct
{
    int* data;
    unsigned int size;
    unsigned int capacity;
} numBox;
#define GROWTH_RATE 2
#define SHRINK_RATE 0.5

typedef struct
{
    char name[21];
    char phone[11];
    char email[65];
} contact;

typedef struct
{
    contact* contacts;
    int size;
    int capacity;
} contactBook;
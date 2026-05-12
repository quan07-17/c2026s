#include "point.h"

typedef struct
{
    point_t center;
    double radius;
} circle_t;

double circleArea(circle_t c);
double isPointInCircle(point_t p, circle_t c);
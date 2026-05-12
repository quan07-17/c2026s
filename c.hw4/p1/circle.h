#include "point.h"

#define bool char
#define true 1
#define false 0

typedef struct {
    double x;
    double y;
} center;

typedef struct {
    center center;
    double radius;
} circle_t;

double circleArea(circle_t c);
bool isPointInCircle(point_t p, circle_t c);


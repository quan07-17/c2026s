#include <math.h>
#include "point.h"

#define PI 3.14
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


double circleArea(circle_t c) {
    return PI * pow(c.radius,2);
}

bool isPointInCircle(point_t p, circle_t c) {
    double distance = sqrt(pow(p.x - c.center.x, 2) + pow(p.y - c.center.y, 2));
    return distance <= c.radius;
}
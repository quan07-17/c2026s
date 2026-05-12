#include <math.h>

#include "circle.h"

double circleArea(circle_t c)
{
    return 3.14 * c.radius * c.radius;
}

double isPointInCircle(point_t p, circle_t c)
{
    double d = sqrt(pow(p.x - c.center.x, 2) + pow(p.y - c.center.y, 2));
    return d <= c.radius;
}
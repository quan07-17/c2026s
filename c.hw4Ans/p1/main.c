#include <stdio.h>

#include "circle.h"

int main()
{
    point_t p = {0, 0};
    circle_t c = {{0, 0}, 0};

    printf("Enter the center of the circle (x y): ");
    scanf(" %lf %lf", &c.center.x, &c.center.y);
    printf("Enter the radius of the circle: ");
    scanf(" %lf", &c.radius);

    printf("Area of the circle: %.2lf\n", circleArea(c));

    printf("Enter a point to check (x y): ");
    scanf(" %lf %lf", &p.x, &p.y);
    if (isPointInCircle(p, c))
    {
        printf("The point is inside the circle.\n");
    }
    else
    {
        printf("The point is outside the circle.\n");
    }

    return 0;
}
#include <stdio.h>
#include <math.h>

float func0(float a, float b, float c) {
if (a + b <= c || a + c <= b || b + c <= a) return -1;
float s = (a + b + c) / 2;
float area = sqrtf(s * (s - a) * (s - b) * (s - c));
return roundf(area * 100) / 100;
}

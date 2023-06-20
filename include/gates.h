#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

float cost_gates(float w1,float w2,float b);
void gradient_descent_gates(float w1, float w2, float b);
float sigmoid_f(float x);
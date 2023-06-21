#ifndef ONE_PARAM
#define ONE_PARAM

#ifndef STD_HEADERS
#define STD_HEADERS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#endif

float rand_float(void);
float cost_one_parameter(float w, float b);
void gradient_descent_one_parameter(float w, float b);

#endif
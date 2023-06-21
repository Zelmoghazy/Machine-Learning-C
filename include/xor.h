#ifndef XOR
#define XOR

#ifndef STD_HEADERS
#define STD_HEADERS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#endif

typedef struct {
    float or_w1;
    float or_w2;
    float or_b;

    float nand_w1;
    float nand_w2;
    float nand_b;

    float and_w1;
    float and_w2;
    float and_b;
}xor;

float forward(xor m, float x1, float y2);
float cost_xor(xor m);
xor rand_xor(void);
void print_xor(xor m);
xor finite_diff(xor m , float eps);
xor apply_diff(xor m, xor g, float rate);
#endif
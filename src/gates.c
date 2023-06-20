#include "../include/gates.h"

/**
 *  OR-gate 
 */
/* input1,input2,output */
float train_or[][3] = {
    {0, 0, 0},
    {0, 1, 1},
    {1, 0, 1},
    {1, 1, 1},
};
float train_and[][3] = {
    {0, 0, 0},
    {0, 1, 0},
    {1, 0, 0},
    {1, 1, 1},
};

#define train_count_or (sizeof(train_or)/sizeof(train_or[0]))


float sigmoid_f(float x){
    return 1.f/(1.f + expf(-x));
}

float cost_gates(float w1,float w2,float b){
    float result = 0.0f;
    for (size_t i = 0; i < train_count_or; i++){
        float x1 = train_and[i][0];
        float x2 = train_and[i][1];
        float y = sigmoid_f(x1*w1 + x2*w2 + b);
        float d = y - train_and[i][2];
        result += d*d;             
    }
    result /= train_count_or;
    return result;
}

void gradient_descent_gates(float w1, float w2, float b){
    float eps = 1e-1;
    float rate = 1e-1;
    float c;
    for (size_t i = 0; i < 1000000; i++){
        c = cost_gates(w1, w2,b);
        float dw1 = (cost_gates(w1 + eps, w2,b) - c) / eps;
        float dw2 = (cost_gates(w1, w2 + eps,b) - c) / eps;
        float db = (cost_gates(w1, w2 , b+ eps) - c) / eps;
        w1 -= rate * dw1;
        w2 -= rate * dw2;
        b -= rate * db;
    }
    printf("w1 = %f, w2 = %f, b = %f, c = %f\n", w1, w2,b, c);
    for (size_t i = 0; i < 2; i++){
        for (size_t j = 0; j < 2; j++){
            printf("%zu | %zu = %f\n",i,j,sigmoid_f(i*w1 + j*w2 + b)); 
        }
    }
    
}

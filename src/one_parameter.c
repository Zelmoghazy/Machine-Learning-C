#include "../include/one_parameter.h"

float train_one_parameter[][2] = {
    {0, 0},
    {1, 3},
    {2, 6},
    {3, 9},
    {4, 12}
};

#define train_count_one_parameter (sizeof(train_one_parameter)/sizeof(train_one_parameter[0]))

float rand_float(void){
    return (float) rand()/ (float) RAND_MAX;
}

float cost_one_parameter(float w, float b){
    float result = 0.0f;
    
    for (size_t i = 0; i < train_count_one_parameter; i++){
        float x = train_one_parameter[i][0];
        float y = x*w + b;
        float d = y - train_one_parameter[i][1];
        result += d*d;              // Square of error -> Amplify error, absolute value
    }
    result /= train_count_one_parameter;
    return result;
}

void gradient_descent_one_parameter(float w, float b){
    float eps = 1e-3;
    float rate = 1e-3;
    while(cost_one_parameter(w,b) > 0.001){
        float c = cost_one_parameter(w,b);
        float dw = (cost_one_parameter(w+eps,b)-c)/eps;
        float db = (cost_one_parameter(w,b+eps)-c)/eps;
        w -= rate*dw;
        b -= rate*db;
    }
    printf("w: %f\n",w);
    printf("b: %f\n",b);
}
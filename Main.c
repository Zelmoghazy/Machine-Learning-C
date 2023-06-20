#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float train[][2] = {
    {0, 0},
    {1, 3},
    {2, 6},
    {3, 9},
    {4, 12}
};

#define train_count (sizeof(train)/sizeof(train[0]))

float rand_float(void){
    return (float) rand()/ (float) RAND_MAX;
}

float cost(float w, float b){
    float result = 0.0f;
    
    for (size_t i = 0; i < train_count; i++){
        float x = train[i][0];
        float y = x*w + b;
        float d = y - train[i][1];
        result += d*d;              // Square of error -> Amplify error, absolute value, simplify math
    }
    result /= train_count;
    return result;
}

void gradient_descent(float w, float b){
    float eps = 1e-3;
    float rate = 1e-3;
    while(cost(w,b) > 0.001){
        float c = cost(w,b);
        float dw = (cost(w+eps,b)-c)/eps;
        float db = (cost(w,b+eps)-c)/eps;
        w -= rate*dw;
        b -= rate*db;
    }
    printf("w: %f\n",w);
    printf("b: %f\n",b);
}

int main()
{
    srand(time(0));
    float w = rand_float()*10.0f;
    float b = rand_float()*5.0f;
    gradient_descent(w,b);
    system("pause");
    return 0;
}

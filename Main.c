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

float cost(float w){
    float result = 0.0f;
    
    for (size_t i = 0; i < train_count; i++)
    {
        float x = train[i][0];
        float y = x*w;
        float d = y - train[i][1];
        result += d*d;              // Square of error -> Amplify error, absolute value, simplify math
    }
    result /= train_count;
    return result;
}

float gradient_descent(float w){
    float eps = 1e-3;
    float rate = 1e-3;

    for (size_t i = 0; i < 500; i++)
    {
        float dcost = (cost(w+eps)-cost(w))/eps;
        w -= rate*dcost;
        if(i%100 == 0){
            printf("Cost:%f\n",cost(w));
        }
    }
    return w;
}

int main()
{
    // srand(time(0));
    srand(7);
    float w = rand_float()*10.0f;

    printf("parameter value : %f\n",gradient_descent(w));
    system("pause");
    return 0;
}

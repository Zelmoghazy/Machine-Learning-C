#include "./include/gates.h"
#include "./include/one_parameter.h"


int main(void){
    srand(time(0));
    float w1 = rand_float();
    float w2 = rand_float();
    float b = rand_float();
    gradient_descent_gates(w1,w2,b);
    
    system("pause");
}

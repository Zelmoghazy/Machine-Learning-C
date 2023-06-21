#include "./include/xor.h"

int main(void){
    srand(time(0));

    float eps = 1e-1;
    float rate = 1e-1;
    
    xor m = rand_xor();

    for (size_t i = 0; i < 1000000; i++){
        xor g = finite_diff(m,eps);
        m = apply_diff(m,g,rate);
    }
    printf("%f\n",cost_xor(m));
    for (size_t i = 0; i < 2; i++){
        for (size_t j = 0; j < 2; j++){
            printf("%zu ^ %zu = %f \n",i,j, forward(m,i,j));
        }
    }
    system("pause");
}

#include "../include/xor.h"
#include "../include/gates.h"
#include "../include/one_parameter.h"


float forward(xor m, float x1, float y2){
    float a = sigmoid_f(m.or_w1*x1 + m.or_w2*y2 + m.or_b);
    float b = sigmoid_f(m.nand_w1*x1 + m.nand_w2*y2 + m.nand_b);
    float c = m.and_w1*a + m.and_w2*b + m.and_b;
    return sigmoid_f(c);
}

float train_xor[][3] = {
    {0, 0, 0},
    {0, 1, 1},
    {1, 0, 1},
    {1, 1, 0},
};
float (*train_ptr)[3] = train_xor;

size_t train_count_xor =  4;

float cost_xor(xor m){
    float result = 0.0f;
    for (size_t i = 0; i < train_count_xor; i++){
        float x1 = train_ptr[i][0];
        float x2 = train_ptr[i][1];
        float y = forward(m,x1,x2);
        float d = y - train_ptr[i][2];
        result += d * d;
    }
    result /= train_count_xor;
    return result;
}
xor rand_xor(void){
    xor m;
    m.or_w1   = rand_float();
    m.or_w2   = rand_float();
    m.or_b    = rand_float();
    m.nand_w1 = rand_float();
    m.nand_w2 = rand_float();
    m.nand_b  = rand_float();
    m.and_w1  = rand_float();
    m.and_w2  = rand_float();
    m.and_b   = rand_float();
    return m;
}

void print_xor(xor m){
    printf("or_w1   = %f\n",m.or_w1  );
    printf("or_w2   = %f\n",m.or_w2  );
    printf("or_b    = %f\n",m.or_b   );
    printf("nand_w1 = %f\n",m.nand_w1);
    printf("nand_w2 = %f\n",m.nand_w2);
    printf("nand_b  = %f\n",m.nand_b );
    printf("and_w1  = %f\n",m.and_w1 );
    printf("and_w2  = %f\n",m.and_w2 );
    printf("and_b   = %f\n",m.and_b  );
}

xor apply_diff(xor m, xor g, float rate) {
    m.or_w1   -= rate * g.or_w1;
    m.or_w2   -= rate * g.or_w2;
    m.or_b    -= rate * g.or_b;
    m.nand_w1 -= rate * g.nand_w1;
    m.nand_w2 -= rate * g.nand_w2;
    m.nand_b  -= rate * g.nand_b;
    m.and_w1  -= rate * g.and_w1;
    m.and_w2  -= rate * g.and_w2;
    m.and_b   -= rate * g.and_b;

    return m;
}

xor finite_diff(xor m, float eps) {
    xor g;
    float c = cost_xor(m);
    float saved;

    saved = m.or_w1;
    m.or_w1 += eps;
    g.or_w1 = (cost_xor(m) - c) / eps;
    m.or_w1 = saved;

    saved = m.or_w2;
    m.or_w2 += eps;
    g.or_w2 = (cost_xor(m) - c) / eps;
    m.or_w2 = saved;

    saved = m.or_b;
    m.or_b += eps;
    g.or_b = (cost_xor(m) - c) / eps;
    m.or_b = saved;

    saved = m.nand_w1;
    m.nand_w1 += eps;
    g.nand_w1 = (cost_xor(m) - c) / eps;
    m.nand_w1 = saved;

    saved = m.nand_w2;
    m.nand_w2 += eps;
    g.nand_w2 = (cost_xor(m) - c) / eps;
    m.nand_w2 = saved;

    saved = m.nand_b;
    m.nand_b += eps;
    g.nand_b = (cost_xor(m) - c) / eps;
    m.nand_b = saved;

    saved = m.and_w1;
    m.and_w1 += eps;
    g.and_w1 = (cost_xor(m) - c) / eps;
    m.and_w1 = saved;

    saved = m.and_w2;
    m.and_w2 += eps;
    g.and_w2 = (cost_xor(m) - c) / eps;
    m.and_w2 = saved;

    saved = m.and_b;
    m.and_b += eps;
    g.and_b = (cost_xor(m) - c) / eps;
    m.and_b = saved;

    return g;
}
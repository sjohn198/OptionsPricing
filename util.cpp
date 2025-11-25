#include "util.h"

int factorial(int start, int prod) {
    if (start == 1 or start == 0) {
        return prod;
    } else {
        return factorial(start - 1, prod * start);
    }
}

float exp_estimation(float exp) {
    float sum = 0;
    for(int i = 0; i < 30; i++) {
        sum += (pow(exp,i)) / factorial(i, 1);
    }
    return sum;
}
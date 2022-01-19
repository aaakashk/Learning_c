#ifndef _FUNC_H
#define _FUNC_H

#include <stdbool.h>

int add(int m, int n) {
    return m + n;
}

float multiply(float a, float b) {
    return a * b;
}

bool is_age(int age) {
    if (age > 18)
        return true;
    return false;
}

#endif
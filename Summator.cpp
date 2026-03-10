#include "Summator.h"
#include <iostream>

Summator::Summator() {}

Summator::~Summator() {}

long long Summator::transform(int i) const {
    return i;
}


long long Summator::sum(int N) const {
    long long result = 0;
    for (int i = 1; i <= N; ++i) {
        result += transform(i);
    }
    return result;
}

const char* Summator::getType() const {
    return "Обычный сумматор (1+2+...+N)";
}
#include "SquareSummator.h"

SquareSummator::SquareSummator() {}

SquareSummator::~SquareSummator() {}

//  i^2
long long SquareSummator::transform(int i) const {
    return static_cast<long long>(i) * i;
}

const char* SquareSummator::getType() const {
    return " вадратичный сумматор (1^2+2^2+...+N^2)";
}
#include "CubeSummator.h"

CubeSummator::CubeSummator() {}

CubeSummator::~CubeSummator() {}

// i^3
long long CubeSummator::transform(int i) const {
    return static_cast<long long>(i) * i * i;
}

const char* CubeSummator::getType() const {
    return "Кубический сумматор (1^3+2^3+...+N^3)";
}
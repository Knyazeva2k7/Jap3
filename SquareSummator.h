#pragma once

#include "Summator.h"

class SquareSummator : public Summator {
public:
    SquareSummator();
    virtual ~SquareSummator();

    virtual long long transform(int i) const override;

    // Переопределяем метод получения типа
    virtual const char* getType() const override;
};
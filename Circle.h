#pragma once
#include <string>
#include <cmath>

#include "Figure.h"

using std::string;

class Circle : public Figure {
    double* radius;

public:
    Circle(double radius) {
        this->radius = new double(radius);
    }

    ~Circle() override {
        delete this->radius;
    }

    double calc_area() override {
        const double r = *this->radius;

        return r * r * 3,14;
    }

    string to_string() override;
};

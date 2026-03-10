#pragma once
#include <string>
#include <cmath>
#include "Figure.h"

using std::string;

class Square : public Figure {
	double* side;

public:
	Square(double side) {
		this->side = new double(side);
	}
	~Square() override {
		delete side;
	}
	Square(const Square&) = delete;
	Square& operator=(const Square&) = delete;

	double calc_area() override {
		return *side * *side;
	}
	string to_string() override;
};


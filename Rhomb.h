#pragma once
#include <string>
#include "Figure.h";

using std::string;

class Rhomb :public Figure {
	double *diag1;
	double *diag2;
public:
	Rhomb(double a, double b) {
		this->diag1 = new double(a);
		this->diag2 = new double(b);
	}
	~Rhomb() {
		delete this->diag1;
		delete this->diag2;
	}
	double calc_area() override{
		return *diag1 * *diag2/2;
	}
	string to_string() override;
};
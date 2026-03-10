#include <sstream>

#include "Square.h"

using std::stringstream;

string Square::to_string() {
    stringstream ss;

    ss << "{"
        << "\n\t"
        << "\"figure_type\": \"square\","
        << "\n\t"
        << "\"area\": " << this->calc_area()
        << "\n"
        << "}";

    return ss.str();
}

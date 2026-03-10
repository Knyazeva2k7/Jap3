#include <sstream>

#include "Rhomb.h"

using std::stringstream;

string Rhomb::to_string(){
	stringstream ss;

    ss << "{"
        << "\n\t"
        << "\"figure_type\": \"rhomb\","
        << "\n\t"
        << "\"area\": " << this->calc_area()
        << "\n"
        << "}";

    return ss.str();
	
}
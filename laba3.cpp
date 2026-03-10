#include <iostream>

#include "Figure.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Rhomb.h"
#include "Square.h"

using namespace std;


int main() {
    setlocale(LC_ALL, "rus");
    Figure* c = nullptr;
    cout << "Выбор фигуры:\n 1. Круг \n 2. Ромб \n 3. Квадрат \n" << endl;
    int number;
    cin >> number;

    switch (number) {
    case 1:
        c = new Circle(3);    
        break;
    case 2:
        c = new Rhomb(5, 6);  
        break;
    case 3:
        c = new Square(2);
        break;
    default:
        c = new Rectangle(3, 4);
        break;
    }

    cout << c->to_string() << endl;
    cout << "Cylinder value " << calc_cylinder_volume(c, 5) << endl;

    return 0;
}
#include <iostream>
#include "AnimalWorld.h"
using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    cout << "" << endl;
    Fish fish1;
    Bird bird1;
    FlyingBird flyingBird1;

    cout << "\n Работа с объектом типа Fish:" << endl;
    fish1.breathe();
    fish1.eat();
    fish1.swim();

    cout << "\n Работа с объектом типа Bird:" << endl;
    bird1.breathe();
    bird1.eat();
    bird1.lay_eggs();

    cout << "\n Работа с объектом типа FlyingBird:" << endl;
    flyingBird1.breathe();
    flyingBird1.eat();
    flyingBird1.lay_eggs();
    flyingBird1.fly();
}

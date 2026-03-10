#include "AnimalWorld.h"
#include <iostream>
#include <string>

using namespace std;

void Fish::eat() {
	cout << "fish eat" << endl;
}
void Fish::breathe() {
	cout << "fish breathe" << endl;
}
void Fish::swim() {
	cout << "fish swim" << endl;
}
void Bird::eat() {
	cout << "bird eat" << endl;
}
void Bird::breathe() {
	cout << "bird breathe" << endl;
}
void Bird::lay_eggs() {
	cout << "bird lay eggs" << endl;
}
void FlyingBird::eat() {
	cout << "Flying bird eat" << endl;
}
void FlyingBird::breathe() {
	cout << "Flying bird breathe" << endl;
}
void FlyingBird::lay_eggs() {
	cout << "Flying bird lay eggs" << endl;
}
void FlyingBird::fly() {
	cout << "Flying bird fly" << endl;
}
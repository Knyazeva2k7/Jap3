#pragma once
#include <string>


class Animal {
public:
	virtual ~Animal() = default;
	virtual void eat() = 0;
	virtual void breathe() = 0;
};

class Fish : public Animal {
public:
	void eat();
	void breathe();
	void swim();
};

class Bird : public Animal {
public:
	void eat();
	void breathe();
	void lay_eggs();
};
class FlyingBird : public Bird {
public:
	void eat();
	void breathe();
	void lay_eggs();
	void fly();
};
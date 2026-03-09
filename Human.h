#pragma once
#include <string>

using namespace std;

class Human {
	string name;
	string surname;
	string patronymic;
public:
	Human();
	Human(const string& name, const string& surname, const string& patronymic);
	
	string getSurnameAndInitials() const;
	string getFullName() const;

	// Добавляем геттеры для доступа к полям
	string getName() const { return name; }
	string getSurname() const { return surname; }
	string getPatronymic() const { return patronymic; }
};


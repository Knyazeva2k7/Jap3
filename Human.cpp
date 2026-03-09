#include "Human.h"
#include <string>;

using namespace std;

Human::Human() : name("неизвестно"), surname("неизвестно"), patronymic("неизвестно"){}

Human::Human(const string& name, const string& surname, const string& patronymic) : name(name), surname(surname), patronymic(patronymic) {}

string Human::getSurnameAndInitials() const {
	string res = surname;
	if (!name.empty()) {
		res+= " ";
		res += name[0];
		res += ".";
	}

	if (!patronymic.empty()) {
		res += patronymic[0];
		res += ".";
	}
	return res;
}

string Human::getFullName() const {
	return surname + " " + name + " " + patronymic;
}
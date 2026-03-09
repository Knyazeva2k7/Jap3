#include "Student.h"
#include <sstream>

using namespace std;

Student::Student() : Human(), scores() {}

Student::Student(const string& name, const string& surname,
    const string& patronymic, const vector<int>& scores):
    Human(name, surname, patronymic), scores(scores){}

void Student::addScore(int score) {
    scores.push_back(score);
}

double Student::getAverageScore() const {
    if (scores.empty()) {
        return 0.0;
    }
    int sum = 0;
    for (int score : scores) {
        sum += score;
    }
    return (double)sum / scores.size();//(double)sum перевод сум в дабл
}

string Student::getShortStudentInfo() const{
    stringstream ss;
    ss << getSurnameAndInitials() << ": " <<  getAverageScore();
    return ss.str();
}
string Student::getFullStudentInfo() const{
    stringstream ss;
    ss << Human::getFullName()<< ": ";

    // Добавляем все оценки через пробел
    for (size_t i = 0; i < scores.size(); i++) {
        ss << scores[i];
        if (i != scores.size() - 1) ss << " ";
    }

    ss << " – " << getAverageScore();
    return ss.str();
}
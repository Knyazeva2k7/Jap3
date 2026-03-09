#include "Teacher.h"
#include <sstream>


string Teacher::positionToString() const {// Помогает преобразовать enum в строку
    switch (position) {
    case ASSISTANT: 
        return "ассистент";
    case SENIOR_LECTURER: 
        return "старший преподаватель";
    case DOCENT: 
        return "доцент";
    case PROFESSOR:
        return "профессор";
    default:
        return "Неизвестно";
    }
}


Teacher::Teacher()
    : Human("", "", ""), position(UNKNOWN), subjects() {}


Teacher::Teacher(const string& name,
    const string& surname,
    const string& patronymic,
    Position pos,
    const vector<string>& subjects)
    : Human(name, surname, patronymic), position(pos), subjects(subjects) {
}

void Teacher::addSubject(const string& subject) {
    subjects.push_back(subject);
}


string getInitials(const string& surname, const string& name, const string& patronymic) {
    string initials = surname;
    if (!name.empty())
        initials += " " + name.substr(0, 1) + ".";
    if (!patronymic.empty())
        initials += patronymic.substr(0, 1) + ".";
    return initials;
}

string Teacher::getShortTeacherInfo() const{
    stringstream ss;
    ss << getSurnameAndInitials() << " "
        << positionToString() << ": "
        << subjects.size();
    return ss.str();
}

string Teacher::getFullTeacherInfo() const {
    stringstream ss;
    ss << getFullName() << " "
        << positionToString() << ": ";

    for (size_t i = 0; i < subjects.size(); ++i) {
        ss << subjects[i];
        if (i + 1 != subjects.size())
            ss << ", ";
    }
    return ss.str();
}
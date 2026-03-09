#pragma once
#include "Human.h"
#include <vector>
#include <string>

using namespace std;

class Teacher : public Human {
public:
    enum Position {
        UNKNOWN,       // Неизвестно
        ASSISTANT,     // ассистент
        SENIOR_LECTURER, // старший преподаватель
        DOCENT,        // доцент
        PROFESSOR      // профессор
    };
    Teacher();  // конструктор по умолчанию
    Teacher(const string& name,
        const string& surname,
        const string& patronymic,
        Position pos,
        const vector<string>& subjects);

    void addSubject(const string& subject);
    string positionToString();
    string getShortTeacherInfo() const;
    string getFullTeacherInfo() const;

    Position getPosition() const { return position; }
    const vector<string>& getSubjects() const { return subjects; }

private:
    Position position;
    vector<string> subjects;

    string positionToString() const; 
};

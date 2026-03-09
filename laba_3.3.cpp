#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Human.h"
#include "Student.h"
#include "Teacher.h"
#include <sstream>
#include <algorithm>

using namespace std;

//функции сохранения/загрузки
void saveStudentsToFile(const vector<Student>& students, const string& filename) {
    ofstream file("students.txt");
    if (!file.is_open()) {
        cout << "Ошибка открытия файла для сохранения студентов!" << endl;
        return;
    }

    for (const auto& student : students) {
        // Используем константные методы
        file << student.getFullName() << endl;
        file << "Оценки: ";
        for (int score : student.getScores()) {
            file << score << " ";
        }
        file << endl;
        file << "Средний балл: " << student.getAverageScore() << endl;
        file << "---" << endl;
    }

    file.close();
    cout << "Студенты сохранены в файл " << filename << endl;
}

void loadStudentsFromFile(const string& filename) {
    ifstream file("students.txt");
    if (!file.is_open()) {
        cout << "Ошибка открытия файла для загрузки студентов!" << endl;
        return;
    }

    string line;
    cout << "\nЗагруженные студенты из файла:" << endl;
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

void saveTeachersToFile(const vector<Teacher>& teachers, const string& filename) {
    ofstream file("teachers.txt");
    if (!file.is_open()) {
        cout << "Ошибка открытия файла для сохранения преподавателей!" << endl;
        return;
    }

    for (const auto& teacher : teachers) {
        file << teacher.getFullName() << endl;
        file << "Должность: ";
        switch (teacher.getPosition()) {
        case Teacher::ASSISTANT: file << "ассистент"; break;
        case Teacher::SENIOR_LECTURER: file << "старший преподаватель"; break;
        case Teacher::DOCENT: file << "доцент"; break;
        case Teacher::PROFESSOR: file << "профессор"; break;
        default: file << "неизвестно";
        }
        file << endl;

        file << "Предметы: ";
        for (const auto& subject : teacher.getSubjects()) {
            file << subject << ", ";
        }
        file << endl;
        file << "---" << endl;
    }

    file.close();
    cout << "Преподаватели сохранены в файл " << filename << endl;
}

void loadTeachersFromFile(const string& filename) {
    ifstream file("teachers.txt");
    if (!file.is_open()) {
        cout << "Ошибка открытия файла для загрузки преподавателей!" << endl;
        return;
    }

    string line;
    cout << "\nЗагруженные преподаватели из файла:" << endl;
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

// Функция для поиска студента с наибольшим количеством оценок
int findStudentWithMostScores(const vector<Student>& students) {
    if (students.empty()) return -1;

    int maxIndex = 0;
    int maxScores = 0;

    for (size_t i = 0; i < students.size(); i++) {
        int scoreCount = students[i].getScoresCount();
        if (scoreCount > maxScores) {
            maxScores = scoreCount;
            maxIndex = i;
        }
    }

    return maxIndex;
}

// Функция для поиска профессора с наибольшим количеством предметов
int findProfessorWithMostSubjects(const vector<Teacher>& teachers) {
    if (teachers.empty()) return -1;

    int maxIndex = -1;
    int maxSubjects = 0;

    for (size_t i = 0; i < teachers.size(); i++) {
        if (teachers[i].getPosition() == Teacher::PROFESSOR) {
            int subjectCount = teachers[i].getSubjects().size();
            if (subjectCount > maxSubjects) {
                maxSubjects = subjectCount;
                maxIndex = i;
            }
        }
    }

    return maxIndex;
}

int main() {
    setlocale(LC_ALL, "Russian");

    // массив студентов 
    vector<Student> students;

    students.push_back(Student("Иван", "Иванов", "Петрович", { 5, 4, 5, 4, 5 }));
    students.push_back(Student("Петр", "Петров", "Иванович", { 3, 3, 4, 3, 3 }));
    students.push_back(Student("Мария", "Сидорова", "Алексеевна", { 5, 5, 5, 5, 5 }));
    students.push_back(Student("Анна", "Смирнова", "Дмитриевна", { 2, 3, 2, 3, 2 }));
    students.push_back(Student("Данила", "Козлов", "Сергеевич", { 4, 4, 4, 5, 4 }));
    students.push_back(Student("Елена", "Морозова", "Андреевна", { 3, 4, 3, 4, 5 }));
    students.push_back(Student("Алексей", "Волков", "Николаевич", { 2, 2, 3, 2, 2 }));
    students.push_back(Student("Ольга", "Соколова", "Павловна", { 5, 5, 4, 5, 4 }));
    students.push_back(Student("Артемий", "Лебедев", "Михайлович", { 4, 5, 4, 5, 3, 4, 5, 4, 5, 4 }));
    students.push_back(Student("Татьяна", "Новикова", "Игоревна", { 3, 3, 3, 4, 3 }));

    // массив преподавателей
    vector<Teacher> teachers;

    teachers.push_back(Teacher("Александр", "Чуешев", "Владимирович", Teacher::DOCENT, { "Математика", "Физика" }));
    teachers.push_back(Teacher("Наталья", "Иванова", "Петровна", Teacher::PROFESSOR, { "Информатика", "Программирование", "Алгоритмы", "Базы данных" }));
    teachers.push_back(Teacher("Михаил", "Петров", "Сергеевич", Teacher::DOCENT, { "История", "Философия" }));
    teachers.push_back(Teacher("Екатерина", "Сидорова", "Алексеевна", Teacher::SENIOR_LECTURER, { "Английский язык" }));
    teachers.push_back(Teacher("Владимир", "Козлов", "Николаевич", Teacher::PROFESSOR, { "Физика", "Механика" }));
    teachers.push_back(Teacher("Анна", "Морозова", "Дмитриевна", Teacher::ASSISTANT, { "Химия" }));
    teachers.push_back(Teacher("Денис", "Волков", "Андреевич", Teacher::DOCENT, { "Биология", "Экология" }));
    teachers.push_back(Teacher("Оксана", "Соколова", "Павловна", Teacher::PROFESSOR, { "Информатика", "Программирование", "Web-технологии" }));
    teachers.push_back(Teacher("Григорий", "Лебедев", "Михайлович", Teacher::DOCENT, { "Экономика", "Менеджмент" }));
    teachers.push_back(Teacher("Светлана", "Новикова", "Игоревна", Teacher::SENIOR_LECTURER, { "Информатика", "Компьютерная графика" }));

    // Демонстрация сохранения и загрузки
    cout << "=== ДЕМОНСТРАЦИЯ СОХРАНЕНИЯ И ЗАГРУЗКИ ===" << endl;
    saveStudentsToFile(students, "students.txt");
    saveTeachersToFile(teachers, "teachers.txt");

    loadStudentsFromFile("students.txt");
    loadTeachersFromFile("teachers.txt");

    cout << "\n=== ВЫПОЛНЕНИЕ ЗАДАНИЙ ===" << endl;

    // 1) Студенты со средним баллом > 4
    cout << "\n1. Студенты со средним баллом больше 4:" << endl;
    for (const auto& student : students) {
        if (student.getAverageScore() > 4.0) {
            cout << "  " << student.getShortStudentInfo() << endl;
        }
    }

    // 2) Студенты со средним баллом < 3
    cout << "\n2. Студенты со средним баллом меньше 3:" << endl;
    for (const auto& student : students) {
        if (student.getAverageScore() < 3.0) {
            cout << "  " << student.getShortStudentInfo() << endl;
        }
    }

    // 3) Полная информация о студенте с наибольшим количеством оценок
    cout << "\n3. Полная информация о студенте с наибольшим количеством оценок:" << endl;
    int studentWithMostScores = findStudentWithMostScores(students);
    if (studentWithMostScores != -1) {
        cout << "  " << students[studentWithMostScores].getFullStudentInfo() << endl;
        cout << "  Количество оценок: " << students[studentWithMostScores].getScoresCount() << endl;
    }

    // 4) Краткая информация обо всех доцентах
    cout << "\n4. Краткая информация обо всех доцентах:" << endl;
    for (const auto& teacher : teachers) {
        if (teacher.getPosition() == Teacher::DOCENT) {
            cout << "  " << teacher.getShortTeacherInfo() << endl;
        }
    }

    // 5) Полная информация о профессоре с наибольшим количеством предметов
    cout << "\n5. Полная информация о профессоре с наибольшим количеством предметов:" << endl;
    int professorWithMostSubjects = findProfessorWithMostSubjects(teachers);
    if (professorWithMostSubjects != -1) {
        cout << "  " << teachers[professorWithMostSubjects].getFullTeacherInfo() << endl;
    }

    // 6) Полная информация обо всех преподавателях, которые ведут информатику
    cout << "\n6. Полная информация о преподавателях, ведущих информатику:" << endl;
    for (const auto& teacher : teachers) {
        for (const auto& subject : teacher.getSubjects()) {
            if (subject == "Информатика") {
                cout << "  " << teacher.getFullTeacherInfo() << endl;
                break;
            }
        }
    }

    return 0;
}
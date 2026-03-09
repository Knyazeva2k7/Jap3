#pragma once
#include "Human.h"
#include <vector>
#include <string>

using namespace std;

class Student : public Human {
	vector<int> scores;
public:
	Student();
	Student(const string& name, const string& surname,
		const string& patronymic, const vector<int>& scores);
	void addScore(int score);
	double getAverageScore() const;
	string getShortStudentInfo() const;
	string getFullStudentInfo() const;

	// для получения количества оценок
	int getScoresCount() const { return scores.size(); }
	const vector<int>& getScores() const { return scores; }
};
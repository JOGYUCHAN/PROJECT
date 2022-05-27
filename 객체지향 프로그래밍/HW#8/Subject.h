#include <string>

#ifndef SUBJECT_H
#define SUBJECT_H

using namespace std;

class Subject {
protected:
	string m_name;	// 과목명
	int m_hakjum;	// 학점
	string m_grade;	// 등급 
	float m_GPA;	// 평점

public:
	void initialize();						// 멤버변수 초기화
	void initialize(string sub_name, int hakjum, string grade);	// 입력받은값으로 멤버변수 초기화
	void inputValue(int& int_num);
	void inputValue(string& str);
	void inputData();						// 멤버변수 값 입력
	void printTitle();		// 타이틀 출력
	void printData();		// 값 출력
	void calcGPA();			// 평점 계산
	string getName();	// m_name 리턴
	int getHakjum();	// m_hakjum 리턴
	string getGrade(); 	// m_grade 리턴
	float getGPA();		// m_GPA 리턴
};

#endif

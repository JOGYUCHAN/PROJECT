#include <iostream>
#include <cstring>
#include <iomanip>
#include "Student.h"
#include "Subject.h"

using namespace std;

float convert_grade(string str) {
	if (strcmp(str.c_str(), "A+") == 0) return 4.5;
	else if (strcmp(str.c_str(), "A") == 0) return 4.0;
	else if (strcmp(str.c_str(), "B+") == 0) return 3.5;
	else if (strcmp(str.c_str(), "B") == 0) return 3.0;
	else if (strcmp(str.c_str(), "C+") == 0) return 2.5;
	else if (strcmp(str.c_str(), "C") == 0) return 2.0;
	else if (strcmp(str.c_str(), "D+") == 0) return 1.5;
	else if (strcmp(str.c_str(), "D") == 0) return 1.0;
	else if (strcmp(str.c_str(), "F") == 0) return 0.0;
};

void Subject::calcGPA() {
	m_GPA = m_hakjum * convert_grade(m_grade);
}

void Subject::initialize() {	//그냥 초기화
	m_name = "";		// 과목명
	m_hakjum = 0;		// 과목학점
	m_grade = "";		// 과목등급
	m_GPA = 0.0f;		// 과목평점
}

void Subject::initialize(string sub_name, int hakjum, string grade) {	//입력받은값으로 초기화
	m_name = sub_name;
	m_hakjum = hakjum;
	m_grade = grade;
	m_GPA = m_hakjum * convert_grade(m_grade); 
}

void Subject::inputValue(int& int_num) {
	cin >> int_num;
	if (cin.fail()) {		//int형 외 자료형 입력받았을때 무한반복에러 해결
		cout << "\n숫자를 입력해주세요" << "\n";
		cin.clear(); // 오류스트림을 초기화
		cin.ignore(256, '\n'); // 버퍼를 무시	
		cin >> int_num;
	}
	cin.ignore();
}

void Subject::inputValue(string& str) {
	getline(cin, str);
}

void Subject::inputData() {		// 값 입력
	cout << "과목 : ";
	inputValue(m_name);
	cout << "학점 : ";
	inputValue(m_hakjum);
	cout << "등급 : ";
	inputValue(m_grade);

	calcGPA();
}

void Subject::printTitle() {
	cout.width(10);
	cout << "====================================================================================\n";
	cout.width(10);
	cout << "과목명" << setw(20) << "과목학점" << setw(20) << "과목등급" << setw(20) << "과목평점\n";
	cout << "====================================================================================\n";
}

void Subject::printData() {
	cout.width(10);
	cout << m_name << setw(20) << m_hakjum << setw(20) << m_grade << setw(20) << m_GPA<<"\n";
}


string Subject::getName() {		// 과목명
	return m_name;
}

int Subject::getHakjum() {		// 과목학점
	return m_hakjum;
}

string Subject::getGrade() {	// 과목등급
	return m_grade;
}

float Subject::getGPA() {		// 과목평점
	return m_GPA;
}

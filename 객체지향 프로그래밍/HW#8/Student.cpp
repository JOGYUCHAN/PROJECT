#include <iostream>
#include <string>
#include <iomanip>
#include "Subject.h"
#include "Student.h"

using namespace std;

void Student::initialize() {
    m_name = "";
    m_sub = 0;
    m_hakbun = 0;
    m_subnum = 0;
    m_aveGPA = 0.0f;
}


void Student::initialize(string stdname, int hakbun, int subnum, Subject* sub) {
    m_name = stdname;
    m_sub = sub;
    m_hakbun = hakbun;
    m_subnum = subnum;
    m_aveGPA = calcAveGPA();
}

void Student::remove() {
    delete[] m_sub;
}

void Student::inputValue(int& int_num) {
    cin >> int_num;
    if (cin.fail()) {		//int형 외 자료형 입력받았을때 무한반복에러 해결
        cout << "\n숫자를 입력해주세요" << "\n";
        cin.clear(); // 오류스트림을 초기화
        cin.ignore(256, '\n'); // 버퍼를 무시	
        cin >> int_num;
    }
    cin.ignore();
}

void Student::inputValue(string& str) {
    getline(cin, str);
}

void Student::inputData() {
    int tmp_hakjum = 0;
    float tmp_gpa = 0.0f;

    cout << "이름 :";
    inputValue(m_name);
    cout << "학번 :";
    inputValue(m_hakbun);
    cout << "과목 수 :";
    inputValue(m_subnum);
    m_sub = new Subject[m_subnum];              

    for (int i = 0; i < m_subnum; i++)          
    {
        m_sub[i].inputData();
        tmp_hakjum += m_sub[i].getHakjum();    
        tmp_gpa += m_sub[i].getGPA();
    }

    m_aveGPA = tmp_gpa / (float)tmp_hakjum;
}

void Student::printData() {   
    cout << "\n====================================================================================\n"; 
    cout << "이름 : " << m_name << setw(20) << "학번 : " << m_hakbun << "\n";  
 
    for (int i = 0; i < m_subnum; i++)
    {
        if (i == 0) //학생 존재시 타이틀 한번 출력
            m_sub[i].printTitle();
        m_sub[i].printData();
    }
}

float Student::calcAveGPA() {
    int tmp_hakjum = 0;
    float tmp_gpa = 0.0f;

    for (int i = 0; i < m_subnum; i++)
    {
        tmp_hakjum += m_sub[i].getHakjum();
        tmp_gpa += m_sub[i].getGPA();
    }

    m_aveGPA = tmp_gpa / (float)tmp_hakjum;
    return m_aveGPA;
}; // 평균 평점 계산

string Student::getName() {
    return m_name;
}; // m_name 리턴
int Student::getHakbun() {
    return m_hakbun;
}; // m_hakbun 리턴
int Student::getSubNum() {
    return m_subnum;
}; // m_subnum 리턴
float Student::getAveGPA() {
    return m_aveGPA;
}; // m_aveGPA 리턴


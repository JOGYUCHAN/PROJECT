#include <iostream>
#include <string>
#include "Subject.h"

using namespace std;

#ifndef STUDENT_H
#define STUDENT_H

class Student {
protected:
    string m_name; // 학생명
    int m_hakbun; // 학번
    Subject* m_sub; // 수강한 과목들
    int m_subnum; // 수강한 과목 수
    float m_aveGPA; // 수강한 과목들의 평균 평점

public:
    void initialize(); // 멤버변수 초기화
    void initialize(string stdname, int hakbun, int subnum, Subject* sub); // 인자값으로 멤버변수 초기화
    void remove(); // 동적메모리 해제
    void inputValue(int& int_num);
    void inputValue(string& str);
    void inputData(); // 멤버변수 값 입력
    void printData(); // 멤버변수 값 출력
    float calcAveGPA(); // 평균 평점 계산
    string getName(); // m_name 리턴
    int getHakbun(); // m_hakbun 리턴
    int getSubNum(); // m_subnum 리턴
    float getAveGPA(); // m_aveGPA 리턴
    friend void ShowData(const Student&);
};

#endif
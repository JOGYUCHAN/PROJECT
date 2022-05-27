#include<iostream>
#include<string>
#include"Subject.h"
using namespace  std;

class Student {
protected:
   string m_name; // 학생 이름
   int m_hakbun;  // 학번
   int m_subnum;  // 수강한 과목 수
   Subject* m_sub; // 수강한 과목들
   float m_aveGPA; // 수강한 과목들의 평균 평점

public:
   void InputValue(string&);
   void InputValue(int&);
   void InputData(); // 멤버변수 값 입력
   void PrintData(); // 멤버변수 값 출력
   void CalcAveGPA(float sum, float haksum); // 평균 평점 계산
   void Modify(); // 학생 정보 수정

   Student(); // 디폴트 생성자 
   Student(string name, int hakbun, int subnum, Subject* sub); // 인자있는 생성자
   Student(const Student& std);// 복사 생성자
   ~Student();

   string GetName(); // 접근자함수 : 클래스 밖에서 멤버변수를 읽을 수 있게함.
   int GetHakbun();
   int GetSubNum();
   float GetAveGPA();

};
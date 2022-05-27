#include "Student.h"
#include "Subject.h"
#include <iostream>

void main() {	//subject 클래스 테스트
	Subject sub1, sub2, sub3[2], * sub4;
	int i;
	sub1.initialize();
	sub2.initialize("사진학", 3, "A+");
	for (i = 0; i < 2; i++)
		sub3[i].initialize("컴퓨터", 3, "C");
	sub4 = new Subject[2];
	sub1.inputData(); // 화면에서 입력
	cout << "\n" << "sub1 정보" << "\n";
	sub1.printTitle(); sub1.printData();
	cout << "\n" << "sub2 정보" << "\n";
	sub2.printTitle(); sub2.printData();
	cout << "\n" << "sub3 정보" << "\n";
	sub3[0].printTitle();
	for (i = 0; i < 2; i++) sub3[i].printData();
	for (i = 0; i < 2; i++) (sub4 + i)->inputData();
	cout << "\n" << "sub4 정보" << "\n";
	sub4->printTitle();
	for (i = 0; i < 2; i++) (sub4 + i)->printData();
	delete[] sub4;
}

// void main() {	//student 클래스 테스트
// 	Subject sub[2];
// 	sub[0].Initialize("컴퓨터", 3, "C");
// 	sub[1].Initialize("현대무용", 2, "A");
// 	Student st1, st2;
// 	st1.Initialize();
// 	st2.Initialize("홍길동", 2013909845, 2, sub);
// 	st1.InputData();
// 	cout << "\n" << "st1 정보" << "\n";
// 	st1.PrintData();
// 	cout << "\n" << "st2 정보" << "\n";
// 	st2.PrintData();
// 	st1.Remove();
// }

// #include "Subject.h"
// #include "Student.h"
// #include <iostream>
// using namespace std;
// void ShowData(const Student&);
// void main() {
// 	Student st;
// 	// 객체 입력 및 출력 생략
// 	Subject sub[2];
	
// 	st.Initialize("홍길동", 2013909845, 2, sub);

// 	ShowData(st);
// }
// void ShowData(const Student& s) { //전역함수
// 	cout << s.m_name << "이 수강한 과목은 총" << s.m_subnum << "개로";
	
// 	cout << "수강한 과목의 평균평점은" << s.m_aveGPA << "입니다.\n";
// }
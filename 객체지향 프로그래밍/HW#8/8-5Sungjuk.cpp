#include "Subject.h"
#include "Student.h"
#include <iostream>
using namespace std;

void ShowData(const Student &);

int main() {
	Student st;
	Subject sub[2];
	
	st.initialize("홍길동", 2013909845, 2, sub);

	ShowData(st);

    return 0;
}

void ShowData(const Student& s) { //전역함수
	cout << s.m_name << "이 수강한 과목은 총" << s.m_subnum << "개로";
	
	cout << "수강한 과목의 평균평점은" << s.m_aveGPA << "입니다.\n";
}
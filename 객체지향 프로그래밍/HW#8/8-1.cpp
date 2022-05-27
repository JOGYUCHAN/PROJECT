#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

class Subject {

private:
    string m_name; // 과목명 
    int m_hakjum; // 학점
    string m_grade; // 등급
    float m_GPA; // 평점

public:
    void initialize(); // 멤버변수 초기화
    void initialize(string, int, string); // 인자값으로 멤버변수 초기화
    void inputValue(int &);
    void inputValue(string &);
    void inputData(); // 멤버변수 값 입력 // 내부적으로 InputValue()이용
    void printTitle(); 
    void printData(); // 멤버변수에 대한 title Text 출력 // 멤버변수 값 출력
    void calcGPA(); // 평점 계산
};

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

void Subject::initialize() {	//초기화
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

int main() {
    Subject sub1, sub2, sub3[2], *sub4;
    int i;

    sub1.initialize();
    sub2.initialize("사진학", 3, "A+");

    for (i = 0; i < 2; i++) {
        sub3[i].initialize("컴퓨터", 3, "C");
        sub4 = new Subject[2];
    }

    sub1.inputData(); // 화면에서 입력
    cout << "\n" << "sub1 정보" << "\n";
    sub1.printTitle();
    sub1.printData();

    cout << "\n" << "sub2 정보" << "\n";
    sub2.printTitle();
    sub2.printData();

    cout << "\n" << "sub3 정보" << "\n";
    sub3[0].printTitle();
    for (i = 0; i < 2; i++) sub3[i].printData();
    for (i = 0; i < 2; i++) (sub4 + i)->inputData();
    cout << "ok";
    cout << "\n" << "sub4 정보" << "\n";
    sub4->printTitle();
    for (i = 0; i < 2; i++) (sub4 + i)->printData();
    delete[] sub4;

return 0;
}
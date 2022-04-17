#include <iostream>
#include <cstring>
using namespace std;
int PEOPLE = 0;

struct Subject { //학생의 수강 과목 구조체
    int value; //학점 (예:3학점)
    char grade[10]; //교과목 평점
    char subjectName[30]; //과목명
    float GPA;
};

struct Student { //학생 구조체
    char studentName[30]; //학생 이름
    int studentSerial; //학번
    int subNum;
    Subject* sub; //수강 과목 구조체 << *sub 어떻게 가능한거지
    float AveGPA; //평균 평점
};

inline int printMenu() { //메인 메뉴를 함수로 만듬
    int num;
    cout << "==== 메뉴 ====" << endl;
    cout << "1. 성적 입력" << endl;
    cout << "2. 전체 학생 성적 조회" << endl;
    cout << "3. 특정 학생 성적 검색" << endl;
    cout << "4. 전체 학생 목록 확인" << endl;
    cout << "5. 학생의 정보 수정하기" << endl;
    cout << "6. 프로그램 종료" << endl;
    cout << "원하는 기능을 입력하세요 : ";
    cin >> num;
    return num; //정수 입력받아 반환
}

void line() {
    cout << "=======================================================================\n";
}

float AveGPA(Subject & sub, int subNum) {
    sub.GPA *= sub.value; // 평점을 이수 학점으로 곱하기
    return sub.GPA / subNum; // 과목 GPA를 과목 수만큼 나눈 평균GPA 리턴
    
}

float calGPA(Subject & sub) { //문자열 학점(A+)을 실수 평점값(4.5)으로 변환 - 평점계산함수
    float GPA;
    
    if (strcmp (sub.grade, "A+")== 0 || strcmp (sub.grade, "a+") == 0) { //switch 문을 사용하고 싶었으나 C++에서 switch문에 문자열 사용이 안된다고 함.
        GPA = 4.5;
    }
    else if (strcmp (sub.grade, "A0") == 0 || strcmp (sub.grade, "a0") == 0) //대소문자 모두 인식되게 구현
    {
        GPA = 4.0;
    }
    else if (strcmp (sub.grade, "B+") == 0 || strcmp (sub.grade, "b+") == 0)
    {
        GPA = 3.5;
    }
    else if (strcmp (sub.grade, "B0") == 0 || strcmp (sub.grade, "b0") == 0)
    {
        GPA = 3.0;
    }
    else if (strcmp (sub.grade, "C+") == 0 || strcmp (sub.grade, "c+") == 0)
    {
        GPA = 2.5;
    }
    else if (strcmp (sub.grade, "C0") == 0 || strcmp (sub.grade, "c0") == 0)
    {
        GPA = 2.0;
    }
    else if (strcmp (sub.grade, "D+") == 0 || strcmp (sub.grade, "d+") == 0)
    {
        GPA = 1.5;
    }
    else if (strcmp (sub.grade, "D0") == 0 || strcmp (sub.grade, "d0") == 0)
    {
        GPA = 1.0;
    }
    else if (strcmp (sub.grade, "F") == 0 || strcmp (sub.grade, "f") == 0)
    {
        GPA = 0.0;
        cout << "공부하세요" << endl;
    }
    else
    {
        cout << "올바른 학점이 입력되지 않았습니다.";
    }
    return GPA;
}

void printOneData(const Student & std) { //한사람 데이터 출력
    int j = 0;
    cout.width(10);
    cout << "이름 : " << std.studentName;
    cout.width(10);
    cout << "학번 : " << std.studentSerial << endl;
    line();
    cout.width(20);
    cout << "과목명";
    cout.width(20);
    cout << "과목학점";
    cout.width(20);
    cout << "과목등급";
    cout.width(20);
    cout << "과목평점\n";
    line();
    for (j = 0; j < std.subNum; j++) {
        cout.width(15);
        cout << std.sub[j].subjectName;
        cout.width(15);
        cout << std.sub[j].value;
        cout.width(15);
        cout << std.sub[j].grade;
        cout.width(15);
        cout << std.sub[j].GPA << endl;
    }
    line();
    cout.width(60);
    cout << "평균평점";
    cout.width(10);
    cout << std.AveGPA << endl;
}

void printAllData(const Student* std) {
    for (int i = 0; i < PEOPLE; i++) {
        printOneData(std[i]);
    }
}

Student* stdSearch(Student* std) {
    char stdname[30];
    cout << "검색하려는 학생의 이름을 입력해주세요 : ";
    cin >> stdname;
    for (int i = 0; i < PEOPLE; i++) {
            if (strcmp(stdname, (*(std + i)).studentName) == 0) {
                cout << stdname << "학생을 찾았습니다." << endl;
                return (std+i);
        }
    }
    cout << "검색한 이름과 동일한 학생이 존재하지 않습니다. 메인 메뉴로 돌아갑니다." << endl;
    return NULL;
}

inline void inputValue(char* str) {
    cin >> *str;
}

inline void inputValue(int & i) {
    cin >> i;
}

void setData(Student* std) { //이름/학번 각각에 대해 오버로드 될 수 있게 구현
    int i, j;
    for(i = 0; i < PEOPLE; i++) {
            cout << "* " << i + 1 << "번째 학생의 이름과 학번을 입력하세요." << endl;
            cout << "이름 : ";
            inputValue(std[i].studentName);
            cout << "학번 : ";
            inputValue(std[i].studentSerial);
            cout << "수강 과목 수 : ";
            inputValue(std[i].subNum);
            std[i].sub = new Subject [std[i].subNum];
            std[i].AveGPA = 0;

            for(j = 0; j < std[i].subNum; j++) {
                cout << "수강한 과목 " << std[i].subNum <<"3개와 각 교과목명, 과목학점, 과목등급을 입력하세요." << endl;
                cout << "교과목명 : ";
                inputValue(std[i].sub[j].subjectName);
                cout << "수강학점 : ";
                inputValue(std[i].sub[j].value);
                cout << "과목등급(A+ ~ F) : ";
                inputValue(std[i].sub[j].grade);
                std[i].sub[j].GPA = calGPA(std[i].sub[j]); //입력받은 성적 등급을 숫자 평점으로 변환하는 함수 이용하여 계산 후 임시 저장
                std[i].AveGPA += AveGPA(std[i].sub[j], std[i].subNum);
                }
            
        }
}

void printAllStd(Student* std) { //4. 전체 학생 목록 확인
    line();
    cout.width(10);
    cout << "이름";
    cout.width(10);
    cout << "학번" << endl;
    line();
    for(int i = 0; i < PEOPLE; i++) {
        cout.width(10);
        cout << std[i].studentName;
        cout.width(10);
        cout << std[i].studentSerial << endl;
    }
    line();
}

void changeOneData(Student* std) { //5. 학생 정보 수정
    cout << "* <" << (*std).studentName << ", " << (*std).studentSerial << ">의 정보를 수정하세요" << endl;
    cout << "이름 : ";
    inputValue((*std).studentName);
    cout << "학번 : ";
    inputValue((*std).studentSerial);
    cout << "정상적으로 변경되었습니다." << endl;
}

int main(void) {
    int num = 0;
    int i, j, temp;
    char xxx[10];
    // struct Student std[PEOPLE]; //구조체 생성


    cout << "학생수를 입력해주세요 : ";
    cin >> PEOPLE;


    struct Student* pStd;
    pStd = new struct Student[PEOPLE];

    while (num != 6) { // 메뉴 무한 반복 (숫자 6 입력시 반복문 탈출 후 코드 종료)
        num = printMenu(); //메인메뉴 함수 호출 후 입력값 반환받아 저장
        if (num == 1) {
            setData(pStd);
        }
        else if (num == 2) {
            printAllData(pStd);
        }
        else if (num == 3) {
            Student* stdPointer;
            stdPointer = stdSearch(pStd);
            if (stdPointer != NULL) {
                printOneData(*stdPointer);
            }
        }
        else if (num == 4) { //전체 학생 목록 확인
            printAllStd(pStd);
        }
        else if (num == 5) { //학생의 정보 수정하기
            Student* stdPointer;
            stdPointer = stdSearch(pStd);
            if (stdPointer != NULL) {
                changeOneData(stdPointer); //간접 호출
            }
        }
        else {
            cout << "올바른 수를 입력해주세요.";
        }
    }

    cout << "프로그램을 종료합니다.";   
    return 0;
}
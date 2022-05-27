//2019038055 조규찬
#include <iostream>
#include <string>
#include <string.h>
#include <iomanip>
using namespace std;
int StdNum = 0;

void PrintMenu(void)//프로그램 실행시 메뉴화면 출력
{
    cout << "\n";
    cout << "------- 메뉴 ------" << endl;
    cout << "1. 학생 성적 입력" << endl;
    cout << "2. 전체 학생 성적 보기" << endl;
    cout << "3. 학생 이름 검색" << endl;
    cout << "4. 학생 정보 수정" << endl;
    cout << "5. 프로그램 종료\n" << endl;
    cout << "원하는 기능을 입력하세요 : ";
}




struct Subject {//과목정보
    //char SubName[30];
    string SubName;
    int Hakjum;
    //char Grade[10];
    string Grade;
    float GPA;

};


struct Student {//학생정보
    //char StdName[30];
    string StdName;
    int Hakbun;
    Subject *Sub;
    int SubNum;
    float AveGPA;
};



void CalcGPA(Subject& Sub)// 입력받은 string을 비교하여 학점으로 계산 strcmp에서 ==연산자로 변경
{

    if (Sub.Grade == "A+") {
        Sub.GPA = (float)(4.5) * (float)Sub.Hakjum; //평점*학점
    }
    else if ((Sub.Grade == "A") || (Sub.Grade == "A0")) {
        Sub.GPA = (float)(4.0) * (float)Sub.Hakjum; 
    }
    else if (Sub.Grade == "B+") {
        Sub.GPA = (float)(3.5) * (float)Sub.Hakjum;
    }
    else if ((Sub.Grade == "B") || (Sub.Grade == "B0")) {
        Sub.GPA = (float)(3.0) * (float)Sub.Hakjum;
    }
    else if (Sub.Grade == "C+") {
        Sub.GPA = (float)(2.5) * (float)Sub.Hakjum;
    }
    else if ((Sub.Grade == "C")|| (Sub.Grade == "C0")) {
        Sub.GPA = (float)(2.0) * (float)Sub.Hakjum;
    }
    else if (Sub.Grade == "D+") {
        Sub.GPA = (float)(1.5) * (float)Sub.Hakjum;
    }
    else if ((Sub.Grade == "D")|| (Sub.Grade == "D0")) {
        Sub.GPA = (float)(1.0) * (float)Sub.Hakjum;
    }
    else {
        Sub.GPA = (float)(0.0) * (float)Sub.Hakjum;
    }

}

float CalcAveGPA(Subject* sub, int num) {
	float avg = 0;	//평균평점 계산용
	int time = 0;
	for (int i = 0;i < num; ++i) {
		avg += sub[i].GPA;	//avg에 과목평점 더하고
		time += sub[i].Hakjum;	//time에 학점수 더해서
	}
	return (avg / time);	//총 학점수로 나눔
};

inline void InputValue(string& str)// 문자열과 정수를 getline을 통해 입력받는 함수를 inline함수를 통해 같은 이름으로 구현
{
    
   getline(cin,str);
   
   
}

inline void InputValue(int &num)
{
	cin >> num;
	if (cin.fail()) {		//int형 외 자료형 입력받았을때 무한반복에러 해결
		cin.clear(); // 오류스트림을 초기화
		cin.ignore(256, '\n'); // 버퍼를 무시	
		cin >> num;
	}
}	



void InputData(Student *stu, int StudentNum)//학생수와 과목수를 비록한 정보를 입력받는 함수, Student 구조체와 학생수를 참조받음
{
    for (int i = 0; i < StudentNum; i++ )// 학생수만큼 반복
    {
    cout << "\n";
    cout << "*" << i + 1 << " 번째 학생 이름과 학번을 입력하세요." << endl;
    cout.width(10);
    cout << "이름 :";
    InputValue(stu[i].StdName);//InputValue함수(문자열)
    cout.width(10);
    cout << "학번 :";
    InputValue(stu[i].Hakbun);//InputValue함수(정수)
    cout.width(10);
    cout << "수강한 과목수:";
    InputValue(stu[i].SubNum);
    stu[i].Sub = new Subject[stu[i].SubNum];  //과목수 동적할당
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "*" << "수강한 과목의 각 교과목명, 과목학점, 과목등급을 입력하세요.\n";
        for (int j = 0; j < stu[i].SubNum; j++)
        {

            cout.width(10);
            cout << "교과목명 :";
            cin.ignore();
            InputValue(stu[i].Sub[j].SubName);
            cout.width(10);
            cout << "과목 학점수 :";
            InputValue(stu[i].Sub[j].Hakjum);
            cout.width(10);
            cout << "과목등급(A+ ~ F) :";
            cin.ignore();
            InputValue(stu[i].Sub[j].Grade);
            cout << "\n";
            CalcGPA(stu[i].Sub[j]);//학생의 과목별 평점계산
        }
    
            stu[i].AveGPA = CalcAveGPA(stu[i].Sub, stu[i].SubNum);//학생별 평균평점을 계산

        
    }    
}


void PrintOneData(const Student& std)//구조체 배열로 선언 되어있던 함수를 상수로 선언해 한 학생의 정보만 출력                                       //Stduent 구조체에 배열을 통해 두명의 학생 정보 
{
        
        cout << " 이름 : " << std.StdName << "  학번 : " << std.Hakbun << endl;
        cout.width(10); cout << "========================================================" << endl;
        cout.width(10); cout << "과목명";
        cout.width(10); cout << "과목학점";
        cout.width(10); cout << "과목등급";
        cout.width(10); cout << "과목평점" << endl;
        cout.width(10); cout << "========================================================" << endl;
        for (int j = 0; j < std.SubNum; j++)//반복문 - 과목
        {
            cout.width(10); cout << std.Sub[j].SubName;
            cout.width(10); cout << std.Sub[j].Hakjum;
            cout.width(10); cout << std.Sub[j].Grade;
            cout.width(10); cout << std.Sub[j].GPA << endl;
        }
        cout << "========================================================" << endl;
        
        cout.width(50); cout << "평균평점 : " << std.AveGPA << endl;
        cout << "\n" << endl;
    
}

void PrintAllData(const Student*pSt, int StudentNum)//printonedata 함수를 두번 호출하여 모든 학생의 성적을 출력
   {
      cout << "       전체 성적보기" << endl;
      for(int i = 0; i < StudentNum; i++)
      {
          PrintOneData((pSt[i]));
      }
    
   }

Student* StdSearch(Student* pSt, int StudentNum){
	string Std_name;
	cout << "검색할 학생의 이름을 입력 : ";
	cin.ignore();
	getline(cin, Std_name);
	if (pSt == NULL) {//학생 입력없이 검색호출시 오류
		return NULL;
	}
	for (int i = 0;i < 2;i++) {
		for (int j = 0; j < strlen(Std_name.c_str()) && pSt[i].StdName[j] == Std_name[j] && strlen(Std_name.c_str()) == strlen(pSt[i].StdName.c_str()); j++) {	//j<입력한 이름길이만큼 반복, pSt에 저장된 이름이랑 검색한 이름,길이 같음
			if (j == strlen(Std_name.c_str()) - 1) return &pSt[i];	//있으면 해당 학생 리턴
		}
	}
	return NULL;
}	//없으면 NULL 리턴// 학생이름(inname)을 입력받아


Subject* SubSearch(const Student* pSt) {	// pSt : 학생정보가 담긴 Student 포인터 변수
	string searchSub;
	cout << "검색 할 과목 이름 : ";
	getline(cin, searchSub);	// 특정 과목 이름을 입력 후,
	for (int i = 0; i < pSt[0].SubNum; i++) {
		if (searchSub == pSt[0].Sub[i].SubName) {	// pSt.Sub[i]를 사용하여 해당 교과목이 있는지 탐색
			return &pSt[0].Sub[i];					// 리턴값 : 해당 학생의 특정 교과목이 있는 곳의 주소
		}
	}
	return NULL;
}


void ModifyStdInfo(Student* pSt, int stuNum) {
	Student* ChangeStd;
	ChangeStd = StdSearch(pSt, stuNum);	//바꿀 학생 정보 검색 저장할 구조체
	if (ChangeStd != NULL) {
		string info; //”학생정보” 또는 “과목정보” 문자열 저장용 string
		cout << "수정(학생정보/과목정보) : ";
		InputValue(info); // Type 입력 함수 오버로딩 이용한 입력 함수
		if (info == "학생정보") {
			cout << "*( " << ChangeStd[0].StdName << ", " << ChangeStd[0].Hakbun << " )의 정보를 수정하세요" << endl;
			cout << "이름 : ";
			InputValue(ChangeStd[0].StdName);
			cout << "학번 : ";
			InputValue(ChangeStd[0].Hakbun);
		}
		else if (info == "과목정보") {
			Subject* Subinfo;	//과목탐색 결과 받을 구조체1
			Subinfo = SubSearch(pSt); // 교과목 탐색
			if (Subinfo != NULL) {		//탐색한 과목 정보 수정
				cout << "*( " << Subinfo[0].SubName << ", " << Subinfo[0].Hakjum << ", " << Subinfo[0].Grade << " )의 정보를 수정하세요" << endl;
				cout << "교과목명 : ";
				InputValue(Subinfo[0].SubName);
				cout << "과목학점 : ";
				InputValue(Subinfo[0].Hakjum);
				cout << "과목등급 : ";
				InputValue(Subinfo[0].Grade);
				CalcGPA(Subinfo[0]);
				ChangeStd[0].AveGPA = CalcAveGPA(ChangeStd[0].Sub, ChangeStd[0].SubNum);	// 과목의 등급과 학점수가 바뀌었으므로 평점 다시계산
			}
			else cout << "검색한 과목이 없습니다.\n\n";
		}
		else
			cout << "잘못 입력하였습니다.\n\n";
	}
	else
		cout << "검색한 학생이 없습니다.\n\n";
}

int main(){//메인함수

    cout.precision(2);//소수점 두번째자리까지 출력
    cout << fixed;

    
    int i = 0; 
    char menu;
    cout << "학생수를 입력하세요 : ";
    cin >> StdNum;
    Student* std;
    std = new Student[StdNum];// Student구조체를 입력받은 학생수만큼 동적할당

    for (i = 0; i < StdNum; i++) {
        std[i].AveGPA = 0;}   // 학생 평점계산시 오류가 발생하여 평점을 초기화함3

    while (true)//while문을 통해 '4'을 입력하기 전까지 반복되도록함
    {

        PrintMenu();
        cin >> menu;

        if (menu == '5') {
            cout << "프로그램을 종료합니다.";  //while문을 통해 '4'을 입력하기 전까지 반복되도록함
            break;
        }
        switch (menu)//번호입력에 따라 다른 결과
        {
        case '1':
        {
            cin.ignore();
            InputData(std, StdNum);
            break;


        }

        case '2': { //평점 정보 출력

            PrintAllData(std, StdNum);
            break;

        }


        case '3': 
         {
            
			Student* search;	//검색용 search 선언
			search = StdSearch(std, StdNum);
			if (search != NULL) PrintOneData(*search);	//있으면 출력
			else if (search == NULL) cout << "검색한 학생이 없습니다.\n";
            
            break;
         }

        case '4':
        {
            ModifyStdInfo(std,StdNum);
        }



        }
    }
    delete []std;//동적할당 된 메모리 해제





}








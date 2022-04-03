
#include <iostream>
#include <cstring>  //입출력, 문자열 입력을 위한 헤더파일
using namespace std;


void PrintMenu(void)//프로그램 실행시 메뉴화면 출력
{
    cout << "\n";
    cout << "------- 메뉴 ------" << endl;
    cout << "1. 학생 성적 입력" << endl;
    cout << "2. 전체 학생 성적 보기" << endl;
    cout << "3. 학생 이름 검색" << endl;
    cout << "4. 프로그램 종료\n" << endl;
    cout << "원하는 기능을 입력하세요 : ";
}




struct Subject {//과목정보
    char SubName[30];
    int Hakjum;
    char Grade[10];
    float GPA;

};


struct Student {//학생정보
    char StdName[30];
    int Hakbun;
    Subject Sub[3];
    float AveGPA;
};


void CalcGPA(Subject& Sub)// if문과 strcmp를 사용하여 학점(문자열)을 평점(실수)로 변환하는 함수 
{

    if (strcmp(Sub.Grade, "A+") == 0) {
        Sub.GPA = (float)(4.5) * (float)Sub.Hakjum; //평점*학점
    }
    else if (strcmp(Sub.Grade, "A") == 0 || strcmp(Sub.Grade, "A0") == 0) {
        Sub.GPA = (float)(4.0) * (float)Sub.Hakjum; 
    }
    else if (strcmp(Sub.Grade, "B+") == 0) {
        Sub.GPA = (float)(3.5) * (float)Sub.Hakjum;
    }
    else if (strcmp(Sub.Grade, "B") == 0 || strcmp(Sub.Grade, "B0") == 0) {
        Sub.GPA = (float)(3.0) * (float)Sub.Hakjum;
    }
    else if (strcmp(Sub.Grade, "C+") == 0) {
        Sub.GPA = (float)(2.5) * (float)Sub.Hakjum;
    }
    else if (strcmp(Sub.Grade, "C") == 0 || strcmp(Sub.Grade, "C0") == 0) {
        Sub.GPA = (float)(2.0) * (float)Sub.Hakjum;
    }
    else if (strcmp(Sub.Grade, "D+") == 0) {
        Sub.GPA = (float)(1.5) * (float)Sub.Hakjum;
    }
    else if (strcmp(Sub.Grade, "D") == 0 || strcmp(Sub.Grade, "D0") == 0) {
        Sub.GPA = (float)(1.0) * (float)Sub.Hakjum;
    }
    else {
        Sub.GPA = (float)(0.0) * (float)Sub.Hakjum;
    }

}

   float CalcAveGPA(Subject* Sub) //평균학점을 계산하는 함수 : 구조체 포인터를 통해 세 개의 학점을 3으로 나눔
{

   return (Sub->GPA + (Sub + 1)->GPA + (Sub + 2)->GPA) / 3;
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
        for (int j = 0; j < 3; j++)//반복문 - 과목
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
      PrintOneData((pSt[0]));
      PrintOneData((pSt[1]));
   }

Student* StdSearch(char *inname, Student *pSt, int StudentNum)// 학생이름(inname)을 입력받아 strcmp를 통해
                                                               // 구조체에 저장된 학생 이름  과 같을시 츨력하는 함수
   {   
      for (int i = 0; i < StudentNum; i++)
      {
         if (strcmp(inname, pSt[i].StdName) == 0)
            return &pSt[i];
      }

      cout << "해당 학생은 존재하지 않습니다." << endl;
      return 0;
   }   

int main()//메인함수
{
    cout.precision(2);
    cout << fixed;

    struct Student std[2];//구조체에 두명의 학생 정보 저장
    
    int i = 0; 
    char menu;

    for (i = 0; i < 2; i++) {
        std[i].AveGPA = 0;
    }// 학생 평점계산시 오류가 발생하여 평점을 초기화함

    while (true)//while문을 통해 '4'을 입력하기 전까지 반복되도록함
    {

        PrintMenu();
        cin >> menu;

        if (menu == '4') {
            cout << "프로그램을 종료합니다.";  //while문을 통해 '4'을 입력하기 전까지 반복되도록함
            break;
        }
        switch (menu)//번호입력에 따라 다른 결과
        {
        case '1':
        {
            for (i = 0; i < 2; i++)
            {
                cout << "\n";
                cout << "*" << i + 1 << " 번째 학생 이름과 학번을 입력하세요." << endl;
                cout.width(10);
                cout << "이름 :";
                cin >> std[i].StdName;
                cout.width(10);
                cout << "학번 :";
                cin >> std[i].Hakbun;
                cout << "\n";
                cout << "\n";
                cout << "\n";
                for (int j = 0; j < 3; j++)
                {

                    cout << "*수강한 과목 3개와 각 교과목명, 과목학점, 과목등급을 입력하세요." << endl;
                    cout.width(10);
                    cout << "교과목명 :";
                    cin >> std[i].Sub[j].SubName;
                    cout.width(10);
                    cout << "과목 학점수 :";
                    cin >> std[i].Sub[j].Hakjum;
                    cout.width(10);
                    cout << "과목등급(A+ ~ F) :";
                    cin >> std[i].Sub[j].Grade;
                    cout << "\n";
                    CalcGPA(std[i].Sub[j]);//학생의 과목별 평점계산
                    
                    
                }
                std[i].AveGPA = CalcAveGPA(&(std[i].Sub[0]));


               
            }
            break;


        }

        case '2': { //평점 정보 출력

            PrintAllData(std, 2);
            break;

        }
        case '3': 
         {
            
            char inname[20];
            cout << "검색 할 학생 이름 : ";
            cin >> inname;
            Student *find = StdSearch(inname, std, 2);
            if (find != 0)
               PrintOneData(*find);
            
            break;
         }



        }
    }





}








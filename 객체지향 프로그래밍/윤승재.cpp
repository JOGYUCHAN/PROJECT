/***************************************************************/
/*             HW#4 : 성적처리프로그램#3                       */
/*  작성자 : 윤승재                    날짜 : 2022년 4월 7일   */
/*                                                             */
/* 문제 정의 :  인라인 함수를 이용하여 성적처리프로그램의 개선 */
/*              전체 학생 목록 보기와 정보 수정 기능 추가      */
/***************************************************************/

#include<iostream>
#include<string.h>
using namespace std;

struct Subject {
   char SubName[30];   //과목 이름
   int Hakjum;         //과목 학점
   char Grade[10];      //과목 등급
   float GPA;         //과목 평점
};

struct Student {
   char StdName[30];   //학생 이름
   int Hakbun;         //학번
   Subject *Sub;   //과목(동적할당 받을거니까 포인터로)
   int SubNum;         //과목 수
   float AveGPA;      //교과목 평균 평점
};

//Student std_arr[2];


void CalcGPA(Subject& sub) {      //교과목 평점 계산
   float Sub_score = 0;   //과목등급 점수 저장

   if (strcmp(sub.Grade, "A+") == 0) Sub_score += 4.5;
   else if (strcmp(sub.Grade, "A") == 0) Sub_score += 4.0;
   else if (strcmp(sub.Grade, "B+") == 0) Sub_score += 3.5;
   else if (strcmp(sub.Grade, "B") == 0) Sub_score += 3.0;
   else if (strcmp(sub.Grade, "C+") == 0) Sub_score += 2.5;
   else if (strcmp(sub.Grade, "C") == 0) Sub_score += 2.0;
   else if (strcmp(sub.Grade, "D+") == 0) Sub_score += 1.5;
   else if (strcmp(sub.Grade, "D") == 0) Sub_score += 1.0;
   else if (strcmp(sub.Grade, "F") == 0) Sub_score += 0.0;

   // 과목평점 저장 
   sub.GPA = Sub_score * sub.Hakjum;

};

float CalcAvgGPA(Subject* sub) {
   float avg = 0;   //평균평점 계산용
   int time = 0;
   for (int i = 0;i < 3;++i) {
      avg += sub[i].GPA;   //avg에 과목평점 더하고
      time += sub[i].Hakjum;   //time에 학점수 더해서
   }
   return (avg / time);   //총 학점수로 나눔
};



Student* StdSearch(Student* pSt, int StudentNum) {   //학생 한명 검색
   char Std_name[30];   //검색할 이름 받을 용도
   cout << "검색할 학생의 이름을 입력 : ";
   cin >> Std_name;
   //if(Std_name)
   for (int i = 0;i < 2;i++) {
      for (int j = 0; j < strlen(Std_name) && pSt[i].StdName[j] == Std_name[j] && strlen(Std_name) == strlen(pSt[i].StdName); j++) {   //j<입력한 이름길이만큼 반복, pSt에 저장된 이름이랑 검색한 이름,길이 같음
         if (j == strlen(Std_name) - 1) return &pSt[i];   //있으면 해당 학생 리턴
      }
   }
   return NULL;   //없으면 NULL 리턴
};

void PrintOneData(const Student& rSt) {   //주소 받아서 사용   /학생 한명 출력
   cout.width(10);
   cout << "이름 : " << rSt.StdName << "     학번 : " << rSt.Hakbun << "\n";
   cout.width(10);
   cout << "========================================================\n";
   cout.width(10);
   cout << "       과목명    과목학점    과목등급    과목평점\n";
   for (int i = 0;i < rSt.SubNum;i++) {
      cout.width(10);
      cout << "          " << rSt.Sub[i].SubName << "          " << rSt.Sub[i].Hakjum << "          " << rSt.Sub[i].Grade << "          " << rSt.Sub[i].GPA << "\n";
   }
   cout << "========================================================\n";
   cout << "                                평균평점      " << "\t" << rSt.AveGPA << "\n\n";
};

void PrintAllData(const Student* pSt, int StudentNum) {//printonedata가 주소 받아야하니까 포인터로, 학생수 만큼 반복.   /학생 전부 출력
   cout.width(10);
   cout << "\n           전체 학생 성적 보기\n";
   cout << "========================================================\n";

   for (int i = 0;i < StudentNum;i++) {
      PrintOneData(pSt[i]);      //학생 수만큼 PinrtOneData 반복
   }
};


inline void PrintMenu() {   //메뉴 출력
   cout.width(10);
   cout << "===== 메뉴 =====\n";
   cout.width(10);
   cout << "1. 학생 성적 입력\n";
   cout.width(10);
   cout << "2. 전체 학생 성적 보기\n";
   cout.width(10);
   cout << "3. 학생 이름 검색\n";
   cout.width(10);
   cout << "4. 전체 학생 목록 보기\n";
   cout.width(10);
   cout << "5. 학생 정보 수정\n";
   cout.width(10);
   cout << "6. 프로그램 종료\n";
   cout.width(10);
   cout << "\n원하는 기능을 입력하세요 : ";
};

inline void Input_Value(char* str) {
   cin >> str;
};

inline void Input_Value(int& i) {
   cin >> i;
};

void InputData(Student* pSt, int StudentNum) {   //pSt : 수정할 학생정보포인터매개변수, StudentNum : 전체 학생 수
   for (int i = 0;i < StudentNum;i++)   {
      cout << "*" << i + 1<<" 번째 학생 이름과 학번을 입력하세요.\n";
      cout << "이름 : ";
      Input_Value(pSt[i].StdName);
      cout << "학번 : ";
      Input_Value(pSt[i].Hakbun);
      pSt[i].SubNum = 0;
      cout << "수강한 과목 수를 입력";
      Input_Value(pSt[i].SubNum);
      pSt[i].Sub = new Subject[pSt[i].SubNum];
      cout << "*" << "수강한 과목의 각 교과목명, 과목학점, 과목등급을 입력하세요.\n";
      for (int j = 0; j < pSt[i].SubNum; j++) {
         cout.width(10);
         cout << "교과목명 : ";
         Input_Value(pSt[i].Sub[j].SubName);   
         cout.width(10);
         cout << "과목 학점수 : ";
         Input_Value(pSt[i].Sub[j].Hakjum);   
         cout.width(10);
         cout << "과목등급(A+ ~f) : ";
         Input_Value(pSt[i].Sub[j].Grade);   
         cout << "\n";
         CalcGPA(*pSt[i].Sub);
      }
      pSt[i].AveGPA = CalcAvgGPA(pSt[i].Sub);
   }

}

void PrintAllStdList(const Student* pSt, int StudentNum) {   //이름 학번만 출력
   cout << "이름\t\t" << "학번\n";
   for (int i = 0; i < StudentNum; i++) {
      cout << pSt[i].StdName << "\t\t" << pSt[i].Hakbun << "\n";
   }
   cout << "\n\n";
}

void ModifyStdInfo(Student* pSt) { //학생 정보 수정 
   Student* ChangeStd; //바꾼 정보 저장할거라서 포인터
   ChangeStd = StdSearch(pSt, 2);
   if (ChangeStd != NULL) { // 수정 
      cout << " (" << ChangeStd[0].StdName << ", " << ChangeStd[0].Hakbun << ")의 정보를 수정하세요" << endl;
      cout << "이름 : ";
      Input_Value(ChangeStd[0].StdName);
      cout << "학번 : ";
      Input_Value(ChangeStd[0].Hakbun);
   }
}

int main(){
   cout.precision(2);
   cout << fixed;

   int num = 0;
   int StdNum = 0;
   cout << "학생수를 입력하세요 : ";
   cin >> StdNum;
   Student* std;
   std = new Student[StdNum];
   /*for (int i = 0;i < StdNum; i++)
      cout << std+i << "\n";*/

   while (1) {
      PrintMenu();
      cin >> num;
      if (num == 1){
            InputData(std, StdNum);
         }
         //   cout.width(10);
         //   cout << "\n" << "* " << n + 1 << " 번째 학생 이름과 학번을 입력하세요.\n";
         //   cout.width(10);
         //   cout << "이름 : ";
         //   Input_Value(std[n].StdName);      //n번째 학생 이름 입력받기
         //   cout.width(10);
         //   cout << "학번 : ";
         //   Input_Value(std[n].Hakbun);      //n번째 학생 학번 입력받기
         //   cout << "\n";

         //   cout.width(10);
         //   cout << "* 수강한 과목 3개와 각 교과목명, 과목학점, 과목등급을 입력하세요.\n";
         //   for (int i = 0;i < 3;++i) {      //n번학생 과목 3개 입력
         //      cout.width(10);
         //      cout << "교과목명 : ";
         //      Input_Value(std[n].Sub[i].SubName);   //n번째학생 i번째 과목 교과목명 입력받기
         //      cout.width(10);
         //      cout << "과목 학점수 : ";
         //      Input_Value(std[n].Sub[i].Hakjum);   //n번째학생 i번째 과목 학점수 입력받기
         //      cout.width(10);
         //      cout << "과목등급(A+ ~f) : ";
         //      Input_Value(std[n].Sub[i].Grade);   //n번째학생 i번째 과목 과목등급 입력받기
         //      cout << "\n";
         //      CalcGPA(std[n].Sub[i]);
         //   }
         //   cout << "\n\n\n";
         //   std[n].AveGPA = CalcAvgGPA(std[n].Sub);
         //}
      else if (num == 2)
         PrintAllData(std, StdNum);
      else if (num == 3) {
         Student* search;   //검색용 search 선언
         search = StdSearch(std, StdNum);
         if (search != NULL) PrintOneData(*search);   //있으면 출력
         else if (search == NULL) cout << "검색한 학생이 없습니다.\n";
      }
      else if (num == 4) {
         PrintAllStdList(std, StdNum);
      }
      else if (num == 5) {
         ModifyStdInfo(std);
      }
      else if (num == 6) {
         delete[] std;
         cout << "프로그램을 종료합니다.";
         break;
      }
      else {               //메뉴 미선택시 메뉴 다시 출력
         //cout << "\n원하는 기능을 입력하세요 : " << "\n";

         if (cin.fail())      //int형 외 자료형 입력받았을때 무한반복에러 해결
            cout << "\n숫자를 입력해주세요" << "\n";
         cin.clear(); // 오류스트림을 초기화
         cin.ignore(256, '\n'); // 버퍼를 무시   
      }
   }
   return 0;
}
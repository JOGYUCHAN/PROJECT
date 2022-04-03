
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;


void PrintMenu(void)
{
   cout << "\n";
   cout << "------- 메뉴 ------" << endl;
   cout << "1. 학생 성적 입력" << endl;
   cout << "2. 전체 학생 성적 보기" << endl;
   cout << "3. 학생이름 검색" << endl;
   cout << "4. 프로그램 종료\n" << endl;
   cout << "원하는 기능을 입력하세요 : ";
}




struct Subject {
   char SubName[30];
   int Hakjum;
   char Grade[10];
   float GPA;

};


struct Student {
   char StdName[30];
   int Hakbun;
   Subject Sub[3];
   float AveGPA;
};


void CalcGPA(Subject& Sub)
{

   if (strcmp(Sub.Grade, "A+") == 0) {
      Sub.GPA = (float)(4.5) * (float)Sub.Hakjum;
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
      


   float CalcAveGPA(Subject* Sub)
{

   return (Sub->GPA + (Sub + 1)->GPA + (Sub + 2)->GPA) / 3;
}
   void PrintOneData(const Student& rSt)
   {
      cout << " 이름 : " << rSt.StdName << "  학번 : " << rSt.Hakbun << endl;
      cout.width(10); cout << "========================================================" << endl;
      cout.width(10); cout << "과목명";
      cout.width(10); cout << "과목학점";
      cout.width(10); cout << "과목등급";
      cout.width(10); cout << "과목평점" << endl;
      cout.width(10); cout << "========================================================" << endl;
      for (int i = 0; i < 3; i++)
      {
         cout.width(10); cout << rSt.Sub[i].SubName;
         cout.width(10); cout << rSt.Sub[i].Hakjum;
         cout.width(10); cout << rSt.Sub[i].Grade;
         cout.width(10); cout << rSt.Sub[i].GPA << endl;
      }
      cout << "========================================================" << endl;

      cout.width(50); cout << "평균평점 : " << rSt.AveGPA << endl;
      cout << "\n" << endl;
   }


   

   void PrintAllData(const Student*pSt, int StudentNum)
   {
      cout << "       전체 성적보기" << endl;
      PrintOneData((pSt[0]));
      PrintOneData((pSt[1]));
   }
   
   Student* StdSearch(char *inname, Student *pSt, int StudentNum)
   {
   

      for (int i = 0; i < StudentNum; i++)
      {
         if (strcmp(inname, pSt[i].StdName) == 0)
            return &pSt[i];
      }

      cout << "해당 학생은 존재하지 않습니다." << endl;
      return 0;
   }

   int StudentNum;
   int main()
   {
      cout.precision(2);
      cout << fixed;
   
      struct Student std[2];

      Student*pSt = nullptr;
      int i = 0;
      char menu;



      while (true)
      {

         PrintMenu();
         cin >> menu;

         if (menu == '4') {
            cout << "프로그램을 종료합니다.";
            break;
         }
         switch (menu)
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
                  CalcGPA(std[i].Sub[j]);
               }
               std[i].AveGPA = CalcAveGPA(&(std[i].Sub[0]));

            }
            break;

         }

         case '2': {

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
   



         

   
         
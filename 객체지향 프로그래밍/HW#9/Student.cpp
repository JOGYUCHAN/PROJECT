#include <iostream>
#include <string>
#include"Student.h"
#include"Subject.h"
using namespace std;

Student::Student() //디폴트 생성자 
{
   m_name = "";
   m_hakbun = 0;
   m_subnum = 0;
   m_sub = NULL;
   m_aveGPA = 0.0;
   cout << "* Student 디폴트 생성자 호출 *\n";

}

Student::Student(string name, int hakbun, int subnum, Subject* sub) // 인자있는 생성자_깊은 복사 해야함
{
   m_name = name;
   m_hakbun = hakbun;
   m_subnum = subnum;

   m_sub = new Subject[m_subnum];

   for (int i = 0; i < m_subnum; i++)
   {
      (m_sub + i)->SetName((sub + i)->GetName());
      (m_sub + i)->SetHakjum((sub + i)->GetHakjum());
      (m_sub + i)->SetGrade((sub + i)->GetGrade());
      (m_sub + i)->SetGPA((sub + i)->GetGPA()); // 
   }


   cout << "* Student 인자있는 생성자 호출 *\n";
}

Student::~Student() // 할당받은 메모리 공간 해제
{
   cout << "Student 소멸자 호출\n";
   delete[]m_sub;
   m_sub = NULL;
}

Student::Student(const Student& std) //복사생성자
{
   this->m_name = std.m_name;
   this->m_hakbun = std.m_hakbun;
   this->m_subnum = std.m_subnum;

   this->m_sub = new Subject[m_subnum];
   //과목복사가 일어나야함.

   for (int i = 0; i < m_subnum; i++)
   {
      (this->m_sub + i)->SetName((std.m_sub + i)->GetName());
      (this->m_sub + i)->SetHakjum((std.m_sub + i)->GetHakjum());
      (this->m_sub + i)->SetGrade((std.m_sub + i)->GetGrade());
      (this->m_sub + i)->SetGPA((std.m_sub + i)->GetGPA());
   }

}
void Student::InputValue(string& str) // 문자열 입력을 위한 함수
{
   getline(cin, str);
}

void Student::InputValue(int& i) // 정수 입력을 위한 함수
{
   cin >> i;
   cin.ignore(); // 버퍼 비우기
}

void Student::InputData() // 사용자로부터 데이터 입력 받기
{
   cout << "*" << "학생 이름과 학번을 입력하세요.\n";
   cout << "이름 : ";
   InputValue(m_name); // 인자가 문자열이므로 문자열 입력 함수 호출
   cout << "학번 : ";
   InputValue(m_hakbun);
   cout << "\n"; // 인자가 정수이므로 정수형 입력 함수 호출

   cout << "수강한 과목 수 입력 :";
   InputValue(m_subnum);

   m_sub = new Subject[m_subnum]; // 입력받은 과목 수 만큼 과목 정보 공간을 동적할당


   for (int j = 0; j < (m_subnum); j++)
   {
      cout << "* 수강한 교과목" << m_subnum << "개와 각 교과목명, 과목학점, 과목등급을 입력하세요.\n";
      (m_sub + j)->InputData(); // 한과목씩 과목 정보 입력
   }

}

void Student::CalcAveGPA(float sum, float haksum) // 전체 학점 평균을 계산하는 함수
{
   m_aveGPA = sum / haksum; // 평점들의 합/ 총 학점 수
}

void Student::PrintData() // 정보 출력
{
   float sum = 0; // 평균 평점을 더해서 받을 변수
   float haksum = 0; // 전체 학점 수를 더해서 받을 변수
   cout.width(10);
   cout << "이름 : " << m_name; // 이름출력
   cout.width(10);
   cout << "학번 : " << m_hakbun << "\n" << "\n"; // 학번출력
   cout.width(20);

   m_sub->PrintTitle(); //Subject 클래스의 PrintTitle() 호출

   for (int p = 0; p < m_subnum; p++) // 입력받은 과목수 만큼 반복문을 돌면서
   {
      (m_sub + p)->PrintData(); // 각 과목 정보 출력
      haksum = haksum + (m_sub + p)->GetHakjum(); // 각 과목의 학점수를 더하여 변수에 합을 할당_접근자 함수를 사용하여 접근가능
      sum = sum + (m_sub + p)->GetGPA(); // 각 과목의 평점을 더하여 변수에 할당_접근자 함수를 사용하여 접근가능
   }

   cout << "--------------------------------------------------------------------\n";
   cout.width(45);
   CalcAveGPA(sum, haksum); // 평균평점 계산
   cout << "평균 평점 :" << m_aveGPA << "\n" << "\n";

}

void Student::Modify()
{
   string Type; // 학생정보 또는 과목정보 문자열 저장용 string
   cout << "수정<학생정보/과목정보/모두>:"; // 수정할 내용 입력
   InputValue(Type);

   if (Type == "학생정보") // 학생정보 수정이면
   {
      cout << "*< " << m_name << "  " << m_hakbun << " >의 정보를 수정하세요\n";
      cout << "이름 : ";
      InputValue(m_name); // 인자가 문자열이므로 문자열 입력 함수 호출
      cout << "학번 : ";
      InputValue(m_hakbun);
      cout << "\n";
   }
   else if (Type == "과목정보") // 과목정보 수정_어떤 과목을 수정할 것인지 과목 찾기
   {
      string subject; // string 문자열 객체
      cout << "검색할 과목 이름 :"; // 교과목이 있는지 검색
      InputValue(subject);
      int i;
      for (i = 0; i < m_subnum; i++) // 수강하는 과목의 수만큼 반복
      {
         if (subject == (m_sub + i)->GetName()) // 입력받은 과목과 수강 과목들을 차례대로 비교
         {
            (m_sub + i)->Modify();
            break;
         }
         else
            continue; // 일치하는 과목을 찾지 못했다면, 계속 다음 반복을 수행
      }
      if (i == m_subnum)
      {
         cout << "일치하는 과목이 없습니다. \n"; // 일치하는 과목이 없을 경우, 메세지 출력
      }

   }
   else if (Type == "모두")
   {
      cout << "*< " << m_name << "  " << m_hakbun << " >의 정보를 수정하세요\n";
      cout << "이름 : ";
      InputValue(m_name); // 인자가 문자열이므로 문자열 입력 함수 호출
      cout << "학번 : ";
      InputValue(m_hakbun);
      cout << "\n";

      string subject; // string 문자열 객체
      cout << "검색할 과목 이름 :"; // 교과목이 있는지 검색
      InputValue(subject);
      int i;
      for (i = 0; i < m_subnum; i++) // 수강하는 과목의 수만큼 반복
      {
         if (subject == (m_sub + i)->GetName()) // 입력받은 과목과 수강 과목들을 차례대로 비교
         {
            (m_sub + i)->Modify();
            break;
         }
         else
            continue; // 일치하는 과목을 찾지 못했다면, 계속 다음 반복을 수행
      }
      if (i == m_subnum)
      {
         cout << "일치하는 과목이 없습니다. \n"; // 일치하는 과목이 없을 경우, 메세지 출력
      }


   }

}

string Student::GetName() // 접근자함수 : 클래스 밖에서 멤버변수를 읽을 수 있게함.
{
   return m_name;
}

int Student::GetHakbun()
{
   return m_hakbun;
}

int Student::GetSubNum()
{
   return m_subnum;
}

float Student::GetAveGPA()
{
   return m_aveGPA;
}

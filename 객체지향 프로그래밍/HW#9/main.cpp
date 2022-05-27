//2019038055조규찬
#include <iostream>
#include <string>
#include "Student.h"
#include "Subject.h"
using namespace std;

int main(void)
{
   Subject sub1("컴퓨터", 3, "C+"); // 인자있는 생성자
   Subject sub2(sub1); // 복사생성자
   cout << "\n" << "sub1의 정보" << "\n";
   sub1.PrintTitle();
   sub1.PrintData();

   cout << "\n" << "sub2의 정보" << "\n";
   sub2.PrintTitle();
   sub2.PrintData();
   cout << "\n";
   sub2.Modify(); //sub2의 내용 수정
   sub2.PrintTitle(); // 수정된 내용 출력
   sub2.PrintData();
   cout << "\n";

   Student st2("홍길동", 2013909845, 1, &sub1); // 인자있는 생성자
   Student st1(st2); // 깊은 복사
   Student st3("김성령", 2015909845, 1, &sub2);


   cout << "\n" << "st1의 정보" << "\n";
   st1.PrintData();

   cout << "\n" << "st2의 정보" << "\n";
   st2.PrintData();

   cout << "\n" << "st3의 정보" << "\n";
   st3.PrintData();


   cout << "\n" << "st2의 정보수정" << "\n";
   st2.Modify(); // st2 학생의 정보 수정_
   cout << "\n" << "수정된 st2의 정보" << "\n";
   st2.PrintData();
   st1.PrintData();

   cout << "\n" << "st3의 정보" << "\n";
   st3.PrintData();

   return 0;
}
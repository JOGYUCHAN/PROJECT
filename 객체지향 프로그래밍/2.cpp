#include<iostream>
using namespace std;

int main(void){
int arr[6] = {1,2,3,4,5,6};
int *chr_ptr; // 1) int에 대한 포인터 변수 chr_ptr을 선언하는 문장작성
chr_ptr = arr ; // chr_ptr이 arr 배열이 저장되어 있는메모리 주소값을 갖도록 초기화
chr_ptr++; // chr_ptr의 값을 하나 증가 -> chr_ptr이 arr[0]에서 arr[1]의 주소값을 갖도록 증가
cout << chr_ptr << endl; // 3) 옆 문장이 실행되었을 때의결과는? -> arr[1]의 주소값 출력 
cout << *chr_ptr << endl; // 4) 옆 문장이 실행되었을 때의결과는? -> arr[1]이 가지는 값 출력
cout << arr << endl; // 5) 옆 문장이 실행되었을 때의 결과는? -> arr[0]의 주소값 출력
cout << arr+4 << endl; // 6) 옆 문장이 실행되었을 때의결과는? -> arr[4]의 주소값 출력
cout << &arr[3] << endl; // 7) 옆 문장이 실행되었을 때의결과는? -> arr[3]의 주소값 출력
cout << arr[4] << endl; //-> arr[4]가 가지는 값 출력
// arr[3]의 값을 chr_ptr을 이용하여 프린트
cout << *(chr_ptr + 1)  << endl;
return 0;
}
#include <iostream>
#include <cstring>//strcmp를 사용하기 때문에 써준다.
using namespace std;
//2019038055 조규찬

//비슷한 처리결과를 구하는 4개의 함수 Getmin함수를 매개변수 타입을 다르게 선언해 중복사용
//Getmin1 정수의 최솟값
int GetMin(int a, int b) {
	if (a > b) return b;
	else return a;
}

//Getmin2 실수의 최솟값
double GetMin(double a, double b) {
	if (a > b) return b;
	else return a;
}

//Getmin3 문자열 비교(strcmp사용)
char *GetMin( char* a, char* b) {
	int min = strcmp(a, b);
	if (min > 0) return b;
	else return a;
}

//Getmin4 배열의 최솟값
int GetMin(int a[], int size) {
	int min = a[0];
	for (int i = 1; i < size; i++)
		if (min > a[i]) min = a[i];
	return min;
}


//main함수 - 4개의 경우 모두 Getmin 함수를 호출하지만 매개변수의 타입을 다르게 호출하여 다른 함수를 사용한다
int main() {
	int a, b;//정수
	cout << "두개의 정수를 입력하세요 :";
	cin >> a >> b;
	cout << "최소값은 "<< GetMin(a, b) <<"입니다.\n";
	double c, d;//실수
	cout << "두개의 실수를 입력하세요 :";
	cin >> c >> d;
	cout << "최소값은 " << GetMin(c, d) <<"입니다.\n";
	char s1[20], s2[20];//문자열
	cout << "두개의 문자열를 입력하세요 :";
	cin >> s1 >> s2;
	cout << "최소값은 " << GetMin(s1, s2) <<"입니다.\n";
	int arr[] = { 2,19,34,387,1,45,78,45,11,29 };//배열
	cout << "배열을 원소 : ";
	for (int i = 0; i < 10; i++)
		cout << arr[i] << " ";
	cout << "\n최소값은 "<< GetMin(arr, 10) <<"입니다.\n";
	return 0;
}
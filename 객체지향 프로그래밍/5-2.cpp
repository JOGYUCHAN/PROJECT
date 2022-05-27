#include <iostream>
using namespace std;
//2019038055조규찬
template < typename T>
//템플릿 T선언


void Sort(T* arr, int size)//템플릿T를 인자로 사용하여 호출되는 변수의 자료형의 따라 다른 데이터타입우로 사용
{
	for (int i = 0; i < size - 1; i++)// 선택정렬을 통해 배열을 정렬
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] > arr[j])
			{
				T temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int main()
{
	char menu;
	while (true)
	{
		cout << "1. 정수 정렬\n";
		cout << "2. 실수 정렬\n";
		cout << "3. 종료\n";
		cout << "메뉴 선택: ";
		cin >> menu;
		//3을 했을경우 종료
		if (menu == '3')
			break;
		switch (menu)
		{
		case '1':
		{//정수를 받는 경우
			int arr[5];
			cout << "5개의 정수를 입력하세요: ";
			for (int i = 0; i < 5; i++)
				cin >> arr[i];
			Sort(arr, 5);//int형 변수 arr를 사용해 호출하여 T = int형 변수로 사용됨
			cout << "정렬 결과 : ";
			for (int i = 0; i < 5; i++) 
				cout << arr[i] << " ";
			cout << "\n";
			break;
		}
		case '2':
		{//실수를 받는 경우
			double arr[5];
			cout << "5개의 실수를 입력하세요: ";
			for (int i = 0; i < 5; i++)
				cin >> arr[i];
			Sort(arr, 5);//double형 변수 arr를 사용해 호출하여 T = int형 변수로 사용됨
			cout << "정렬 결과 : ";
			for (int i = 0; i < 5; i++)
				cout << arr[i] << " ";
			cout << "\n";
			break;
		}
		break;
		default:
		cout << "잘못 입력하셨습니다.\n";
		continue;
		}
	}
	return 0;
}
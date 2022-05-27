//2019038055조규찬
#include <iostream>
#include <string>
#include <vector>//vector클래스 사용을위한 헤더파일 선언
using namespace std;

struct WORD {//문자열과 카운트 정보를 저장하는 구조체
	string str;
	int count;
};

vector <WORD*> words;//vector 클래스로 구조체를 words로 선언

int FindWords(const string& s) { //FindWords함수 - 	문자열이 기존에 존재하면 빈도수를 반환하고 아닐 시 -1 반환
	for(int i = 0; i<words.size(); i++){
		if(words[i]->str == s)
			return i;
	}
	return -1;
}

void CountWords(const string& s) {//CountWords함수 - FindWords함수에서 -1반환시 구조체에 새로운 단어로 추가하고 카운트를 1로 설정
								  // 아닐 시 카운트 +1
	int index = FindWords(s);

	if(index == -1) {
		WORD *pWord = new WORD;
		pWord->str = s;
		pWord->count = 1;
		words.push_back(pWord);//새 원소를 삽입(처음 입력된 문자열)
	}

	else {
		words[index]->count++;
	}
}

void PrintWords() {//PrintWords - 단어의 종류와 빈도수를 출력
	for(int i=0; i<words.size(); i++)
		cout << words[i]->str << " : " << words[i]->count << endl;
}

void RemoveAll() {//빈도수를 출력 후 단어를 삭제
	for(int i=0; i<words.size(); i++)
		delete words[i];
}
int main() {
	cout << "문자열입력, Ctrl+Z 종료" << endl;
	string buffer;
	
	while( cin >> buffer)//버퍼에 입력될 때 마다 vetor를 이용해 빈도수를 계산한다
		CountWords(buffer);

	PrintWords();
	RemoveAll();

	return 0;
}

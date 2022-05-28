#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct WORD {
	string str;
	int count;
};

vector <WORD*> words;//vector선언

int FindWords(const string& s);
void CountWords(const string& s);
void PrintWords();
void RemoveAll();

int main() {
	cout << "문자열입력. Ctrl+Z 종료" << endl;
	string buffer;
	
	while( cin >> buffer)
		CountWords(buffer);

	PrintWords();
	RemoveAll();

	return 0;
}

void CountWords(const string& s) {
	int index = FindWords(s);

	if(index == -1) {
		WORD *pWord = new WORD;
		pWord->str = s;
		pWord->count = 1;
		words.push_back(pWord);
	}

	else {
		words[index]->count++;
	}
}

int FindWords(const string& s) {
	for(int i = 0; i<words.size(); i++){
		if(words[i]->str == s)
			return i;
	}
	return -1;
}

void PrintWords() {
	for(int i=0; i<words.size(); i++)
		cout << words[i]->str << " : " << words[i]->count << endl;
}

void RemoveAll() {
	for(int i=0; i<words.size(); i++)
		delete words[i];
}
//1234'
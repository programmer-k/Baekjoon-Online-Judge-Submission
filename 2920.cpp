/*
파일 이름 : 2920.cpp
제작자 : 정지운
제작 날짜 : 2017년 5월 20일
제작 목표 : 1차원 배열을 활용한다.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int notes[8];
	int asc = 0;
	int des = 0;

	for (int i = 0; i < 8; i++)
		cin >> notes[i];

	for (int i = 0; i < 8; i++)
	{
		if (i + 1 == notes[i])
			asc++;
		else if (notes[i] == 8 - i)
			des++;
	}

	if (asc == 8)
		cout << "ascending" << endl;
	else if (des == 8)
		cout << "descending" << endl;
	else
		cout << "mixed" << endl;

	return 0;
}
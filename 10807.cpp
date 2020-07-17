/*
파일 이름 : 10807.cpp
제작자 : 정지운
제작 날짜 : 2017년 7월 29일
*/

#include <iostream>
using namespace std;

int main(void)
{
	int arrlen;
	int arr[100];
	int num;

	// 입력
	cin >> arrlen;
	for (int i = 0; i < arrlen; i++)
		cin >> arr[i];
	cin >> num;

	// 검사
	int cnt = 0;
	for (int i = 0; i < arrlen; i++)
	{
		if (num == arr[i])
			cnt++;
	}

	// 출력
	cout << cnt << endl;
}
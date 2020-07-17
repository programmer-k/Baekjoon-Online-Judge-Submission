/*
파일 이름 : 8393.cpp
제작자 : 정지운
제작 날짜 : 2017년 5월 20일
제작 목표 : 1부터 입력받은 수까지의 합을 구한다.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int num;
	cin >> num;
	
	int sum = 0;
	for (int i = 1; i <= num; i++)
		sum += i;

	cout << sum << endl;
	return 0;
}
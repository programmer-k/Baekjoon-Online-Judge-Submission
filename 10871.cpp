/*
파일 이름 : 10871.cpp
제작자 : 정지운
제작 날짜 : 2017년 5월 16일
제작 목표 : X보다 작은 수를 모두 출력한다.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int nums, num;
	cin >> nums >> num;

	// 배열을 만들어서 수열을 저장한다.
	int * ptr = new int[nums];

	for (int i = 0; i < nums; i++)
		cin >> ptr[i];

	// X보다 작은 수를 모두 출력한다.
	for (int i = 0; i < nums; i++)
		if (ptr[i] < num)
			cout << ptr[i] << ' ';

	delete[]ptr;
	return 0;
}
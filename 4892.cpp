/*
파일 이름 : 4892.cpp
제작자 : 정지운
제작 날짜 : 2017년 8월 4일
*/

#include <iostream>
using namespace std;

int main(void)
{
	int i = 1;
	while (true)
	{
		int n0;

		// 입력
		cin >> n0;

		// 탈출 조건
		if (n0 == 0)
			break;

		// n1 구하기
		int n1 = n0 * 3;

		// 출력
		if (n1 % 2 == 0)
			cout << i << ". even ";
		else
			cout << i << ". odd ";

		// n2 구하기
		int n2;
		if (n1 % 2 == 0)
			n2 = n1 / 2;
		else
			n2 = (n1 + 1) / 2;

		// n3 구하기
		int n3 = 3 * n2;

		// n4 구하기
		int n4 = n3 / 9;

		// 출력
		cout << n4 << endl;

		i++;
	}
	return 0;
}
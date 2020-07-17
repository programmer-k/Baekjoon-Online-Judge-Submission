/*
파일 이름 : 3034.cpp
제작자 : 정지운
제작 날짜 : 2017년 7월 14일
프로그램 용도 : 성냥이 박스 안에 들어갈 수 있는지 검사한다.
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	int n, height, width;

	// 입력
	cin >> n >> height >> width;

	// 최대 길이 계산
	double max = sqrt(height * height + width * width);

	// n의 크기만큼 반복
	for (int i = 0; i < n; i++)
	{
		// 입력
		int length;
		cin >> length;

		// 조건 검사
		if (length <= max)
			cout << "DA" << endl;
		else
			cout << "NE" << endl;
	}
	return 0;
}
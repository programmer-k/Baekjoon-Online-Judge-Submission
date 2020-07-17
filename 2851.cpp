/*
파일 이름 : 2851.cpp
제작자 : 정지운
제작 날짜 : 2017년 7월 18일
프로그램 용도 : 마리오의 점수를 구한다.
*/

/* 문제를 맞추지 못하였습니다. */

#include <iostream>
using namespace std;

int main(void)
{
	int score[10];
	int lowSum = 0;
	int highSum = 0;

	// 입력
	for (int i = 0; i < 10; i++)
		cin >> score[i];

	// 계산
	for (int i = 0; i < 10; i++)
	{
		// lowSum은 100을 넘지 않는 가장 큰 수로 만들고 highSum은 100을 넘는 가장 작은 수로 만든다.
		if (lowSum + score[i] <= 100)
			lowSum += score[i];
		else
		{
			highSum = lowSum + score[i];
			break;
		}
	}

	// lowSum과 highSum 중 100에 누가 더 가까운지 비교해서 출력
	if ((100 - lowSum) < (highSum - 100))
		cout << lowSum << endl;
	else
		cout << highSum << endl;

	return 0;

}
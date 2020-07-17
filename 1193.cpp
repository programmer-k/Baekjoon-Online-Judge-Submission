/*
파일 이름 : 1193.cpp
제작자 : 정지운
제작 날짜 : 2018년 5월 12일
*/

#include <iostream>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int numerator = 1, denominator = 1;
	int num;
	int cnt = 1;
	bool numeratorIncr;
	bool hasChanged = false;

	// 입력
	cin >> num;

	while (true)
	{
		// num번째 분수를 찾으면 중단
		if (num == cnt)
			break;

		if (numerator == 1 && !hasChanged)
		{
			denominator++;
			numeratorIncr = true;
			hasChanged = true;
		}
		else if (denominator == 1 && !hasChanged)
		{
			numerator++;
			numeratorIncr = false;
			hasChanged = true;
		}
		else
		{
			if (numeratorIncr)
			{
				numerator++;
				denominator--;
			}
			else
			{
				numerator--;
				denominator++;
			}
			hasChanged = false;
		}
		cnt++;
	}

	// 출력
	cout << numerator << '/' << denominator << '\n';
	return 0;
}
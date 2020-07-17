/*
파일 이름 : 2577.cpp
제작자 : 정지운
제작 날짜 : 2017년 5월 20일
제작 목표 : 1차원 배열을 활용한다.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int A, B, C;
	cin >> A;
	cin >> B;
	cin >> C;

	int result = A * B * C;
	int ans[10] = { 0 };


	while (result != 0)
	{
		if (result % 10 == 0)
			ans[0]++;
		else if (result % 10 == 1)
			ans[1]++;
		else if (result % 10 == 2)
			ans[2]++;
		else if (result % 10 == 3)
			ans[3]++;
		else if (result % 10 == 4)
			ans[4]++;
		else if (result % 10 == 5)
			ans[5]++;
		else if (result % 10 == 6)
			ans[6]++;
		else if (result % 10 == 7)
			ans[7]++;
		else if (result % 10 == 8)
			ans[8]++;
		else if (result % 10 == 9)
			ans[9]++;

		result /= 10;
	}

	for (int i = 0; i < 10; i++)
		cout << ans[i] << endl;
	return 0;
}
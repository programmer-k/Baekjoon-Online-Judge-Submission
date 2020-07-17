/*
파일 이름 : 2439.cpp
제작자 : 정지운
제작 날짜 : 2017년 5월 15일
제작 목표 : 오른쪽 정렬한 별을 출력한다.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int num;
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		int cnt = num - (i + 1);
		while (cnt)
		{
			cout << ' ';
			cnt--;
		}

		cnt = i + 1;
		while (cnt)
		{
			cout << '*';
			cnt--;
		}
		cout << endl;
	}

	return 0;
}
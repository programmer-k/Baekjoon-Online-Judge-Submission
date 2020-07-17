/*
파일 이름 : 2490.cpp
제작자 : 정지운
제작 날짜 : 2017년 5월 20일
프로그램 용도 : 윷의 상태를 표시한다.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int yout[4];
	
	for (int j = 0; j < 3; j++)
	{
		int back, front;
		back = front = 0;

		for (int i = 0; i < 4; i++)
		{
			cin >> yout[i];
		}
		for (int i = 0; i < 4; i++)
		{
			if (yout[i] == 0)
				front++;
			else
				back++;
		}
		
		if (back == 4)
			cout << 'E' << endl;
		else if (front == 4)
			cout << 'D' << endl;
		else if (back == 1 && front == 3)
			cout << 'C' << endl;
		else if (back == 2 && front == 2)
			cout << 'B' << endl;
		else if (back == 3 && front == 1)
			cout << 'A' << endl;
	}

	return 0;
}
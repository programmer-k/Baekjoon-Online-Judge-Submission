/*
파일 이름 : 5575.cpp
제작자 : 정지운
제작 날짜 : 2017년 8월 2일
*/

#include <iostream>
using namespace std;

/* 직원의 근무 정보를 저장할 클래스를 만든다. */
class Employee
{
private:
	int hour;
	int min;
	int sec;
public:
	/* 사용자로부터 입력을 받아서 근무 시간을 계산해서 저장하는 생성자이다. */
	Employee(void)
	{
		int hour1, hour2, min1, min2, sec1, sec2;
		
		// 입력
		cin >> hour1 >> min1 >> sec1 >> hour2 >> min2 >> sec2;

		// 시간 계산
		sec = sec2 - sec1;
		if (sec < 0)
		{
			sec += 60;
			min2--;
		}

		min = min2 - min1;
		if (min < 0)
		{
			min += 60;
			hour2--;
		}

		hour = hour2 - hour1;
	}

	void ShowEmployeeInfo(void)
	{
		cout << hour << ' ' << min << ' ' << sec << endl;
	}
};

int main(void)
{
	Employee p1, p2, p3;

	// 출력
	p1.ShowEmployeeInfo();
	p2.ShowEmployeeInfo();
	p3.ShowEmployeeInfo();
	return 0;
}
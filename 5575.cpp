/*
���� �̸� : 5575.cpp
������ : ������
���� ��¥ : 2017�� 8�� 2��
*/

#include <iostream>
using namespace std;

/* ������ �ٹ� ������ ������ Ŭ������ �����. */
class Employee
{
private:
	int hour;
	int min;
	int sec;
public:
	/* ����ڷκ��� �Է��� �޾Ƽ� �ٹ� �ð��� ����ؼ� �����ϴ� �������̴�. */
	Employee(void)
	{
		int hour1, hour2, min1, min2, sec1, sec2;
		
		// �Է�
		cin >> hour1 >> min1 >> sec1 >> hour2 >> min2 >> sec2;

		// �ð� ���
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

	// ���
	p1.ShowEmployeeInfo();
	p2.ShowEmployeeInfo();
	p3.ShowEmployeeInfo();
	return 0;
}
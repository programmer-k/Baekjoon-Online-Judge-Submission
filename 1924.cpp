/*
���� �̸� : 1924.cpp
������ : ������
���� ��¥ : 2017�� 5�� 20��
���α׷� �뵵 : ������ ����Ѵ�.
*/

#include <iostream>
using namespace std;

enum
{
	SUN = 0, MON = 1, TUE = 2, WED = 3, THU = 4, FRI = 5, SAT = 6
};

int main(void)
{
	int month, day;
	cin >> month >> day;

	// ���� �޷� �ٲ۴�.
	while (month - 1 > 0)
	{
		if (month - 1 == 2)
			day += 28;
		else if (month - 1 == 4 || month - 1 == 6 || month - 1 == 9 || month - 1 == 11)
			day += 30;
		else
			day += 31;

		month--;
	}

	day %= 7;

	// ����� ����Ѵ�.
	if (day == SUN)
		cout << "SUN";
	else if (day == MON)
		cout << "MON";
	else if (day == TUE)
		cout << "TUE";
	else if (day == WED)
		cout << "WED";
	else if (day == THU)
		cout << "THU";
	else if (day == FRI)
		cout << "FRI";
	else if (day == SAT)
		cout << "SAT";
	cout << endl;
	
	return 0;
}
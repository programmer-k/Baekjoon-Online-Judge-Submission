/*
���� �̸� : 2525.cpp
������ : ������
���� ��¥ : 2017�� 7�� 24��
���α׷� �뵵 : ���챸�̰� ������ �ð��� ����Ѵ�.
*/

#include <iostream>
using namespace std;

/* ���� �÷� �ø��� �Լ��̴�. */
void ConvertMin(int * ptrMin, int * ptrHour)
{
	while (*ptrMin >= 60)
	{
		*ptrMin -= 60;
		(*ptrHour)++;
	}
}

/* �ø� 0 - 23�� ������ �ٲٴ� �Լ��̴�. */
int ConvertHour(int hour)
{
	return hour % 24;
}

int main(void)
{
	int hour, min;
	int cookMin;

	// �Է�
	cin >> hour >> min;
	cin >> cookMin;

	// ���
	min += cookMin;

	ConvertMin(&min, &hour);
	hour = ConvertHour(hour);

	// ���
	cout << hour << ' ' << min << endl;
	return 0;
}
/*
���� �̸� : 1110.cpp
������ : ������
���� ��¥ : 2017�� 5�� 20��
���� ��ǥ : if���� ����Ѵ�.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int num;
	int cnt = 0;
	cin >> num;

	if (num < 10)
		num *= 10;

	int num1 = num;
	int num2 = -1;

	while (num != num2)
	{
		num2 = (num1 % 10) * 10 + (num1 / 10 + num1 % 10) % 10;

		cnt++;
		num1 = num2;
	}

	cout << cnt << endl;
	return 0;
}
/*
���� �̸� : 2530.cpp
������ : ������
���� ��¥ : 2017�� 7�� 26��
���α׷� �뵵 : �ð��� ����Ѵ�.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int hour, min, sec;
	int cookSec;

	// �Է�
	cin >> hour >> min >> sec;
	cin >> cookSec;

	// ���
	sec += cookSec;

	// �ʸ� ������ ��ȯ
	while (sec >= 60)
	{
		sec -= 60;
		min++;
	}

	// ���� �÷� ��ȯ
	while (min >= 60)
	{
		min -= 60;
		hour++;
	}

	// �ø� 0 - 23�� ������ ����
	hour %= 24;
	
	// ���
	cout << hour << ' ' << min << ' ' << sec << endl;
	return 0;
}
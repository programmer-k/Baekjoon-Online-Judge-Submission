/*
���� �̸� : 10162.cpp
������ : ������
���� ��¥ : 2017�� 7�� 29��
*/

#include <iostream>
using namespace std;

int main(void)
{
	int cookSec;
	int btn1P, btn2P, btn3P;
	const int btn1 = 300, btn2 = 60, btn3 = 10;

	// �Է�
	cin >> cookSec;

	// ���
	btn1P = cookSec / btn1;
	cookSec %= btn1;

	btn2P = cookSec / btn2;
	cookSec %= btn2;

	btn3P = cookSec / btn3;
	cookSec %= btn3;

	// ���
	if (cookSec != 0)
		cout << -1 << endl;
	else
		cout << btn1P << ' ' << btn2P << ' ' << btn3P << endl;
	return 0;
}
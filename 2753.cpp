/*
���� �̸� : 2753.cpp
������ : ������
���� ��¥ : 2017�� 7�� 26��
���α׷� �뵵 : �������� �˻��Ѵ�.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int year;

	// �Է�
	cin >> year;

	// �������� �˻�
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		cout << 1 << endl;
	else
		cout << 0 << endl;
	return 0;
}
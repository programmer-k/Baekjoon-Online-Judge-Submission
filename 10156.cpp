/*
���� �̸� : 10156.cpp
������ : ������
���� ��¥ : 2017�� 7�� 24��
���α׷� �뵵 : ������ �θ�Բ� �޾ƾ� �ϴ� ���� �׼��� ����Ѵ�.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int snackPrice, snackNum, money;

	// �Է�
	cin >> snackPrice >> snackNum >> money;

	// ���
	int getMoney = snackPrice * snackNum - money;

	// ���
	if (getMoney >= 0)
		cout << getMoney << endl;
	else
		cout << 0 << endl;
	
	return 0;
}
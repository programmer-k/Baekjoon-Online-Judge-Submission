/*
���� �̸� : 9655.cpp
������ : ������
���� ��¥ : 2018�� 3�� 4��
*/

#include <iostream>
using namespace std;

int main(void)
{
	int num;

	// �Է�
	cin >> num;

	// ¦���̸� ù ��° �÷��̾ ����, Ȧ���̸� ù ��° �÷��̾ �̱�.
	if (num % 2 == 0)
		cout << "CY" << endl;
	else
		cout << "SK" << endl;
	return 0;
}
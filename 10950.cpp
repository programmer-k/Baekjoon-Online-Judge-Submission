/*
���� �̸� : 10950.cpp
������ : ������
���� ��¥ : 2017�� 7�� 24��
*/

#include <iostream>
using namespace std;

int main(void)
{
	int num1, num2;
	int tc;

	// �Է�
	cin >> tc;

	// tc�� ����ŭ �ݺ�
	for (int i = 0; i < tc; i++)
	{
		// �Է� �� ���
		cin >> num1 >> num2;
		cout << num1 + num2 << endl;
	}
	return 0;
}
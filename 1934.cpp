/*
���� �̸� : 1934.cpp
������ : ������
���� ��¥ : 2017�� 7�� 28��
���α׷� �뵵 : �ּ� ������� ����Ѵ�.
*/

#include <iostream>
using namespace std;

/* �ִ� ������� ��ȯ�ϴ� �Լ��̴�. */
int GCD(int num1, int num2)
{
	int num3 = -1;

	// ��Ŭ���� ȣ������ �̿��Ͽ� �ִ������� ���Ѵ�.
	while (num3 != 0)
	{
		num3 = num1 % num2;
		num1 = num2;
		num2 = num3;
	}

	return num1;
}

int main(void)
{
	int tc;

	// �Է�
	cin >> tc;

	for (int i = 0; i < tc; i++)
	{
		int num1, num2;

		//  �Է�
		cin >> num1 >> num2;

		// ���
		cout << num1 * num2 / GCD(num1, num2) << endl;
	}
	return 0;
}
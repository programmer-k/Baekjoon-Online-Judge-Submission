/*
���� �̸� : 2609.cpp
������ : ������
���� ��¥ : 2017�� 6�� 18��
���α׷� �뵵 : �ִ������� �ּҰ������ ����Ѵ�.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int num1, num2, temp;
	cin >> num1 >> num2;

	// �ּҰ������ ���ϱ� ���� num1, num2�� ���� ���� ���´�.
	const int n1 = num1;
	const int n2 = num2;

	// ��Ŭ���� ȣ������ �̿��ؼ� �ִ� ������� ���Ѵ�.
	while (true)
	{
		temp = num1 % num2;

		if (temp == 0)
			break;

		num1 = num2;
		num2 = temp;
	}

	// ��� ���
	cout << num2 << endl;
	cout << n1 * n2 / num2 << endl;
	return 0;
}
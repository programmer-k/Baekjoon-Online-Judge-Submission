/*
���� �̸� : 11021.cpp
������ : ������
���� ��¥ : 2017�� 7�� 24��
���α׷� �뵵 : A + B�� ����Ѵ�.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int tc;
	int num1, num2;

	// �Է�
	cin >> tc;

	// tc�� ����ŭ �ݺ�
	for (int i = 0; i < tc; i++)
	{
		// �Է�
		cin >> num1 >> num2;

		// ���
		cout << "Case #" << i + 1 << ": " << num1 + num2 << endl;
	}
	return 0;
}
/*
���� �̸� : 2440.cpp
������ : ������
���� ��¥ : 2017�� 5�� 20��
���� ��ǥ : ���� ����Ѵ�.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int num1;
	cin >> num1;
	int num2 = num1;

	for (int i = 0; i < num1; i++)
	{
		for (int j = 0; j < num2; j++)
			cout << '*';
		num2--;
		cout << endl;
	}
	return 0;
}
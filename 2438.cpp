/*
���� �̸� : 2438.cpp
������ : ������
���� ��¥ : 2017�� 4�� 2��
���α׷� �뵵 : ���� ����Ѵ�.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int num;

	cin >> num;

	// for���� ��ø�� �̿��ؼ� ���� ����Ѵ�.
	for (int i = 1; i <= num; i++)
	{
		for (int k = 1; k <= i; k++)
			cout << '*';

		cout << endl;
	}

	return 0;
}
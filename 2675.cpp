/*
���� �̸� : 2675.cpp
������ : ������
���� ��¥ : 2017�� 5�� 20��
���� ��ǥ : ���ڿ��� ó���Ѵ�.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int num;
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		int itr;
		cin >> itr;

		char str[21];
		cin >> str;

		for (int j = 0; str[j] != '\0'; j++)
		{
			for (int k = 0; k < itr; k++)
				cout << str[j];
		}
		cout << endl;
	}
	return 0;
}
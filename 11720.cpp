/*
���� �̸� : 11720.cpp
������ : ������
���� ��¥ : 2017�� 5�� 20��
���α׷� �뵵 : �Է����� �־��� N���� ���� ���� ����Ѵ�.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int len;
	cin >> len;

	char str[101];
	cin >> str;

	int sum = 0;
	for (int i = 0; i < len; i++)
		sum += str[i] - '0';

	cout << sum << endl;
	return 0;
}
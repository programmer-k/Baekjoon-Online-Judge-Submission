/*
���� �̸� : 10988.cpp
������ : ������
���� ��¥ : 2017�� 7�� 24��
���α׷� �뵵 : ���ڿ��� �Ӹ�������� Ȯ���Ѵ�.
*/

#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
	char str[101];
	int ans = 1;

	// �Է�
	cin >> str;

	// �Ӹ�������� �˻�
	for (int i = 0; i < strlen(str) / 2; i++)
	{
		if (str[i] != str[strlen(str) - 1 - i])
			ans = 0;
	}
	
	// ���
	cout << ans << endl;
	return 0;
}
/*
���� �̸� : 11721.cpp
������ : ������
���� ��¥ : 2017�� 5�� 20��
���α׷� �뵵 : 10���ھ� ��� ����Ѵ�.
*/

#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
	char str[101];
	cin >> str;

	for (int i = 0; i < strlen(str); i++)
	{
		cout << str[i];

		// 10���ڸ� ����� ��, ���� �ٲ۴�.
		if ((i + 1) % 10 == 0)
			cout << endl;
	}
	
	return 0;
}
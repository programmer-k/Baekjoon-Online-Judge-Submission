/*
���� �̸� : 11718.cpp
������ : ������
���� ��¥ : 2017�� 4�� 2��
���� ��ǥ : �Է¹��� ��� ����Ѵ�.
*/

#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
	char str[101];

	while (fgets(str, sizeof(str), stdin) != NULL)
	{	
		cout << str;
	}
	return 0;
}
/*
���� �̸� : 10807.cpp
������ : ������
���� ��¥ : 2017�� 7�� 29��
*/

#include <iostream>
using namespace std;

int main(void)
{
	int arrlen;
	int arr[100];
	int num;

	// �Է�
	cin >> arrlen;
	for (int i = 0; i < arrlen; i++)
		cin >> arr[i];
	cin >> num;

	// �˻�
	int cnt = 0;
	for (int i = 0; i < arrlen; i++)
	{
		if (num == arr[i])
			cnt++;
	}

	// ���
	cout << cnt << endl;
}
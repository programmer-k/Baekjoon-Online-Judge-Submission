/*
���� �̸� : 8393.cpp
������ : ������
���� ��¥ : 2017�� 5�� 20��
���� ��ǥ : 1���� �Է¹��� �������� ���� ���Ѵ�.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int num;
	cin >> num;
	
	int sum = 0;
	for (int i = 1; i <= num; i++)
		sum += i;

	cout << sum << endl;
	return 0;
}
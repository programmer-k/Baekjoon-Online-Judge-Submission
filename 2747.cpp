/*
���� �̸� : 2747.cpp
������ : ������
���� ��¥ : 2017�� 8�� 
*/

#include <iostream>
using namespace std;

int main(void)
{
	int n;
	int fibo[46];

	// �Է�
	cin >> n;

	// �Ǻ���ġ ���� ���
	fibo[0] = 0;
	fibo[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}

	// ���
	cout << fibo[n] << endl;
	return 0;
}
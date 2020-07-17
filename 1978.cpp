/*
���� �̸� : 1978.cpp
������ : ������
���� ��¥ : 2018�� 6�� 5��
*/

#include <iostream>
using namespace std;

bool IsPrime(int num)
{
	// 1�� �Ҽ��� �ƴ�.
	if (num == 1)
		return false;

	for (int i = 2; i < num; i++)
	{
		if (num % i == 0)
			return false;
	}

	return true;
}

int main(void)
{
	int num;
	int cnt = 0;

	cin >> num;

	for (int i = 0; i < num; i++)
	{
		int n;

		cin >> n;

		if (IsPrime(n))
			cnt++;
	}

	cout << cnt << endl;
	return 0;
}
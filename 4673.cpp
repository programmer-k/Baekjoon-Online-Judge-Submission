/*
���� �̸� : 4673.cpp
������ : ������
���� ��¥ : 2018�� 3�� 4��
*/

#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	vector<int> vec(10000, 0);

	// 1���� 10000������ n�� �����ؼ� d(n)�� �������� ���ϰ� d(n)�� ������ ���Ϳ� 1�� �����Ѵ�.
	for (int i = 1; i <= 10000; i++)
	{
		// d(n) ���ϱ�
		int dn = i;
		int tempNum = i;

		// �� �ڸ� �� ���ؼ� ���ϱ�
		do
		{
			dn += tempNum % 10;
			tempNum /= 10;
		} while (tempNum != 0);

		// d(n) ���ϱ� �Ϸ�!

		// d(n)�̶�� ���ڴ� �����ڰ� �����Ƿ� ���Ϳ� 1�� ����
		// d(n)�� 10000���� ũ�� ������ ������ �����Ƿ� �ǳʶڴ�.
		if (dn <= 10000)
		{
			vec[dn - 1] = 1;
		}
	}

	// ���
	for (int i = 0; i < 10000; i++)
	{
		if (vec[i] == 0)
			cout << i + 1 << endl;
	}	
	return 0;
}
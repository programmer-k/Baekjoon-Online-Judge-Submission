/*
���� �̸� : 1065.cpp
���� ��¥ : 2018�� 3�� 17��
*/

#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int num;

	// �Է�
	cin >> num;

	// �Ѽ� ���� ����
	int cnt = 0;
	for (int i = 1; i <= num; i++)
	{
		if (i < 100)
			cnt++;
		else if (i < 1000)
		{
			// �� �ڸ��� �и��ϱ�
			int temp = i;
			int one = temp % 10;
			temp /= 10;
			int ten = temp % 10;
			temp /= 10;
			int hundred = temp % 10;

			int diff = hundred - ten;
			if (hundred - ten == ten - one || ten - hundred == one - ten)
				cnt++;
		}
	}

	// ���
	cout << cnt << endl;
	return 0;
}
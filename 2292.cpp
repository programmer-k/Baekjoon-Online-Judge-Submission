/*
���� �̸� : 2292.cpp
������ : ������
���� ��¥ : 2018�� 5�� 12��
*/

#include <iostream>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	const int incr = 6;
	int num;

	// �Է�
	cin >> num;

	// ���
	int cnt = 1;
	int sum = 1;
	while (true)
	{
		if (sum >= num)
			break;

		sum += incr * cnt++;
	}

	// ���
	cout << cnt << '\n';
	return 0;
}
/*
���� �̸� : 2439.cpp
������ : ������
���� ��¥ : 2017�� 5�� 15��
���� ��ǥ : ������ ������ ���� ����Ѵ�.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int num;
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		int cnt = num - (i + 1);
		while (cnt)
		{
			cout << ' ';
			cnt--;
		}

		cnt = i + 1;
		while (cnt)
		{
			cout << '*';
			cnt--;
		}
		cout << endl;
	}

	return 0;
}
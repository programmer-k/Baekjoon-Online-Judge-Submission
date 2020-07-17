/*
���� �̸� : 4809.cpp
������ : ������
���� ��¥ : 2018�� 4�� 27��
*/

/* ���� Ǯ�� ���� - 2��° tc�� �������� ���ϰ���. */

#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main(void)
{
	int n, lowest, highest;
	int cnt = 1;

	while (true)
	{
		// �Է�
		cin >> n >> lowest >> highest;

		// Ż�� ����
		if (n == 0 && lowest == 0 && highest == 0)
			break;

		// �켱���� ť ����
		priority_queue<int> pqMax;
		priority_queue<int, vector<int>, greater<int>> pqMin;

		// ������ �Է�
		for (int i = 0; i < n; i++)
		{
			int num;
			cin >> num;

			pqMax.push(num);
			pqMin.push(num);
		}

		cout << "Case " << cnt << endl;

		// ������ ������
		for (int i = 0; i < lowest; i++)
		{
			cout << pqMin.top() << ' ';
			pqMin.pop();
		}
		cout << endl;

		for (int i = 0; i < highest; i++)
		{
			cout << pqMax.top() << ' ';
			pqMax.pop();
		}
		cout << endl;

		cnt++;
	}

	return 0;
}
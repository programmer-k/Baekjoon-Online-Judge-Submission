/*
���� �̸� : 9610.cpp
������ : ������
���� ��¥ : 2017�� 7�� 29��
*/

#include <iostream>
using namespace std;

int main(void)
{
	int tc;

	// �Է�
	cin >> tc;

	int q1, q2, q3, q4;
	int axis;
	q1 = q2 = q3 = q4 = axis = 0;

	for (int i = 0; i < tc; i++)
	{
		int x, y;

		// �Է�
		cin >> x >> y;

		// �˻�
		if (x > 0 && y > 0)
			q1++;
		else if (x < 0 && y > 0)
			q2++;
		else if (x < 0 && y < 0)
			q3++;
		else if (x > 0 && y < 0)
			q4++;
		else
			axis++;
	}

	// ���
	cout << "Q1: " << q1 << endl;
	cout << "Q2: " << q2 << endl;
	cout << "Q3: " << q3 << endl;
	cout << "Q4: " << q4 << endl;
	cout << "AXIS: " << axis << endl;
	return 0;
}
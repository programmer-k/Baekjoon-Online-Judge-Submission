/*
���� �̸� : 2851.cpp
������ : ������
���� ��¥ : 2017�� 7�� 18��
���α׷� �뵵 : �������� ������ ���Ѵ�.
*/

/* ������ ������ ���Ͽ����ϴ�. */

#include <iostream>
using namespace std;

int main(void)
{
	int score[10];
	int lowSum = 0;
	int highSum = 0;

	// �Է�
	for (int i = 0; i < 10; i++)
		cin >> score[i];

	// ���
	for (int i = 0; i < 10; i++)
	{
		// lowSum�� 100�� ���� �ʴ� ���� ū ���� ����� highSum�� 100�� �Ѵ� ���� ���� ���� �����.
		if (lowSum + score[i] <= 100)
			lowSum += score[i];
		else
		{
			highSum = lowSum + score[i];
			break;
		}
	}

	// lowSum�� highSum �� 100�� ���� �� ������� ���ؼ� ���
	if ((100 - lowSum) < (highSum - 100))
		cout << lowSum << endl;
	else
		cout << highSum << endl;

	return 0;

}
/*
���� �̸� : 5596.cpp
������ : ������
���� ��¥ : 2017�� 7�� 15��
���α׷� �뵵 : ������ ���Ѵ�.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int minGuk[4];
	int manSei[4];

	// �Է�
	for (int i = 0; i < 4; i++)
		cin >> minGuk[i];
	for (int i = 0; i < 4; i++)
		cin >> manSei[i];

	// ���
	int minGukSum = 0;
	int manSeiSum = 0;

	for (int i = 0; i < 4; i++)
		minGukSum += minGuk[i];
	for (int i = 0; i < 4; i++)
		manSeiSum += manSei[i];

	// �� �� ���
	if (minGukSum >= manSeiSum)
		cout << minGukSum << endl;
	else if (manSeiSum > minGukSum)
		cout << manSeiSum << endl;
	return 0;
}
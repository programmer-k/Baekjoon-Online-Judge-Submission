/*
���� �̸� : 5597.cpp
������ : ������
���� ��¥ : 2017�� 7�� 14��
���α׷� �뵵 : ������ �������� ���� �л��� �⼮��ȣ�� ����Ѵ�.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int studentID[30] = { 0, };

	// ������ ������ �л����� ���� 1�� �ٲ۴�.
	for (int i = 0; i < 28; i++)
	{
		// �Է�
		int ID;
		cin >> ID;

		studentID[ID - 1] = 1;
	}

	// ������ �������� ���� �л��� �⼮��ȣ�� ����Ѵ�.
	for (int i = 0; i < 30; i++)
	{
		if (studentID[i] == 0)
			cout << i + 1 << endl;
	}
	return 0;
}
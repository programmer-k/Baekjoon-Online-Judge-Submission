/*
���� �̸� : 11557.cpp
������ : ������
���� ��¥ : 2017�� 7�� 29��
*/

#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
	int tc;

	// �Է�
	cin >> tc;

	for (int i = 0; i < tc; i++)
	{
		int schoolNum;
		char school[21];
		int alcohol = -1;

		// �Է�
		cin >> schoolNum;

		for (int j = 0; j < schoolNum; j++)
		{
			char tempSchool[21];
			int tempAlcohol;

			// �Է�
			cin >> tempSchool >> tempAlcohol;

			// ���
			if (alcohol < tempAlcohol)
			{
				alcohol = tempAlcohol;
				strcpy(school, tempSchool);
			}
		}

		// ���
		cout << school << endl;
	}
	return 0;
}
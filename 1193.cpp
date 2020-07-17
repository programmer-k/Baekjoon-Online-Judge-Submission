/*
���� �̸� : 1193.cpp
������ : ������
���� ��¥ : 2018�� 5�� 12��
*/

#include <iostream>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int numerator = 1, denominator = 1;
	int num;
	int cnt = 1;
	bool numeratorIncr;
	bool hasChanged = false;

	// �Է�
	cin >> num;

	while (true)
	{
		// num��° �м��� ã���� �ߴ�
		if (num == cnt)
			break;

		if (numerator == 1 && !hasChanged)
		{
			denominator++;
			numeratorIncr = true;
			hasChanged = true;
		}
		else if (denominator == 1 && !hasChanged)
		{
			numerator++;
			numeratorIncr = false;
			hasChanged = true;
		}
		else
		{
			if (numeratorIncr)
			{
				numerator++;
				denominator--;
			}
			else
			{
				numerator--;
				denominator++;
			}
			hasChanged = false;
		}
		cnt++;
	}

	// ���
	cout << numerator << '/' << denominator << '\n';
	return 0;
}
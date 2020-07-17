/*
���� �̸� : 1735.cpp
������ : ������
���� ��¥ : 2018�� 3�� 4��
*/

#include <iostream>
using namespace std;

int GCD(int num1, int num2);

int main(void)
{
	int numerat1, numerat2, denomi1, denomi2;

	// �Է�
	cin >> numerat1 >> denomi1;
	cin >> numerat2 >> denomi2;

	// ���ϱ�
	int ansNumerat, ansDenomi;
	if (denomi1 == denomi2)
	{
		// �и� ������ �и�� �״�� ���ڸ� ���ϱ�
		ansNumerat = numerat1 + numerat2;
		ansDenomi = denomi1;
	}
	else
	{
		// �и� �ٸ��� �и� ���� �� ���ϱ�
		numerat1 *= denomi2;
		numerat2 *= denomi1;

		ansDenomi = denomi1 * denomi2;
		ansNumerat = numerat1 + numerat2;
	}

	// ���м��� �����
	// �ִ����� ���ؼ� �װɷ� ������
	int gcd;

	if (ansDenomi >= ansNumerat)
		gcd = GCD(ansDenomi, ansNumerat);
	else
		gcd = GCD(ansNumerat, ansDenomi);

	ansDenomi /= gcd;
	ansNumerat /= gcd;

	// ���
	cout << ansNumerat << ' ' << ansDenomi << endl;
	return 0;
}

/* �ִ������� ���ؼ� ��ȯ�ϴ� �Լ��̴�. */
int GCD(int num1, int num2)
{
	int remainder;

	while (true)
	{
		remainder = num1 % num2;

		if (remainder == 0)
			break;

		num1 = num2;
		num2 = remainder;
	}
	
	return num2;
}
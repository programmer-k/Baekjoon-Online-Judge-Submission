/*
���� �̸� : 10817.cpp
������ : ������
���� ��¥ : 2017�� 4�� 2��
���� ��ǥ : if���� ����Ѵ�.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int num1, num2, num3;

	cin >> num1 >> num2 >> num3;

	// �� ���� ���� �ٸ� ���� ��,
	if ((num1 < num2 && num1 > num3) || (num1 < num3 && num1 > num2))
		cout << num1 << endl;
	else if ((num2 < num1 && num2 > num3) || (num2 < num3 && num2 > num1))
		cout << num2 << endl;
	else if ((num3 < num1 && num3 > num2) || (num3 < num2 && num3 > num1))
		cout << num3 << endl;

	// �� �� �� �� ���� ���� ��,
	else if (num1 == num2 || num1 == num3)
		cout << num1 << endl;
	else if (num2 == num3)
		cout << num3 << endl;

	return 0;
}
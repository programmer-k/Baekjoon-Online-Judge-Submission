/*
���� �̸� : 10430.cpp
������ : ������
���� ��¥ : 2017�� 4�� 2��
���� ��ǥ : �� ���ڸ� �Է� ���� ��,
			ù° �ٿ� (A+B)%C, ��° �ٿ� (A%C + B%C)%C,
			��° �ٿ� (A��B)%C, ��° �ٿ� (A%C �� B%C)%C�� ����Ѵ�.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int num1, num2, num3;

	cin >> num1 >> num2 >> num3;

	cout << (num1 + num2) % num3 << endl;
	cout << (num1 % num3 + num2 % num3) % num3 << endl;
	cout << (num1 * num2) % num3 << endl;
	cout << ((num1 % num3) * (num2 % num3)) % num3 << endl;
	return 0;
}
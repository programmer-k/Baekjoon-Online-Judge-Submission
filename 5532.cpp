/*
���� �̸� : 5532.cpp
������ : ������
���� ��¥ : 2017�� 7�� 18��
���α׷� �뵵 : �� �� �ִ� �ִ��� ���� ����Ѵ�.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int days, lit, math, litPerDay, mathPerDay;

	// �Է�
	cin >> days >> lit >> math >> litPerDay >> mathPerDay;

	// ���
	int litDay, mathDay;
	litDay = lit / litPerDay;
	mathDay = math / mathPerDay;

	// �������� ������ �Ϸ� ����
	if (lit % litPerDay != 0)
		litDay++;
	if (math % mathPerDay != 0)
		mathDay++;

	// �� �� �ִ� �� ��� �� ���
	if ((days - litDay) >= (days - mathDay))
		cout << days - mathDay << endl;
	else
		cout << days - litDay << endl;

	return 0;
}
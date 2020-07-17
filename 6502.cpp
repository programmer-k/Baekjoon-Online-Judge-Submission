/*
���� �̸� : 6502.cpp
������ : ������
���� ��¥ : 2017�� 7�� 27��
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	int numOfPizza = 1;
	// ��Ź�� ���������� 0�� �Է¹��� ��쿡 ���α׷��� �����Ѵ�.
	while (true)
	{
		int radius, width, height;

		// �Է�
		cin >> radius;

		// Ż�� ����
		if (radius == 0)
			break;

		cin >> width >> height;

		// ���
		double halfDiag = sqrt(width * width + height * height) / 2.0;	// ���ڰ� å�󺸴� ũ�ٸ� ���� ���� Ƣ����� �κ��� �������̹Ƿ�

																		// ���
		if (halfDiag <= radius)
			cout << "Pizza " << numOfPizza << " fits on the table." << endl;
		else
			cout << "Pizza " << numOfPizza << " does not fit on the table." << endl;

		numOfPizza++;
	}
	return 0;
}
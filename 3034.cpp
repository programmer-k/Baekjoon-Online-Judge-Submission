/*
���� �̸� : 3034.cpp
������ : ������
���� ��¥ : 2017�� 7�� 14��
���α׷� �뵵 : ������ �ڽ� �ȿ� �� �� �ִ��� �˻��Ѵ�.
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	int n, height, width;

	// �Է�
	cin >> n >> height >> width;

	// �ִ� ���� ���
	double max = sqrt(height * height + width * width);

	// n�� ũ�⸸ŭ �ݺ�
	for (int i = 0; i < n; i++)
	{
		// �Է�
		int length;
		cin >> length;

		// ���� �˻�
		if (length <= max)
			cout << "DA" << endl;
		else
			cout << "NE" << endl;
	}
	return 0;
}
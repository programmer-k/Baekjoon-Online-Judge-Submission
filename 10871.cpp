/*
���� �̸� : 10871.cpp
������ : ������
���� ��¥ : 2017�� 5�� 16��
���� ��ǥ : X���� ���� ���� ��� ����Ѵ�.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int nums, num;
	cin >> nums >> num;

	// �迭�� ���� ������ �����Ѵ�.
	int * ptr = new int[nums];

	for (int i = 0; i < nums; i++)
		cin >> ptr[i];

	// X���� ���� ���� ��� ����Ѵ�.
	for (int i = 0; i < nums; i++)
		if (ptr[i] < num)
			cout << ptr[i] << ' ';

	delete[]ptr;
	return 0;
}
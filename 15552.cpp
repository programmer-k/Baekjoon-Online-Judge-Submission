/*
���� �̸� : 15552.cpp
������ : ������
���� ��¥ : 2018�� 5�� 12��
*/

#include <iostream>
using namespace std;

int main(void)
{
	// ���� ������� ���� ������ �� ���ֱ�!
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	// tc �Է�
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++)
	{
		int num1, num2;
		cin >> num1 >> num2;

		cout << num1 + num2 << '\n';
	}
	return 0;
}
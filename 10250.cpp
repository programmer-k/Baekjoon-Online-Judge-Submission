/*
���� �̸� : 10250.cpp
������ : ������
���� ��¥ : 2018�� 5�� 12��
*/

#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int tc;

	cin >> tc;

	for (int i = 0; i < tc; i++)
	{
		int width, height, num;

		// �Է�
		cin >> height >> width >> num;

		// �� ȣ������ ���ϱ�
		int roomNum = 1;
		while (num > height)
		{
			num -= height;
			roomNum += 1;
		}

		// ���
		if (roomNum < 10)
			cout << num << 0 << roomNum << '\n';
		else
			cout << num << roomNum << '\n';
	}
	return 0;
}
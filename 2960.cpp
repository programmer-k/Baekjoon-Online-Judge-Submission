/*
���� �̸� : 2960.cpp
������ : ������
���� ��¥ : 2018�� 3�� 4��
*/

#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int n, k;

	// �Է�
	cin >> n >> k;

	// ���ڸ� ���� ������ �ʾ����� 1, �������� 0���� ǥ��
	vector<int> vec(n, 1);

	// 1�� �ε����� �����ϱ� ���ϱ� ���� �׳� ���� ���̹Ƿ� -1�� �ʱ�ȭ�Ѵ�.
	vec[0] = -1;

	int eraseCnt = 0;

	// ���ڸ� �ϳ��� ����鼭 ī��Ʈ�ϱ�
	while (true)
	{
		// ���� �� ���ϱ�
		int start;

		if (vec[1] == 1)
			start = 1;
		else
		{
			start = 1;
			while (vec[++start] != 1)
			{

			}
		}


		for (int i = start; i < n; i += start + 1)
		{
			if (vec[i] == 1)
			{
				vec[i] = 0;
				eraseCnt++;

				// k����ŭ ī��Ʈ������ � �������� ����ϰ� ���α׷��� �����Ѵ�.
				if (eraseCnt == k)
				{
					cout << i + 1 << endl;
					return 0;
				}
			}
		}
	}
}
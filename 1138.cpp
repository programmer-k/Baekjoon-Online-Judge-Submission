#include <iostream>
using namespace std;

/*
���� �����ϴ� �迭�� 0���� �ʱ�ȭ�� �ϰ�,
�迭���� ���ʺ��� 0�� �� ���� �ִ��� ����.(0�� �ִ� ������ ������ ���ڰ� �� �����̹Ƿ� ū ���̴�.)
�־��� �Է� + 1�� ��ġ�� �����ϸ� �ȴ�.
*/

int main(void)
{
	int tc;
	cin >> tc;

	int * arr = new int[tc];
	int * ans = new int[tc];

	for (int i = 0; i < tc; i++)
	{
		cin >> arr[i];
		ans[i] = 0;
	}

	for (int i = 0; i < tc; i++)
	{
		int j = arr[i];

		if (i == 0)
			ans[j] = i + 1;
		else
		{
			int cnt = 0;
			for (int k = 0; k < 10; k++)
			{
				if (ans[k] == 0)
					cnt++;

				if (cnt == j + 1)
				{
					ans[k] = i + 1;
					break;
				}
			}
		}
	}

	for (int i = 0; i < tc; i++)
	{
		cout << ans[i] << ' ';
	}

	delete[]arr;
	delete[] ans;
	return 0;
}
#include <iostream>
using namespace std;

/*
답을 저장하는 배열을 0으로 초기화를 하고,
배열에서 왼쪽부터 0이 몇 개가 있는지 센다.(0이 있는 갯수가 앞으로 숫자가 들어갈 공간이므로 큰 수이다.)
주어진 입력 + 1의 위치에 저장하면 된다.
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
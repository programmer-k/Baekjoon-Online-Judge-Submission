/*
파일 이름 : 2775.cpp
제작자 : 정지운
제작 날짜 : 2018년 5월 12일
*/

#include <iostream>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;

	int arr[15][15];

	// 초기화
	for (int i = 1; i <= 14; i++)
		arr[0][i] = i;

	int sum;
	for (int i = 0; i < 14; i++)
	{
		sum = 0;
		for (int j = 1; j <= 14; j++)
		{
			sum += arr[i][j];
			arr[i + 1][j] = sum;
		}
	}

	for (int i = 0; i < tc; i++)
	{
		int k, n;
		cin >> k >> n;

		cout << arr[k][n] << '\n';
	}
	return 0;
}
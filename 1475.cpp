/*
파일 이름 : 1475.cpp
제작자 : 정지운
제작 날짜 : 2018년 5월 12일
*/

#include <iostream>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int num;
	cin >> num;

	int arr[9];

	for (int i = 0; i < 9; i++)
		arr[i] = 0;

	// 예외 케이스
	if (num == 0)
	{
		cout << 1 << '\n';
		return 0;
	}


	while (num != 0)
	{
		int remainder = num % 10;

		if (remainder == 9)
			arr[6] += 1;
		else
			arr[remainder] += 1;

		num /= 10;
	}

	if (arr[6] % 2 == 0)
		arr[6] /= 2;
	else
		arr[6] = arr[6] / 2 + 1;

	int biggest = -1;
	for (int i = 0; i < 9; i++)
	{
		if (biggest < arr[i])
			biggest = arr[i];
	}

	cout << biggest << '\n';
	return 0;
}
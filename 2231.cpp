#include <iostream>
using namespace std;

int main(void)
{
	int num;

	cin >> num;

	for (int i = 1; i < num; i++)
	{
		int n = i;

		// 각 자리 수 모두 더하기
		for (int temp = i; temp != 0; temp /= 10)
			n += temp % 10;

		if (n == num)
		{
			cout << i << endl;
			return 0;
		}
	}

	// 생성자가 없는 경우에는 0을 출력한다.
	cout << 0 << endl;

	return 0;
}
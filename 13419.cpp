#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int tc;

	// 입력
	cin >> tc;

	// tc만큼 반복
	for (int i = 0; i < tc; i++)
	{
		string str;
		string ans1 = "";
		string ans2 = "";

		// 문자열 입력
		cin >> str;

		int idx1 = 0;
		int idx2 = 1;
		while (true)
		{
			// 한 문자씩 쌓아놓기
			ans1 += str[idx1];

			// 한 문자 넘어가고 다음 한 문자
			idx1 += 2;

			// 인덱스 범위 넘어가면 줄이기
			if (idx1 >= str.size())
			{
				idx1 = idx1 % str.size();
			}

			if (idx1 == 0)
				break;
		}
		cout << ans1 << endl;

		if (str.size() == 1)
			cout << str << endl;
		else
		{
			while (true)
			{
				// 한 문자씩 쌓아놓기
				ans2 += str[idx2];

				// 한 문자 넘어가고 다음 한 문자
				idx2 += 2;

				// 인덱스 범위 넘어가면 줄이기
				if (idx2 >= str.size())
				{
					idx2 = idx2 % str.size();
				}
				if (idx2 == 1)
					break;
			}
			cout << ans2 << endl;
		}
	}
	return 0;
}


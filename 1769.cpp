/*
파일 이름 : 1769.cpp
제작자 : 정지운
제작 날짜 : 2018년 3월 4일
*/

/* 주어지는 입력이 백만 이하의 자연수가 아니라 백만 자리 이하의 자연수여서 long long으로도 커버가 불가능함. */
/* 파이썬으로도 시도했는데 시간 초과가 떴음. */
/* 그래서 다시 C++에서 숫자를 string 객체로 저장하는 방식을 이용해서 품. */

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main(void)
{
	string numStr;
	int cnt = 0, sum;

	// 입력
	cin >> numStr;
	
	// 한 자리수의 경우에는 연산하지 않고 바로 출력
	if (numStr.length() >= 2)
	{
		int num;

		// 한 번 변환하면 가장 큰 경우 백만 자리의 숫자이면서 모든 자리수가 9일 때 이것을 다 합하면 9를 백만 번 더하는 것이므로 9 * 백만을 해도
		// 9백만이므로 int범위 안에 충분히 들어감. 그러므로 한 번만 변환하고나서 그다음부터는 전에 쓰던 방법을 사용해도 됨.
		// 하지만 귀찮으므로 그냥 첫 번째 방법을 계속 사용하겠음.

		while (true)
		{
			sum = 0;
			// 각자리의 숫자 합 구하기
			for (int i = 0; i < numStr.length(); i++)
			{
				sum += numStr[i] - '0';
			}

			// 한 번 반복했으므로 증가
			cnt++;

			// 한 자리수면 반복 종료
			if (sum < 10)
				break;

			numStr = to_string(sum);
		}
	}
	else
	{
		sum = atoi(numStr.c_str());
	}

	// 반복을 몇 번 했는지 출력
	cout << cnt << endl;

	// 3의 배수인지 검사
	if (sum % 3 == 0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
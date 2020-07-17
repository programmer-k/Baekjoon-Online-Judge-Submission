/*
파일 이름 : 2960.cpp
제작자 : 정지운
제작 날짜 : 2018년 3월 4일
*/

#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int n, k;

	// 입력
	cin >> n >> k;

	// 숫자를 아직 지우지 않았으면 1, 지웠으면 0으로 표시
	vector<int> vec(n, 1);

	// 1은 인덱스로 접근하기 편하기 위해 그냥 넣은 것이므로 -1로 초기화한다.
	vec[0] = -1;

	int eraseCnt = 0;

	// 숫자를 하나씩 지우면서 카운트하기
	while (true)
	{
		// 시작 값 구하기
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

				// k번만큼 카운트했으면 어떤 숫자인지 출력하고 프로그램을 종료한다.
				if (eraseCnt == k)
				{
					cout << i + 1 << endl;
					return 0;
				}
			}
		}
	}
}
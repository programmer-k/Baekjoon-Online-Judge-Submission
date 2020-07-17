/*
파일 이름 : 4809.cpp
제작자 : 정지운
제작 날짜 : 2018년 4월 27일
*/

/* 문제 풀이 실패 - 2번째 tc를 이해하지 못하겠음. */

#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main(void)
{
	int n, lowest, highest;
	int cnt = 1;

	while (true)
	{
		// 입력
		cin >> n >> lowest >> highest;

		// 탈출 조건
		if (n == 0 && lowest == 0 && highest == 0)
			break;

		// 우선순위 큐 생성
		priority_queue<int> pqMax;
		priority_queue<int, vector<int>, greater<int>> pqMin;

		// 데이터 입력
		for (int i = 0; i < n; i++)
		{
			int num;
			cin >> num;

			pqMax.push(num);
			pqMin.push(num);
		}

		cout << "Case " << cnt << endl;

		// 데이터 꺼내기
		for (int i = 0; i < lowest; i++)
		{
			cout << pqMin.top() << ' ';
			pqMin.pop();
		}
		cout << endl;

		for (int i = 0; i < highest; i++)
		{
			cout << pqMax.top() << ' ';
			pqMax.pop();
		}
		cout << endl;

		cnt++;
	}

	return 0;
}
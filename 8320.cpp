/*
파일 이름 : 8320.cpp
제작자 : 정지운
제작 날짜 : 2017년 7월 18일
프로그램 용도 : 만들 수 있는 직사각형의 개수를 출력한다.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int num;
	int ans = 0;

	// 입력
	cin >> num;

	// 계산
	for (int i = 1; i <= num; i++)
	{
		for (int j = i; j <= num; j++)
		{
			// 회전을 해서 모양이 같으면 같은 직사각형이므로, 애초에 같은 모양이 나오지 않게 j를 i와 같은 숫자부터 시작한다.
			// i는 가로, j는 세로를 의미한다.
			// i * j > num이면, 안쪽의 반복문을 더 돌리는 의미가 없으므로 반복을 중지한다.
			if (i * j <= num)
				ans++;
			else
				break;
		}
	}

	// 출력
	cout << ans << endl;
	return 0;
}
/*
파일 이름 : 5032.cpp
제작자 : 정지운
제작 날짜 : 2017년 7월 25일
프로그램 용도 : 준민이가 먹을 수 있는 탄산음료의 개수를 출력한다.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int emptyBotl, findBotl, changeBotl;
	int totalBotl, ans = 0;

	// 입력
	cin >> emptyBotl >> findBotl >> changeBotl;

	// 계산 및 출력
	totalBotl = emptyBotl + findBotl;	// 가지고 있는 빈 병 수 계산

	while (totalBotl / changeBotl > 0)	// totalBotl / changeBotl의 값이 0보다 크면 ans의 값이 올라갈 수 있으므로 반복을 계속한다.
	{
		int temp = totalBotl / changeBotl;
		ans += temp;	// 얻은 음료의 개수를 추가한다.
		totalBotl = temp + totalBotl % changeBotl;	// 가지고 있는 빈 병 수 다시 설정
	}
	cout << ans << endl;
	return 0;

}
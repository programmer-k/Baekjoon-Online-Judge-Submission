/*
파일 이름 : 1914.c
제작자 : 정지운
제작 날짜 : 2017년 7월 24일
프로그램 용도 : 하노이 타워 문제의 풀이과정을 출력한다.
*/

#include <stdio.h>

//int HanoiTowerMove(int numOfCir, char from, char by, char to);
void HanoiTowerPrint(int numOfCir, char from, char by, char to);
void HanoiTower(int numOfCir, char from, char by, char to);

//int i = 0;
//char str[1000000];
long long move = 0;

int main(void)
{
	int numOfCir;

	// 입력
	scanf("%d", &numOfCir);


	HanoiTower(numOfCir, '1', '2', '3');
	printf("%d\n", move);
	if (numOfCir <= 20)
		HanoiTowerPrint(numOfCir, '1', '2', '3');

	return 0;
}
	/*
	// 계산 및 출력
	printf("%d\n", HanoiTowerMove(numOfCir, '1', '2', '3'));
	for (int j = 0; j < i; j += 2)
	{
		printf("%c %c\n", str[j], str[j + 1]);
	}
	/*

	return 0;
}

/* 하노이 타워 문제의 원반 이동 수를 반환한다. */
/*
int HanoiTowerMove(int numOfCir, char from, char by, char to)
{
	int move = 0;

	// 탈출 조건
	if (numOfCir == 1)
	{
		str[i++] = from;
		str[i++] = to;
		return 1;
	}

	move += HanoiTowerMove(numOfCir - 1, from, to, by);
	str[i++] = from;
	str[i++] = to;
	move++;
	move += HanoiTowerMove(numOfCir - 1, by, from, to);

	return move;
}
*/
/* 하노이 타워 문제의 풀이과정을 출력한다. */

void HanoiTowerPrint(int numOfCir, char from, char by, char to)
{
	// 탈출 조건
	if (numOfCir == 1)
	{
		printf("%c %c\n", from, to);
		return;
	}

	HanoiTowerPrint(numOfCir - 1, from, to, by);
	printf("%c %c\n", from, to);
	HanoiTowerPrint(numOfCir - 1, by, from, to);
}

/* 하노이 타워 문제의 원반 이동 수를 계산한다. */
void HanoiTower(int numOfCir, char from, char by, char to)
{
	// 탈출 조건
	if (numOfCir == 1)
	{
		move++;
		return;
	}

	HanoiTower(numOfCir - 1, from, to, by);
	move++;
	HanoiTower(numOfCir - 1, by, from, to);

	return move;
}
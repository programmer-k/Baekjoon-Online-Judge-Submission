/*
파일 이름 : 10951.c
제작자 : 정지운
제작 날짜 : 2017년 7월 24일
프로그램 용도 : A + B를 출력한다.
*/

#include <stdio.h>

int main(void)
{
	int num1, num2;

	// scanf함수가 입력 받은 갯수를 반환한다는 점을 이용해서 만약 입력 받을 것이 남아있지 않아 0이 반환된다면 반복문을 탈출한다.
	while (scanf("%d %d", &num1, &num2) == 2)
	{
		printf("%d\n", num1 + num2);
	}
	return 0;
}
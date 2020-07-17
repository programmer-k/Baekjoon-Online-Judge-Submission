/*
파일 이름 : 2741.c
제작자 : 정지운
제작 날짜 : 2017년 4월 2일
프로그램 용도 : 하나의 숫자를 입력받고, 그 숫자부터 1까지 차례대로 출력한다.
*/

#include <stdio.h>

int main(void)
{
	int num;

	scanf("%d", &num);

	for (int i = num; i >= 1; i--)
		printf("%d\n", i);
	
	return 0;
}
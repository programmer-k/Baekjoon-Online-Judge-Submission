/*
파일 이름 : 1377.cpp
제작자 : 정지운
제작 날짜 : 2017년 7월 28일
*/

/* 시간 초과로 인한 문제 해결 실패*/

#include <stdio.h>

int main(void)
{
	int * arr;
	int tc;

	// 입력
	scanf("%d", &tc);

	// tc의 크기만큼 동적할당 후 배열처럼 사용
	arr = (int *)malloc(sizeof(int) * (tc + 1));

	for (int i = 0; i < tc; i++)
		scanf("%d", &arr[i + 1]);

	// 주어진 코드
	int i, j, temp;
	int change;
	for (i = 1; i <= tc; i++) {
		change = 0;
		for (j = 1; j <= tc - i; j++) {
			if (arr[j] > arr[j + 1]) {
				change = 1;
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
		if (change == 0) {
			break;
		}
	}
	printf("%d\n", i);

	return 0;
}
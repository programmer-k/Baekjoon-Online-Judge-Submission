/*
파일 이름 : 1546.c
제작자 : 정지운
제작 날짜 : 2017년 5월 16일
제작 목표 : 조작된 평균을 구한다.
*/

#include <stdio.h>

int main(void)
{
	int num;
	
	scanf("%d", &num);

	// 시험 과목 수만큼 배열의 길이를 설정한다.
	int * original = (int*)malloc(sizeof(int) * num);
	double * fake = (double*)malloc(sizeof(double) * num);

	// 시험 점수를 입력받는다.
	for (int i = 0; i < num; i++)
		scanf("%d", &original[i]);

	// 최고점을 찾는다.
	int highest = 0;

	for (int i = 0; i < num; i++)
	{
		if (original[i] > highest)
			highest = original[i];
	}

	// 조작된 시험점수를 계산한다.
	for (int i = 0; i < num; i++)
		fake[i] = original[i] / (double)highest * 100;

	// 조작된 시험점수의 평균을 구한다.
	double sum = 0;

	for (int i = 0; i < num; i++)
		sum += fake[i];

	double average = sum / num;

	// 조작된 평균을 출력한다.
	printf("%.2f", average);

	// 동적 할당된 것들을 해제한다.
	free(original);
	free(fake);
	return 0;
}
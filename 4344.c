/*
파일 이름 : 4344.c
제작자 : 정지운
제작 날짜 : 2017년 5월 20일
제작 목표 : if문을 사용한다.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int testcase;
	scanf("%d", &testcase);

	// testcase의 수만큼 반복한다.
	for (int i = 0; i < testcase; i++)
	{
		int stuNum;
		scanf("%d", &stuNum);

		int * score = (int*)malloc(sizeof(int) * stuNum);

		// 점수 저장
		for (int j = 0; j < stuNum; j++)
			scanf("%d", &score[j]);

		// 평균 구하기
		int sum = 0;
		for (int j = 0; j < stuNum; j++)
			sum += score[j];

		double avg = sum / (double)stuNum;

		int overAvg = 0;
		// 평균을 넘는 학생들의 수 구하기
		for (int j = 0; j < stuNum; j++)
			if (score[j] > avg)
				overAvg++;

		// 평균을 넘는 학생들의 비율을 출력한다.
		printf("%.3f%%\n", overAvg / (double)stuNum * 100);
		
		free(score);
	}
	return 0;
}
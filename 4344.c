/*
���� �̸� : 4344.c
������ : ������
���� ��¥ : 2017�� 5�� 20��
���� ��ǥ : if���� ����Ѵ�.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int testcase;
	scanf("%d", &testcase);

	// testcase�� ����ŭ �ݺ��Ѵ�.
	for (int i = 0; i < testcase; i++)
	{
		int stuNum;
		scanf("%d", &stuNum);

		int * score = (int*)malloc(sizeof(int) * stuNum);

		// ���� ����
		for (int j = 0; j < stuNum; j++)
			scanf("%d", &score[j]);

		// ��� ���ϱ�
		int sum = 0;
		for (int j = 0; j < stuNum; j++)
			sum += score[j];

		double avg = sum / (double)stuNum;

		int overAvg = 0;
		// ����� �Ѵ� �л����� �� ���ϱ�
		for (int j = 0; j < stuNum; j++)
			if (score[j] > avg)
				overAvg++;

		// ����� �Ѵ� �л����� ������ ����Ѵ�.
		printf("%.3f%%\n", overAvg / (double)stuNum * 100);
		
		free(score);
	}
	return 0;
}
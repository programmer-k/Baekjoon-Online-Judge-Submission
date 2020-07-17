/*
���� �̸� : 1546.c
������ : ������
���� ��¥ : 2017�� 5�� 16��
���� ��ǥ : ���۵� ����� ���Ѵ�.
*/

#include <stdio.h>

int main(void)
{
	int num;
	
	scanf("%d", &num);

	// ���� ���� ����ŭ �迭�� ���̸� �����Ѵ�.
	int * original = (int*)malloc(sizeof(int) * num);
	double * fake = (double*)malloc(sizeof(double) * num);

	// ���� ������ �Է¹޴´�.
	for (int i = 0; i < num; i++)
		scanf("%d", &original[i]);

	// �ְ����� ã�´�.
	int highest = 0;

	for (int i = 0; i < num; i++)
	{
		if (original[i] > highest)
			highest = original[i];
	}

	// ���۵� ���������� ����Ѵ�.
	for (int i = 0; i < num; i++)
		fake[i] = original[i] / (double)highest * 100;

	// ���۵� ���������� ����� ���Ѵ�.
	double sum = 0;

	for (int i = 0; i < num; i++)
		sum += fake[i];

	double average = sum / num;

	// ���۵� ����� ����Ѵ�.
	printf("%.2f", average);

	// ���� �Ҵ�� �͵��� �����Ѵ�.
	free(original);
	free(fake);
	return 0;
}
/*
���� �̸� : 1377.cpp
������ : ������
���� ��¥ : 2017�� 7�� 28��
*/

/* �ð� �ʰ��� ���� ���� �ذ� ����*/

#include <stdio.h>

int main(void)
{
	int * arr;
	int tc;

	// �Է�
	scanf("%d", &tc);

	// tc�� ũ�⸸ŭ �����Ҵ� �� �迭ó�� ���
	arr = (int *)malloc(sizeof(int) * (tc + 1));

	for (int i = 0; i < tc; i++)
		scanf("%d", &arr[i + 1]);

	// �־��� �ڵ�
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
/*
���� �̸� : 2712.c
������ : ������
���� ��¥ : 2017�� 8�� 2��
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
	int tc;

	// �Է�
	scanf("%d", &tc);

	for (int i = 0; i < tc; i++)
	{
		double num;
		char str[3];

		// �Է�
		scanf("%lf %s", &num, str);

		// ��� �� ���
		if (!strcmp("kg", str))
		{
			num *= 2.2046;
			printf("%.4f lb\n", num);
		}
		else if (!strcmp("lb", str))
		{
			num *= 0.4536;
			printf("%.4f kg\n", num);
		}
		else if (!strcmp("l", str))
		{
			num *= 0.2642;
			printf("%.4f g\n", num);
		}
		else
		{
			num *= 3.7854;
			printf("%.4f l\n", num);
		}
	}
	return 0;
}
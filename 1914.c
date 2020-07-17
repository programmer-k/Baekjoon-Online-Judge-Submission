/*
���� �̸� : 1914.c
������ : ������
���� ��¥ : 2017�� 7�� 24��
���α׷� �뵵 : �ϳ��� Ÿ�� ������ Ǯ�̰����� ����Ѵ�.
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

	// �Է�
	scanf("%d", &numOfCir);


	HanoiTower(numOfCir, '1', '2', '3');
	printf("%d\n", move);
	if (numOfCir <= 20)
		HanoiTowerPrint(numOfCir, '1', '2', '3');

	return 0;
}
	/*
	// ��� �� ���
	printf("%d\n", HanoiTowerMove(numOfCir, '1', '2', '3'));
	for (int j = 0; j < i; j += 2)
	{
		printf("%c %c\n", str[j], str[j + 1]);
	}
	/*

	return 0;
}

/* �ϳ��� Ÿ�� ������ ���� �̵� ���� ��ȯ�Ѵ�. */
/*
int HanoiTowerMove(int numOfCir, char from, char by, char to)
{
	int move = 0;

	// Ż�� ����
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
/* �ϳ��� Ÿ�� ������ Ǯ�̰����� ����Ѵ�. */

void HanoiTowerPrint(int numOfCir, char from, char by, char to)
{
	// Ż�� ����
	if (numOfCir == 1)
	{
		printf("%c %c\n", from, to);
		return;
	}

	HanoiTowerPrint(numOfCir - 1, from, to, by);
	printf("%c %c\n", from, to);
	HanoiTowerPrint(numOfCir - 1, by, from, to);
}

/* �ϳ��� Ÿ�� ������ ���� �̵� ���� ����Ѵ�. */
void HanoiTower(int numOfCir, char from, char by, char to)
{
	// Ż�� ����
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
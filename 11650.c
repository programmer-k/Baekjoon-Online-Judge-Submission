/*
���� �̸� : 11650.c
������ : ������
���� ��¥ : 2017�� 7�� 31��
*/

/* �ð� �ʰ��� ���� ���� �ذ� ���� */

#include <stdio.h>
#include <stdlib.h>

/* ���� ����Ʈ ���� �ڵ�� */
#define TRUE	1
#define FALSE	0

typedef struct point
{
	int xpos;
	int ypos;
} Point;

typedef Point LData;

typedef struct _node
{
	LData data;
	struct _node * next;
} Node;

typedef struct _linkedList
{
	Node * head;
	Node * cur;
	Node * before;
	int numOfData;
	int(*comp)(LData d1, LData d2);
} LinkedList;

typedef LinkedList List;

void ListInit(List * plist)
{
	plist->head = (Node *)malloc(sizeof(Node));
	plist->head->next = NULL;
	plist->comp = NULL;
	plist->numOfData = 0;
}

void FInsert(List * plist, LData data)
{
	Node * newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = plist->head->next;
	plist->head->next = newNode;

	(plist->numOfData)++;
}

void SInsert(List * plist, LData data)
{
	Node * newNode = (Node *)malloc(sizeof(Node));		// �� ����� ����
	Node * pred = plist->head;							// pred�� ���� ��带 ����Ŵ
	newNode->data = data;								// �� ��忡 ������ ����

														// �� ��尡 �� ��ġ�� ã�� ���� �ݺ���!
	while (pred->next != NULL && plist->comp(data, pred->next->data) != 0)
	{
		pred = pred->next;			// ���� ���� �̵�
	}

	newNode->next = pred->next;		// �� ����� �������� ����
	pred->next = newNode;			// �� ����� ������ ����

	(plist->numOfData)++;			// ����� �������� �� �ϳ� ����
}

void LInsert(List * plist, LData data)
{
	if (plist->comp == NULL)
		FInsert(plist, data);
	else
		SInsert(plist, data);
}

int LFirst(List * plist, LData * pdata)
{
	if (plist->head->next == NULL)
		return FALSE;

	plist->before = plist->head;
	plist->cur = plist->head->next;

	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List * plist, LData * pdata)
{
	if (plist->cur->next == NULL)
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}

LData LRemove(List * plist)
{
	Node * rpos = plist->cur;
	LData rdata = rpos->data;

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(rpos);
	(plist->numOfData)--;
	return rdata;
}

int LCount(List * plist)
{
	return plist->numOfData;
}

void SetSortRule(List * plist, int(*comp)(LData d1, LData d2))
{
	plist->comp = comp;
}

/* ���� �ۼ��� �ڵ� */

/* �������� ������ ���� �Լ� */
int IncreaseSort(Point pos1, Point pos2)
{
	if (pos1.xpos < pos2.xpos)
		return 0;
	else if (pos1.xpos > pos2.xpos)
		return 1;
	else
	{
		if (pos1.ypos < pos2.ypos)
			return 0;
		else
			return 1;
	}
}

int main(void)
{
	int numOfPoint;
	List list;
	Point temp;
	
	// ����Ʈ �ʱ�ȭ
	ListInit(&list);
	SetSortRule(&list, IncreaseSort);

	// �Է�
	scanf("%d", &numOfPoint);

	for (int i = 0; i < numOfPoint; i++)
	{
		scanf("%d %d", &(temp.xpos), &(temp.ypos));

		// ����Ʈ�� ����
		LInsert(&list, temp);
	}

	// ���
	if (LFirst(&list, &temp))
	{
		printf("%d %d\n", temp.xpos, temp.ypos);

		while (LNext(&list, &temp))
			printf("%d %d\n", temp.xpos, temp.ypos);
	}
	return 0;
}
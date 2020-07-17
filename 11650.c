/*
파일 이름 : 11650.c
제작자 : 정지운
제작 날짜 : 2017년 7월 31일
*/

/* 시간 초과로 인한 문제 해결 실패 */

#include <stdio.h>
#include <stdlib.h>

/* 연결 리스트 관련 코드들 */
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
	Node * newNode = (Node *)malloc(sizeof(Node));		// 새 노드의 생성
	Node * pred = plist->head;							// pred는 더미 노드를 가리킴
	newNode->data = data;								// 새 노드에 데이터 저장

														// 새 노드가 들어갈 위치를 찾기 위한 반복문!
	while (pred->next != NULL && plist->comp(data, pred->next->data) != 0)
	{
		pred = pred->next;			// 다음 노드로 이동
	}

	newNode->next = pred->next;		// 새 노드의 오른쪽을 연결
	pred->next = newNode;			// 새 노드의 왼쪽을 연결

	(plist->numOfData)++;			// 저장된 데이터의 수 하나 증가
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

/* 직접 작성한 코드 */

/* 오름차순 정렬을 위한 함수 */
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
	
	// 리스트 초기화
	ListInit(&list);
	SetSortRule(&list, IncreaseSort);

	// 입력
	scanf("%d", &numOfPoint);

	for (int i = 0; i < numOfPoint; i++)
	{
		scanf("%d %d", &(temp.xpos), &(temp.ypos));

		// 리스트에 저장
		LInsert(&list, temp);
	}

	// 출력
	if (LFirst(&list, &temp))
	{
		printf("%d %d\n", temp.xpos, temp.ypos);

		while (LNext(&list, &temp))
			printf("%d %d\n", temp.xpos, temp.ypos);
	}
	return 0;
}
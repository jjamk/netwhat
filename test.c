void SetSortRule(List *plist, int (*comp)(LData d1, LData d2))
{
	plist -> comp = comp;	//comp 함수 등록
}

void Sinsert(List *plist, LData data)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	Node *pred = plist -> head;
	newNode -> data = data;

	while (pred -> next != NULL && plist -> comp(data, pred -> next -> data) != 0)
	{
		pred = pred -> next;	//다음 노드로 이동
	}
	newNode -> next = pred -> next;
	pred -> next = newNode;
	(plist -> numOfData)++;
}
void init(List *plist)
{
	plist -> head = (Node*)malloc(sizeof(Node)); //더미노드
	plist -> head -> next = NULL;
	plist -> comp = NULL;
	plist -> numOfData = 0;
}

void  insert(List *plist, LData data)
{
	if (plist -> comp == NULL) 	//정렬 기준이 없다
		Finsert(plist, data);
	else				//정렬 기준이 있다
		Sinsert(plist, data);
}

void Finsert(List *plist, LData data)
{
	Node *newnode;
	newnode = (Node*)malloc(sizeof(Node));
	newnode -> data = data;

	newNode -> next = plist -> head -> next;
	plist -> head -> next = newnode;
	
	(plist -> numOfData)++;
}

int	first(List *plist, LData *pdata)
{
	if (plist -> head -> next == NULL)
		return FALSE;
	plist -> before = plist -> head;	//before = 더미 노드
	plist -> cur = plist -> head -> next;	//cur = 첫번째 노드

	*pdata = plist -> cur -> data;
	return TRUE;
}

int	next(List *plist, LData *pdata)
{
	if (plist -> cur -> next == NULL)
		return FALSE;
	plist -> before = plist -> cur;
	plist -> cur = plist -> cur -> next;

	*pdata = plist -> cur -> data;
	return TRUE;
}

LData remove(List *plist)
{
	Node *rpos = plist -> cur; //cur을 rpos에 백업
	LData rdata = rpos -> data;
	plist -> before -> next = plist -> cur -> next; //1. 노드 이어주고
	plist -> cur = plist -> before;			//2. cur 한칸 당겨주기
	free(rpos);	//노드 삭제
	(plist -> numOfData)--;
	return (rdata);
}
#ifndef __D_LINKED_LIST_H__
# define __D_LINKED_LIST_H__

#define TRUE 1
#define FALSE 0

typedef int LData;

typedef struct _node
{
	LData data;
	struct _node *next;
}		Node;

typedef struct _linkedList
{
	Node *head;
	Node *cur;
	Node *before;	//노드의 삭제를 위해 존
	int numOfData;
	int (*comp)(Ldata d1, LData d2);
}		LinkedList;

typedef LinkedList List;

void init(List *plist);
void insert(List *plist, LData *pdata);

int first(List *plist, LData *pdata);
int next(List *plist, LData *pdata);


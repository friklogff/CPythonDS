#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType; // ��������Ԫ������

typedef struct LNode {
	ElemType data;
	struct LNode *next;
} LNode, *LinkList;


//struct LNode {
//	ElemType data;
//	struct LNode *next;
//};
//typedef struct LNode LNode;
//typedef struct LNode *LinkList;

// ��ʼ��һ����ͷ�ڵ�ĵ�����
bool InitListWithHead(LinkList &L) {
	L = (LNode *)malloc(sizeof(LNode));
	if (L == NULL) {
		return false;
	}
	L->next = NULL;
	printf("��ʼ����ͷ�ڵ�ĵ�����ɹ�\n");
	return true;
}

// �жϴ�ͷ�ڵ�ĵ������Ƿ�Ϊ��
bool EmptyWithHead(LinkList L) {
	return (L->next == NULL);
}

// ������ͷ������ڵ�
void InsertAtHeadWithHead(LinkList L, ElemType value) {
	LNode *newNode = (LNode *)malloc(sizeof(LNode));
	newNode->data = value;
	newNode->next = L->next;
	L->next = newNode;
	printf("�ڴ�ͷ�ڵ�ĵ�����ͷ������ڵ㣺%d\n", value);
}

// ������ĩβ����ڵ�
void InsertAtEndWithHead(LinkList L, ElemType value) {
	LNode *newNode = (LNode *)malloc(sizeof(LNode));
	newNode->data = value;
	newNode->next = NULL;

	LNode *temp = L;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newNode;

	printf("�ڴ�ͷ�ڵ�ĵ�����ĩβ����ڵ㣺%d\n", value);
}

// ɾ��ָ����ֵ�Ľڵ�
void DeleteNodeWithHead(LinkList L, ElemType key) {
	LNode *temp = L->next;
	LNode *prev = L;

	while (temp != NULL && temp->data != key) {
		prev = temp;
		temp = temp->next;
	}

	if (temp == NULL) {
		return;
	}

	prev->next = temp->next;
	free(temp);

	printf("ɾ���ڵ㣺%d\n", key);
}

// ��ӡ��ͷ�ڵ�ĵ�����Ԫ��
void PrintListWithHead(LinkList L) {
	LNode *temp = L->next;
	printf("��ͷ�ڵ�ĵ�����Ԫ�أ�");
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

// ���ٴ�ͷ�ڵ�ĵ�����
void DestroyListWithHead(LinkList &L) {
	LNode *current = L->next;
	LNode *next;

	while (current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}

	free(L);
	L = NULL;

	printf("���ٴ�ͷ�ڵ�ĵ�����\n");
}

int main() {
	LinkList L;
	InitListWithHead(L);

	InsertAtEndWithHead(L, 10);
	InsertAtEndWithHead(L, 20);
	InsertAtEndWithHead(L, 30);

	printf("\n");
	PrintListWithHead(L);
	printf("��ӡ��ͷ�ڵ�ĵ�����Ԫ��\n");
	printf("\n");

	InsertAtHeadWithHead(L, 5);
	InsertAtHeadWithHead(L, 15);

	printf("\n");
	PrintListWithHead(L);
	printf("��ӡ��ͷ�ڵ�ĵ�����Ԫ��\n");
	printf("\n");

	DeleteNodeWithHead(L, 20);

	printf("\n");
	PrintListWithHead(L);
	printf("��ӡ��ͷ�ڵ�ĵ�����Ԫ��\n");
	printf("\n");

	DestroyListWithHead(L);

	return 0;
}

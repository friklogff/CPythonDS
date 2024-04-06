#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType; // ��������Ԫ������

typedef struct LNode {
	ElemType data;
	struct LNode *next;
} LNode, *LinkList;

// ��ʼ��һ���յĵ�����
bool InitList(LinkList &L) {
	L = NULL;
	printf("��ʼ������ɹ�\n");
	return true;
}

// �жϵ������Ƿ�Ϊ��
bool Empty(LinkList L) {
	return (L == NULL);
}

// ������ͷ������ڵ�
void InsertAtHead(LinkList &L, ElemType value) {
	LNode *newNode = (LNode *)malloc(sizeof(LNode));
	newNode->data = value;
	newNode->next = L;
	L = newNode;
	printf("������ͷ������ڵ㣺%d\n", value);
}

// ������ĩβ����ڵ�
void InsertAtEnd(LinkList &L, ElemType value) {
	LNode *newNode = (LNode *)malloc(sizeof(LNode));
	newNode->data = value;
	newNode->next = NULL;

	if (L == NULL) {
		L = newNode;
	} else {
		LNode *temp = L;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newNode;
	}

	printf("������ĩβ����ڵ㣺%d\n", value);
}

// ɾ��ָ����ֵ�Ľڵ�
void DeleteNode(LinkList &L, ElemType key) {
	LNode *temp = L;
	LNode *prev = NULL;

	if (temp != NULL && temp->data == key) {
		L = temp->next;
		free(temp);
		printf("ɾ���ڵ㣺%d\n", key);
		return;
	}

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

// ��ӡ����Ԫ��
void PrintList(LinkList L) {
	LNode *temp = L;
	printf("����Ԫ�أ�");
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

// ��������
void DestroyList(LinkList &L) {
	LNode *current = L;
	LNode *next;

	while (current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}

	L = NULL;

	printf("��������\n");
}

int main() {
	LinkList L;
	InitList(L);

	// ������ĩβ����ڵ㣺10
	InsertAtEnd(L, 10);
	// ������ĩβ����ڵ㣺20
	InsertAtEnd(L, 20);
	// ������ĩβ����ڵ㣺30
	InsertAtEnd(L, 30);

	printf("\n");
	// ��ӡ����Ԫ�أ�10 20 30
	PrintList(L);
	printf("\n");

	// ������ͷ������ڵ㣺5
	InsertAtHead(L, 5);
	// ������ͷ������ڵ㣺15
	InsertAtHead(L, 15);

	printf("\n");
	// ��ӡ����Ԫ�أ�15 5 10 20 30
	PrintList(L);
	printf("\n");

	// ɾ���ڵ㣺20
	DeleteNode(L, 20);

	printf("\n");
	// ��ӡ����Ԫ�أ�15 5 10 30
	PrintList(L);
	printf("\n");

	// ��������
	DestroyList(L);

	return 0;
}


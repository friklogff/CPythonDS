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

// ����λ�û�ȡ�������е�ָ���ڵ�
LNode *GetElem(LinkList L, int i) {
	int j = 1;
	LNode *p = L;

	if (i == 0)
		return L;
	if (i < 1)
		return NULL;

	while (p != NULL && j < i) {
		p = p->next;
		j++;
	}

	return p;
}

// �ڲ���ͷ���ĵ������е�i��λ�ò���Ԫ��e
bool ListInsert(LinkList &L, int i, ElemType e) {
	if (i < 1)
		return false;
	if (i == 1) { // �����1�����Ĳ�����������������ͬ
		LNode *s = (LNode *)malloc(sizeof(LNode));
		s->data = e;
		s->next = L;
		L = s; // ͷָ��ָ���½��
		return true;
	}
	int j = 1;
	LNode *p = L;

	// �ҵ���i-1���ڵ�
	while (p != NULL && j < i - 1) {
		p = p->next;
		j++;
	}

	if (p == NULL) // iֵ���Ϸ�
		return false;

	LNode *s = (LNode *)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;

	return true; // ����ɹ�
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
	// ��ȡ��2���ڵ��ָ��
	LNode *node = GetElem(L, 2);
	if (node != NULL) {
		printf("The data in the 2nd node is: %d\n", node->data);
	} else {
		printf("Node not found.\n");
	}

	// �ڵ�3��λ�ò���Ԫ�� 25
	if (ListInsert(L, 3, 25)) {
		printf("Inserted 25 at position 3\n");
	} else {
		printf("Failed to insert at position 3\n");
	}

	PrintList(L);
	// ��������
	DestroyList(L);

	return 0;
}


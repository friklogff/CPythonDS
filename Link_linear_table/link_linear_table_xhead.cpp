#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType; // 定义链表元素类型

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

// 初始化一个带头节点的单链表
bool InitListWithHead(LinkList &L) {
	L = (LNode *)malloc(sizeof(LNode));
	if (L == NULL) {
		return false;
	}
	L->next = NULL;
	printf("初始化带头节点的单链表成功\n");
	return true;
}

// 判断带头节点的单链表是否为空
bool EmptyWithHead(LinkList L) {
	return (L->next == NULL);
}

// 在链表头部插入节点
void InsertAtHeadWithHead(LinkList L, ElemType value) {
	LNode *newNode = (LNode *)malloc(sizeof(LNode));
	newNode->data = value;
	newNode->next = L->next;
	L->next = newNode;
	printf("在带头节点的单链表头部插入节点：%d\n", value);
}

// 在链表末尾插入节点
void InsertAtEndWithHead(LinkList L, ElemType value) {
	LNode *newNode = (LNode *)malloc(sizeof(LNode));
	newNode->data = value;
	newNode->next = NULL;

	LNode *temp = L;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newNode;

	printf("在带头节点的单链表末尾插入节点：%d\n", value);
}

// 删除指定数值的节点
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

	printf("删除节点：%d\n", key);
}

// 打印带头节点的单链表元素
void PrintListWithHead(LinkList L) {
	LNode *temp = L->next;
	printf("带头节点的单链表元素：");
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

// 销毁带头节点的单链表
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

	printf("销毁带头节点的单链表\n");
}

// 根据位置获取单链表中的指定节点
LNode *GetElemWithHead(LinkList L, int i) {
	int j = 1;
	LNode *p = L->next;

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

// 在带头结点的单链表中第i个位置插入元素e
bool ListInsertWithHead(LinkList &L, int i, ElemType e) {
	LNode *p = L;
	int j = 0;

	if (i < 1)
		return false;

	// 找到第i-1个节点
	while (p != NULL && j < i - 1) {
		p = p->next;
		j++;
	}

	if (p == NULL) // i值不合法
		return false;

	LNode *s = (LNode *)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;

	return true; // 插入成功
}

int main() {
	LinkList L;
	InitListWithHead(L);

	InsertAtEndWithHead(L, 10);
	InsertAtEndWithHead(L, 20);
	InsertAtEndWithHead(L, 30);

	printf("\n");
	PrintListWithHead(L);
	printf("打印带头节点的单链表元素\n");
	printf("\n");

	InsertAtHeadWithHead(L, 5);
	InsertAtHeadWithHead(L, 15);

	printf("\n");
	PrintListWithHead(L);
	printf("打印带头节点的单链表元素\n");
	printf("\n");

	DeleteNodeWithHead(L, 20);

	printf("\n");
	PrintListWithHead(L);
	printf("打印带头节点的单链表元素\n");
	printf("\n");
	// 获取第2个节点的指针
	LNode *node = GetElemWithHead(L, 2);
	if (node != NULL) {
		printf("The data in the 2nd node is: %d\n", node->data);
	} else {
		printf("Node not found.\n");
	}

	// 在第3个位置插入元素 25
	if (ListInsertWithHead(L, 1, 25)) {
		printf("Inserted 25 at position 3\n");
	} else {
		printf("Failed to insert at position 3\n");
	}

	PrintListWithHead(L);
	DestroyListWithHead(L);

	return 0;
}

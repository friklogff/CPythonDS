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

// 初始化一个空的单链表
bool InitList(LinkList &L) {
	L = NULL;
	printf("初始化链表成功\n");
	return true;
}

// 判断单链表是否为空
bool Empty(LinkList L) {
	return (L == NULL);
}

// 在链表头部插入节点
void InsertAtHead(LinkList &L, ElemType value) {
	LNode *newNode = (LNode *)malloc(sizeof(LNode));
	newNode->data = value;
	newNode->next = L;
	L = newNode;
	printf("在链表头部插入节点：%d\n", value);
}

// 在链表末尾插入节点
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

	printf("在链表末尾插入节点：%d\n", value);
}

// 删除指定数值的节点
void DeleteNode(LinkList &L, ElemType key) {
	LNode *temp = L;
	LNode *prev = NULL;

	if (temp != NULL && temp->data == key) {
		L = temp->next;
		free(temp);
		printf("删除节点：%d\n", key);
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

	printf("删除节点：%d\n", key);
}

// 打印链表元素
void PrintList(LinkList L) {
	LNode *temp = L;
	printf("链表元素：");
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

// 销毁链表
void DestroyList(LinkList &L) {
	LNode *current = L;
	LNode *next;

	while (current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}

	L = NULL;

	printf("销毁链表\n");
}

// 根据位置获取单链表中的指定节点
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

// 在不带头结点的单链表中第i个位置插入元素e
bool ListInsert(LinkList &L, int i, ElemType e) {
	if (i < 1)
		return false;
	if (i == 1) { // 插入第1个结点的操作与其他结点操作不同
		LNode *s = (LNode *)malloc(sizeof(LNode));
		s->data = e;
		s->next = L;
		L = s; // 头指针指向新结点
		return true;
	}
	int j = 1;
	LNode *p = L;

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
	InitList(L);

	// 在链表末尾插入节点：10
	InsertAtEnd(L, 10);
	// 在链表末尾插入节点：20
	InsertAtEnd(L, 20);
	// 在链表末尾插入节点：30
	InsertAtEnd(L, 30);

	printf("\n");
	// 打印链表元素：10 20 30
	PrintList(L);
	printf("\n");

	// 在链表头部插入节点：5
	InsertAtHead(L, 5);
	// 在链表头部插入节点：15
	InsertAtHead(L, 15);

	printf("\n");
	// 打印链表元素：15 5 10 20 30
	PrintList(L);
	printf("\n");

	// 删除节点：20
	DeleteNode(L, 20);

	printf("\n");
	// 打印链表元素：15 5 10 30
	PrintList(L);
	printf("\n");
	// 获取第2个节点的指针
	LNode *node = GetElem(L, 2);
	if (node != NULL) {
		printf("The data in the 2nd node is: %d\n", node->data);
	} else {
		printf("Node not found.\n");
	}

	// 在第3个位置插入元素 25
	if (ListInsert(L, 3, 25)) {
		printf("Inserted 25 at position 3\n");
	} else {
		printf("Failed to insert at position 3\n");
	}

	PrintList(L);
	// 销毁链表
	DestroyList(L);

	return 0;
}


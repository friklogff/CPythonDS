//12，有两个循环单链表，链表头指针分别为h1和 h2，
//编写一个函数将链表h2链接到链表h1之后，
//要求链接后的链表仍保持循环链表形式。
#include <stdio.h>
#include <stdlib.h>

// 定义链表元素类型
typedef int ElemType;

// 链表节点结构体定义（单向循环链表）
typedef struct LNode {
	ElemType data;        // 数据域
	struct LNode *next;   // 指针域，指向下一个节点
} LNode, *LinkList;

// 初始化数组和数组长度
int arr1[] = {1, 2, 3, 4};
int len1 = sizeof(arr1) / sizeof(arr1[0]);

int arr2[] = {5, 6, 7, 8, 9};
int len2 = sizeof(arr2) / sizeof(arr2[0]);

/**
 * 构建单向循环链表
 * @param head 链表头节点的指针
 * @param arr 数组
 * @param len 数组长度
 */
void buildList(LinkList *head, int arr[], int len) {
	*head = (LinkList)malloc(sizeof(LNode));    // 分配头节点空间
	LNode *cur = *head, *newNode;

	// 构建链表节点并连接
	for (int i = 0; i < len; i++) {
		newNode = (LNode *)malloc(sizeof(LNode));
		newNode->data = arr[i];
		cur->next = newNode;
		cur = newNode;
	}
	cur->next = *head;   // 最后一个节点的 next 设为头节点，形成循环
}

/**
 * 显示单向循环链表
 * @param head 链表头节点
 */
void displayList(const LinkList head) {
	const LNode *cur = head->next;
	while (cur != head) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

/**
 * 将两个单向循环链表连接成一个循环链表
 * @param L1 链表1的头节点的指针
 * @param L2 链表2的头节点的指针
 */
void mergeLists(LinkList *L1, LinkList *L2) {
	LNode *p = (*L1)->next; // 指向链表1的第一个节点
	LNode *q = (*L2)->next; // 指向链表2的第一个节点

	// 找到链表1的最后一个节点
	while (p->next != *L1) {
		p = p->next;
	}

	// 找到链表2的最后一个节点
	while (q->next != *L2) {
		q = q->next;
	}

	// 将链表1的最后一个节点指向链表2的第一个节点
	p->next = (*L2)->next;

	// 将链表2的最后一个节点指向链表1的头节点
	q->next = *L1;
}

int main() {
	LinkList L1, L2;

	// 构建链表L1和L2
	buildList(&L1, arr1, len1);
	buildList(&L2, arr2, len2);

	// 显示链表L1
	printf("链表L1:\n");
	displayList(L1);

	// 显示链表L2
	printf("链表L2:\n");
	displayList(L2);

	// 将两个单向循环链表连接成一个循环链表
	mergeLists(&L1, &L2);

	// 显示合并后的链表L1
	printf("合并后的链表L1:\n");
	displayList(L1);

	// 释放链表的内存
	LNode *p = L1->next;
	while (p != L1) {
		LNode *temp = p;
		p = p->next;
		free(temp);
	}
	free(L1);

	return 0;
}

//08.设A和B是两个单链表（带头结点)，其中元素递增有序。设计一个算法从A和B中的
//公共元素产生单链表C，要求不破坏A、B的结点。

#include <stdio.h>
#include <stdlib.h>

// 定义链表元素类型
typedef int ElemType;

// 链表节点结构体定义
typedef struct LNode {
	ElemType data;        // 数据域
	struct LNode *next;   // 指针域，指向下一个节点
} LNode, *LinkList;

// 初始化数组和数组长度
int arr1[] = {2, 3, 4, 9};
int len1 = sizeof(arr1) / sizeof(arr1[0]);

int arr2[] = {4, 7, 9, 10, 11};
int len2 = sizeof(arr2) / sizeof(arr2[0]);

/**
 * 构建链表
 * @param head 链表头节点的引用
 * @param arr 数组
 * @param len 数组长度
 */
void buildList(LinkList &head, int arr[], int len) {
	head = (LinkList)malloc(sizeof(LNode));    // 分配头节点空间
	LNode *cur = head, *newNode;

	// 构建链表节点并连接
	for (int i = 0; i < len; i++) {
		newNode = (LNode *)malloc(sizeof(LNode));
		newNode->data = arr[i];
		cur->next = newNode;
		cur = newNode;
	}
	cur->next = NULL;   // 最后一个节点的next设为NULL
}

/**
 * 显示链表
 * @param head 链表头节点
 */
void displayList(const LinkList head) {
	const LNode *cur = head->next; // 从头节点的下一个节点开始
	while (cur) {
		printf("%d ", cur->data);  // 打印当前节点数据
		cur = cur->next;           // 移动到下一个节点
	}
	printf("\n");
}

/**
 * 构建一个新的链表，包含L1和L2中的公共元素
 * @param L1 链表1的头节点
 * @param L2 链表2的头节点
 * @return 新的链表L3的头节点
 */
LinkList buildCommonList(LinkList L1, LinkList L2) {
	LinkList L3 = (LinkList)malloc(sizeof(LNode));
	LNode *p1 = L1->next, *p2 = L2->next, *cur = L3;

	// 遍历L1和L2，找到它们的公共部分，并加入L3
	while (p1 && p2) {
		if (p1->data < p2->data) {
			p1 = p1->next;
		} else if (p1->data > p2->data) {
			p2 = p2->next;
		} else {
			LNode *newNode = (LNode *)malloc(sizeof(LNode));
			newNode->data = p1->data;
			cur->next = newNode;
			cur = newNode;
			p1 = p1->next;
			p2 = p2->next;
		}
	}
	cur->next = NULL; // 最后一个节点的next设为NULL
	return L3;
}

int main() {
	LinkList L1, L2;

	// 构建链表L1和L2
	buildList(L1, arr1, len1);
	buildList(L2, arr2, len2);

	// 显示链表L1
	printf("链表L1:\n");
	displayList(L1);

	// 显示链表L2
	printf("链表L2:\n");
	displayList(L2);

	// 构建新的链表L3，包含L1和L2中的公共元素
	LinkList L3 = buildCommonList(L1, L2);
	printf("链表L3 (L1和L2中的公共元素):\n");
	displayList(L3);

	return 0;
}

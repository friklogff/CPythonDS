//09.．已知两个链表A和B分别表示两个集合，其元素递增排列。编制函数，
//求A与B的交集，并存放于A链表中。
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
int arr1[] = {1, 2, 3, 4};
int len1 = sizeof(arr1) / sizeof(arr1[0]);

int arr2[] = {2, 4, 5, 6, 7, 8};
int len2 = sizeof(arr2) / sizeof(arr2[0]);

/**
 * 构建链表
 * @param L 链表头节点的指针
 * @param arr 数组
 * @param len 数组长度
 */
void buildList(LinkList &L, int arr[], int len) {
	L = (LinkList)malloc(sizeof(LNode));    // 分配头节点空间
	LNode *cur = L, *newNode;

	// 构建链表节点并连接
	for (int i = 0; i < len; i++) {
		newNode = (LNode *)malloc(sizeof(LNode));
		newNode->data = arr[i];
		cur->next = newNode;
		cur = newNode;
	}
	cur->next = NULL;    // 最后一个节点的next设为NULL
}

/**
 * 显示链表
 * @param L 链表头节点
 */
void displayList(const LinkList L) {
	const LNode *cur = L->next; // 从头节点的下一个节点开始
	while (cur) {
		printf("%d ", cur->data);  // 打印当前节点数据
		cur = cur->next;           // 移动到下一个节点
	}
	printf("\n");
}

/**
 * 将链表B与链表A的交集存放于链表A中
 * @param A 链表A的头节点的引用
 * @param B 链表B的头节点
 */
void Union(LinkList &A, LinkList B) {
	LNode *curA = A->next, *curB = B->next, *prevA = A;
	LNode *temp;

	while (curA && curB) {
		if (curA->data < curB->data) {
			// 删除链表A中当前节点
			temp = curA;
			curA = curA->next;
			prevA->next = curA;
			free(temp);
		} else if (curA->data > curB->data) {
			curB = curB->next;
		} else {
			// 当前节点在A和B中都有，无需删除，移动到下一个节点
			prevA = curA;
			curA = curA->next;
			curB = curB->next;
		}
	}

	// 删除链表A中剩余的节点
	while (curA) {
		temp = curA;
		curA = curA->next;
		prevA->next = curA;
		free(temp);
	}
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

	// 求A与B的交集，并存放于A链表中
	Union(L1, L2);

	// 显示求交集后的链表L1
	printf("求交集后的链表L1:\n");
	displayList(L1);

	// 释放链表的内存
	LNode *p;
	while (L2 != NULL) {
		p = L2;
		L2 = L2->next;
		free(p);
	}

	return 0;
}

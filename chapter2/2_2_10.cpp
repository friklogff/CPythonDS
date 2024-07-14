//10.两个整数序列A=a, az, as,…", am和B=b;, b,b3,.…, b。
//已经存入两个单链表中，设计一个算法，判断序列B是否是序列A的连续子序列。

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType; // 定义链表元素类型

typedef struct LNode {
	ElemType data;
	struct LNode *next;
} LNode, *LinkList;

// 初始化数组和数组长度
int a[] = {1, 2, 3, 4, 5, 6};
int n1 = sizeof(a) / sizeof(a[0]);
int b[] = {3, 4, 7};
int n2 = sizeof(b) / sizeof(b[0]);

/**
 * 构建链表
 * @param L 链表头节点的指针
 * @param arr 数组
 * @param n 数组长度
 */
void buildList(LinkList *L, int arr[], int n) {
	*L = (LinkList)malloc(sizeof(LNode));
	LNode *cur = *L, *newNode;
	for (int i = 0; i < n; i++) {
		newNode = (LNode *)malloc(sizeof(LNode));
		newNode->data = arr[i];
		cur->next = newNode;
		cur = newNode;
	}
	cur->next = NULL;
}

/**
 * 检查链表L2是否是链表L1的子序列
 * @param L1 链表1头节点
 * @param L2 链表2头节点
 * @return 如果L2是L1的子序列，返回true，否则返回false
 */
bool isSubsequence(LinkList L1, LinkList L2) {
	LNode *p1 = L1->next;
	LNode *p2 = L2->next;

	while (p1) {
		// 如果L2已经遍历完，说明L2是L1的子序列
		if (!p2)
			return true;

		// 检查当前节点值是否相等
		if (p1->data == p2->data) {
			p2 = p2->next; // 匹配，移动L2的指针
		} else {
			p2 = L2->next; // 不匹配，重置L2的指针从头开始
		}
		p1 = p1->next;
	}

	// 检查是否所有L2的节点都匹配
	return p2 == NULL;
}

int main() {
	LinkList L1, L2;
	buildList(&L1, a, n1);
	buildList(&L2, b, n2);

	if (isSubsequence(L1, L2)) {
		printf("yes\n");
	} else {
		printf("no\n");
	}

	// 释放链表的内存
	LNode *p;
	while (L1 != NULL) {
		p = L1;
		L1 = L1->next;
		free(p);
	}
	while (L2 != NULL) {
		p = L2;
		L2 = L2->next;
		free(p);
	}

	return 0;
}

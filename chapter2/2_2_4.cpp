//04．设在一个带表头结点的单链表中，所有结点的元素值无序，
//试编写一个函数，删除表中所有介于给定的两个值（作为函数参数给出）
//之间的元素（若存在).
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType; // 定义链表元素类型

// 链表节点结构体定义
typedef struct LNode {
	ElemType data;         // 数据域
	struct LNode *next;    // 指针域，指向下一个节点
} LNode, *LinkList;

// 初始化数组和数组长度
int arr[] = {1, 5, 3, 4, 2};
int len = sizeof(arr) / sizeof(arr[0]);

/**
 * 构建链表
 * @param head 链表头节点的引用
 */
void buildList(LinkList &head) {
	head = (LinkList)malloc(sizeof(LNode));  // 分配头节点空间
	LNode *cur = head, *newNode;

	// 构建链表节点并连接
	for (int i = 0; i < len; i++) {
		newNode = (LNode *)malloc(sizeof(LNode));
		newNode->data = arr[i];
		cur->next = newNode;
		cur = newNode;
	}
	cur->next = NULL; // 最后一个节点的 next 设为 NULL
}

/**
 * 显示链表
 * @param head 链表头节点
 */
void displayList(const LinkList head) {
	const LNode *cur = head->next;
	while (cur) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

/**
 * 删除链表中值在 (min, max) 之间的节点
 * @param head 链表头节点的引用
 * @param min 下界
 * @param max 上界
 */
void deleteNodesInRange(LinkList &head, int min, int max) {
	LNode *cur = head->next, *prev = head;
	while (cur) {
		if (cur->data > min && cur->data < max) {
			prev->next = cur->next; // 从链表中移除节点
			free(cur); // 释放节点内存
			cur = prev->next; // 移动到下一个节点
		} else {
			prev = cur;
			cur = cur->next;
		}
	}
}

int main() {
	LinkList head;

	buildList(head); // 构建链表
	printf("Original list:\n");
	displayList(head); // 显示原始链表

	deleteNodesInRange(head, 1, 4); // 删除值在 (1, 4) 之间的节点
	printf("List after deleting nodes with values in range (1, 4):\n");
	displayList(head); // 显示删除后的链表

	return 0; // 程序结束
}

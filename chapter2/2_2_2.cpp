/*
试编写在带头结点的单链表工中删除一个最小值结点的高效算法
（假设该结点唯一)。
*/
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType; // 定义链表元素类型

// 链表节点结构体定义
typedef struct LNode {
	ElemType data;          // 数据域
	struct LNode *next;     // 指针域，指向下一个节点
} LNode, *LinkList;

/**
 * 删除链表中值最小的节点
 * @param head 链表头节点的引用
 */
void deleteMinNode(LinkList &head) {
	LNode *prev = head, *cur = head->next;
	LNode *minPrev = prev, *minCur = cur;

	// 遍历链表寻找最小值节点
	while (cur != NULL) {
		if (cur->data < minCur->data) {
			minCur = cur;   // 更新最小值节点
			minPrev = prev; // 更新最小值节点的前驱节点
		}
		prev = cur;
		cur = cur->next;
	}

	// 删除最小值节点
	if (minCur != NULL) {
		minPrev->next = minCur->next; // 将最小值节点从链表中断开
		free(minCur);                 // 释放最小值节点的内存
	}
}

int main() {
	LinkList head = (LinkList)malloc(sizeof(LNode)); // 动态分配头节点
	head->next = NULL;

	// 添加元素到链表
	int arr[5] = {5, 3, 8, 1, 6};
	LNode *current = head;
	for (int i = 0; i < 5; i++) {
		LNode *newNode = (LNode *)malloc(sizeof(LNode)); // 动态分配新节点
		newNode->data = arr[i];                          // 设置新节点的数据
		newNode->next = NULL;                            // 初始化新节点的 next 为 NULL
		current->next = newNode;                         // 插入新节点
		current = newNode;                               // 移动到新节点
	}

	// 打印原始链表
	printf("Original linked list:\n");
	current = head->next;
	while (current != NULL) {
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");

	// 删除链表中值最小的节点
	deleteMinNode(head);

	// 打印删除最小值节点后的链表
	printf("After deleting the minimum element:\n");
	current = head->next;
	while (current != NULL) {
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");

	return 0;
}

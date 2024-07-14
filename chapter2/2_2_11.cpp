//11．设计一个算法用于判断带头结点的循环双链表是否对称。
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 定义链表元素类型
typedef int ElemType;

// 链表节点结构体定义 (双向循环链表)
typedef struct LNode {
	ElemType data;        // 数据域
	struct LNode *next;   // 指针域，指向下一个节点
	struct LNode *prior;  // 指针域，指向前一个节点
} LNode, *LinkList;

// 初始化数组和数组长度
int arr[] = {1, 2, 3, 4, 2, 1};
int len = sizeof(arr) / sizeof(arr[0]);

/**
 * 构建双向循环链表
 * @param head 链表头节点的指针
 */
void buildList(LinkList *head) {
	*head = (LinkList)malloc(sizeof(LNode));
	(*head)->prior = *head;
	(*head)->next = *head;

	LNode *cur = *head, *newNode;

	// 构建链表节点并连接
	for (int i = 0; i < len; i++) {
		newNode = (LNode *)malloc(sizeof(LNode));
		newNode->data = arr[i];

		newNode->next = cur->next;
		cur->next->prior = newNode;

		newNode->prior = cur;
		cur->next = newNode;

		cur = newNode;
		(*head)->prior = cur;
	}
}

/**
 * 显示双向循环链表
 * @param head 链表头节点
 */
void displayList(const LinkList head) {
	LNode *cur = head->next;

	while (cur != head) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

/**
 * 检查双向循环链表是否是回文链表
 * @param head 链表头节点
 * @return 如果是回文链表返回true，否则返回false
 */
bool isPalindrome(LinkList head) {
	LNode *p = head->next;
	LNode *q = head->prior;

	while (p != q && q->next != p) {
		if (p->data == q->data) {
			p = p->next;
			q = q->prior;
		} else {
			return false;
		}
	}
	return true;
}

int main() {
	LinkList head;

	buildList(&head);       // 构建链表
	displayList(head);      // 显示链表

	if (isPalindrome(head)) {    // 检查是否是回文链表
		printf("是回文链表\n");
	} else {
		printf("不是回文链表\n");
	}

	// 释放链表的内存
	LNode *cur = head->next;
	while (cur != head) {
		LNode *temp = cur;
		cur = cur->next;
		free(temp);
	}
	free(head);

	return 0;
}

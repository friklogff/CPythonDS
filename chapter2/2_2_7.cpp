//07、在一个递增有序的单链表中，存在重复的元素。设计算法删除重复的元素，例如(7,10,
//10,21,30,42,42,42,51,70）将变为( 7,10,21,30,42,51,70 ).

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 定义链表元素类型
typedef int ElemType;

// 链表节点结构体定义
typedef struct LNode {
	ElemType data;       // 数据域
	struct LNode *next;  // 指针域，指向下一个节点
} LNode, *LinkList;

// 初始化数组和数组长度
int arr[] = {10, 21, 30, 42, 42, 42, 51, 70};
int len = sizeof(arr) / sizeof(arr[0]);

/**
 * 构建链表
 * @param head 链表头节点的指针
 */
void buildList(LinkList *head) {
	*head = (LinkList)malloc(sizeof(LNode));    // 分配头节点空间
	LNode *cur = *head, *newNode;

	// 构建链表节点并连接
	for (int i = 0; i < len; i++) {
		newNode = (LNode *)malloc(sizeof(LNode));
		newNode->data = arr[i];
		cur->next = newNode;
		cur = newNode;
	}
	cur->next = NULL;   // 最后一个节点的 next 设为 NULL
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
 * 删除链表中的重复节点
 * @param head 链表头节点的指针
 */
void deleteDuplicates(LinkList *head) {
	if ((*head)->next == NULL)
		return; // 如果链表为空或只有一个节点，直接返回

	LNode *cur = (*head)->next;
	LNode *nextNode;

	// 遍历链表查找重复节点并删除
	while (cur->next != NULL) {
		if (cur->data == cur->next->data) {
			nextNode = cur->next;       // 保存下一个节点
			cur->next = nextNode->next; // 当前节点的 next 跳过下一个节点
			free(nextNode);             // 释放被删除的节点
		} else {
			cur = cur->next;            // 移动到下一个节点
		}
	}
}

int main() {
	LinkList head;

	buildList(&head); // 构建链表
	printf("删除前:\n");
	displayList(head); // 显示原始链表

	deleteDuplicates(&head); // 删除链表中的重复节点
	printf("删除后:\n");
	displayList(head); // 显示删除重复节点后的链表

	return 0; // 程序结束
}

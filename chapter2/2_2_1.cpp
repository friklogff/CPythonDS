/*在带头结点的单链表工中，删除所有值为x的结点，并释放其空间，
假设值为×的结点不唯一，试编写算法以实现上述操作。
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 链表节点结构体定义
typedef struct LNode {
	int data;           // 数据域
	struct LNode *next; // 指针域，指向下一个节点
} LNode, *LinkList;

// 初始化数组和数组长度
int arr[] = {1, 3, 3, 4};
int len = sizeof(arr) / sizeof(arr[0]);

/**
 * 构建链表
 * @param L 链表头节点
 */
void buildList(LinkList L) {
	LNode *newNode, *cur = L;
	cur->data = arr[0]; // 设置头节点数据
	cur->next = NULL;   // 初始化头节点的 next 为 NULL

	// 遍历数组构建链表
	for (int i = 1; i < len; i++) {
		newNode = (LNode *)malloc(sizeof(LNode)); // 动态分配新节点
		newNode->data = arr[i];                   // 设置新节点数据
		newNode->next = NULL;                     // 初始化新节点的 next 为 NULL
		cur->next = newNode;                      // 当前节点 next 指向新节点
		cur = newNode;                            // 移动到新节点
	}
}

/**
 * 显示链表
 * @param L 链表头节点
 */
void displayList(const LinkList L) {
	const LNode *cur = L;
	while (cur) {
		printf("%d ", cur->data); // 打印当前节点数据
		cur = cur->next;          // 移动到下一个节点
	}
	printf("\n");
}

/**
 * 删除链表中值为 x 的节点方法一
 * @param L 链表头节点的引用
 * @param x 要删除的值
 */
void del_x_1(LinkList &L, int x) {
	LNode *p = L->next, *pre = L, *q;
	while (p != NULL) {
		if (p->data == x) {
			q = p;            // q 指向被删节点
			p = p->next;      // p 指向下一个节点
			pre->next = p;    // 将 q 节点从链表中断开
			free(q);          // 释放 q 节点的空间
		} else {
			pre = p;          // 否则, pre 和 p 同步后移
			p = p->next;      // p 指向下一个节点
		}
	}
}

/**
 * 删除链表中值为 x 的节点方法二
 * @param L 链表头节点
 * @param x 要删除的值
 */
void del_x_2(LinkList L, int x) {
	LNode *p = L->next, *r = L, *q; // r 指向尾结点，其初值为头结点
	while (p != NULL) {
		if (p->data != x) { // 若 p 节点值不为 x 时将其链接到 r 尾部
			r->next = p;
			r = p;
			p = p->next;    // 继续扫描
		} else {
			q = p;          // p 节点值为 x 时将其释放
			p = p->next;    // 继续扫描
			free(q);        // 释放空间
		}
	}
	r->next = NULL;         // 插入结束后置尾结点指针为 NULL
}

int main() {
	LinkList L = (LinkList)malloc(sizeof(LNode)); // 动态分配头节点
	buildList(L); // 构建链表

	printf("Original list:\n");
	displayList(L); // 显示链表

	// 使用方法一删除值为 3 的节点
	del_x_1(L, 3);
	printf("List after deleting value 3 using method 1:\n");
	displayList(L); // 显示链表

	// 重新构建链表以测试方法二
	buildList(L);

	// 使用方法二删除值为 3 的节点
	del_x_2(L, 3);
	printf("List after deleting value 3 using method 2:\n");
	displayList(L); // 显示链表

	return 0; // 程序结束
}

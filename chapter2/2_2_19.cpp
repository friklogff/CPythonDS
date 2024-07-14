//19.【2015统考真题】用单链表保存m个整数，结点的结构为[data] [link]，且|data|≤
//n (n为正整数)。现要求设计一个时间复杂度尽可能高效的算法，对于链表中 data的
//绝对值相等的结点，仅保留第一次出现的结点而删除其余绝对值相等的结点。例如，若给定的单链表head如下:
//head
//工一→可-一国国→国·
//则删除结点后的head为
//head
//`2引-ts→-7
//要求:
//1)给出算法的基本设计思想。
//2）使用C或C++语言，给出单链表结点的数据类型定义。
//3)根据设计思想，采用C或C++语言描述算法，关键之处给出注释。4 )说明你所设计算法的时间复杂度和空间复杂度。

#include <stdio.h>
#include <stdlib.h>

// 定义链表元素类型
typedef int ElemType;

// 链表节点结构体定义
typedef struct LNode {
	ElemType data;       // 数据域
	struct LNode *next;  // 指针域，指向下一个节点
} LNode, *LinkList;

// 初始化数组和长度
int arr[] = {1, -4, 2, 3, 4, -2};
int length = sizeof(arr) / sizeof(arr[0]);

/**
 * 构建单向链表
 * @param head 链表头节点的指针
 */
void buildList(LinkList *head) {
	*head = (LinkList)malloc(sizeof(LNode));  // 分配头节点空间
	LNode *cur = *head, *newNode;

	// 构建链表节点并连接
	for (int i = 0; i < length; i++) {
		newNode = (LNode *)malloc(sizeof(LNode));
		newNode->data = arr[i];
		cur->next = newNode;
		cur = newNode;
	}
	cur->next = NULL;  // 最后一个节点的 next 设为 NULL
}

/**
 * 显示单向链表
 * @param head 链表头节点
 */
void displayList(const LinkList head) {
	const LNode *cur = head->next;  // 从头节点的下一个节点开始
	while (cur) {
		printf("%d ", cur->data);  // 打印当前节点数据
		cur = cur->next;  // 移动到下一个节点
	}
	printf("\n");
}

/**
 * 删除链表中绝对值相同的节点，仅保留第一个出现的节点
 * @param head 链表头节点的指针
 * @param n 数组中元素的绝对值最大长度
 */
void removeDuplicates(LinkList *head, int n) {
	LNode *p = *head;  // 指向链表的当前节点
	int *seen;         // 用于记录已经存在的绝对值
	seen = (int *)malloc(sizeof(int) * (n + 1));
	for (int i = 0; i <= n; i++)
		seen[i] = 0;

	int absValue;  // 用于存储节点的绝对值
	LNode *temp;   // 用于暂存将要删除的节点

	while (p->next != NULL) {
		absValue = abs(p->next->data);  // 计算当前节点数据的绝对值

		if (seen[absValue] == 0) {
			// 如果当前绝对值未出现过，标记为已经出现
			seen[absValue] = 1;
			p = p->next;  // 移动到下一个节点
		} else {
			// 如果当前绝对值已经出现过，删除当前节点
			temp = p->next;
			p->next = temp->next;
			free(temp);
		}
	}
	free(seen);  // 释放动态分配的内存
}

int main() {
	LinkList head;
	buildList(&head);
	printf("链表内容: \n");
	displayList(head);
	removeDuplicates(&head, 4);
	printf("处理后链表内容: \n");
	displayList(head);

	// 释放链表的内存
	LNode *cur = head;
	while (cur != NULL) {
		LNode *temp = cur;
		cur = cur->next;
		free(temp);
	}

	return 0;
}

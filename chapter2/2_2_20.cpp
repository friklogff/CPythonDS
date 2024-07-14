//20.【2019统考真题】设线性表L=(a,as,a,…",a-2,aa- ,a,)采用带头结点的单链表保存，链
//表中的结点定义如下:
//typedef struct node{ int data;
//struct node*next;}NODE;
//请设计一个空间复杂度为O(1)且时间上尽可能高效的算法，重新排列L中的各结点，得到线性表L'=(a,,am,az,a.j,a, ,a-2…)、要求:
//1)给出算法的基本设计思想.
//2）根据设计思想，采用C或C++语言描述算法，关键之处给出注释。3）说明你所设计的算法的时间复杂度。

#include <stdio.h>
#include <stdlib.h>

// 定义链表元素类型
typedef int ElemType;

// 链表节点结构体定义
typedef struct LNode {
	ElemType data;       // 数据域
	struct LNode *next;  // 指针域，指向下一个节点
} LNode, *LinkList;

// 初始化数组和数组长度
int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
int len = sizeof(arr) / sizeof(arr[0]);

/**
 * 构建单向链表
 * @param head 链表头节点的指针
 */
void buildList(LinkList *head) {
	*head = (LinkList)malloc(sizeof(LNode));     // 分配头节点空间
	LNode *cur = *head, *newNode;

	// 构建链表节点并连接
	for (int i = 0; i < len; i++) {
		newNode = (LNode *)malloc(sizeof(LNode));
		newNode->data = arr[i];
		cur->next = newNode;
		cur = newNode;
	}
	cur->next = NULL;    // 最后一个节点的 next 设为 NULL
}

/**
 * 显示单向链表
 * @param head 链表头节点
 */
void displayList(const LinkList head) {
	const LNode *cur = head->next;    // 从头节点的下一个节点开始
	while (cur) {
		printf("%d ", cur->data);     // 打印当前节点数据
		cur = cur->next;              // 移动到下一个节点
	}
	printf("\n");
}

/**
 * 反转链表的后半部分并将结果合并到原链表
 * @param head 链表头节点的指针
 */
void mergeReversedHalf(LinkList *head) {
	LNode *slow = *head, *fast = *head;

	// 使用快慢指针找到链表的中间节点
	while (fast->next != NULL && fast->next->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}

	// 分割链表成前后两部分
	LNode *secondHalf = slow->next;
	slow->next = NULL;

	// 反转链表的第二部分
	LNode *prev = NULL, *curr = secondHalf, *next;
	while (curr != NULL) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	secondHalf = prev;

	// 合并两个链表
	LNode *firstHalf = (*head)->next;
	while (secondHalf != NULL) {
		LNode *tmp1 = firstHalf->next;
		LNode *tmp2 = secondHalf->next;

		firstHalf->next = secondHalf;
		secondHalf->next = tmp1;

		firstHalf = tmp1;
		secondHalf = tmp2;
	}
}

int main() {
	LinkList head;

	buildList(&head);     // 构建链表
	printf("原始链表：\n");
	displayList(head);    // 显示链表

	mergeReversedHalf(&head);  // 反转链表的后半部分并合并
	printf("处理后的链表：\n");
	displayList(head);    // 显示处理后的链表

	// 释放链表的内存
	LNode *p;
	while (head != NULL) {
		p = head;
		head = head->next;
		free(p);
	}

	return 0;
}

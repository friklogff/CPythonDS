/*
试编写算法将带头结点的单链表就地逆置，
所谓"就地"是指辅助空间复杂度为O(1)。
*/
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
int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
int len = sizeof(arr) / sizeof(arr[0]);

/**
 * 构建链表
 * @param head 链表头节点的引用
 */
void buildList(LinkList &head) {
	head = (LinkList)malloc(sizeof(LNode));
	LNode *cur = head, *newNode;

	// 构建链表节点并连接
	for (int i = 0; i < len; i++) {
		newNode = (LNode *)malloc(sizeof(LNode));
		newNode->data = arr[i];
		cur->next = newNode;
		cur = newNode;
	}
	cur->next = NULL;
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
 * 反转链表 (解法1)
 * @param head 链表头节点
 * @return 反转后的链表头节点
 */
LinkList reverseList1(LinkList head) {
	LNode *p, *r;
	p = head->next; // 从第一个元素节点开始
	head->next = NULL; // 先将头节点的 next 置为 NULL

	while (p != NULL) {
		r = p->next;       // 暂存 p 的后继
		p->next = head->next; // 将 p 节点插入到头节点之后
		head->next = p;
		p = r;
	}
	return head;
}

/**
 * 反转链表 (解法2)
 * @param head 链表头节点
 * @return 反转后的链表头节点
 */
LinkList reverseList2(LinkList head) {
	LNode *pre = NULL, *p = head->next, *r;
	if (p != NULL) {
		r = p->next;
		p->next = NULL;  // 处理第一个节点
	}

	while (r != NULL) {
		pre = p;         // pre 移到 p
		p = r;           // p 移到 r
		r = r->next;     // r 移到下一个节点
		p->next = pre;   // 反转 p 的指向
	}
	head->next = p;     // 处理最后一个节点
	return head;
}

int main() {
	LinkList head;

	buildList(head); // 构建链表

	printf("Original list:\n");
	displayList(head); // 显示原始链表

	// 使用解法1反转链表
	head = reverseList1(head);
	printf("Reversed list using method 1:\n");
	displayList(head); // 显示反转后的链表

	// 重新构建链表以测试解法2
	buildList(head);

	// 使用解法2反转链表
	head = reverseList2(head);
	printf("Reversed list using method 2:\n");
	displayList(head); // 显示反转后的链表

	return 0;
}






//
//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//
//typedef int ElemType; // 定义链表元素类型
//
//// 链表节点结构体定义
//typedef struct LNode {
//    ElemType data;        // 数据域
//    struct LNode *next;   // 指针域，指向下一个节点
//} LNode, *LinkList;
//
//// 初始化数组和数组长度
//int arr[] = {1, 2, 3, 4};
//int len = sizeof(arr) / sizeof(arr[0]);
//
///**
// * 构建链表
// * @param head 链表头节点的引用
// */
//void buildList(LinkList &head) {
//    head = (LinkList)malloc(sizeof(LNode));  // 分配头节点空间
//    LNode *cur = head, *newNode;
//
//    // 构建链表节点并连接
//    for (int i = 0; i < len; i++) {
//        newNode = (LNode *)malloc(sizeof(LNode));
//        newNode->data = arr[i];
//        cur->next = newNode;
//        cur = newNode;
//    }
//    cur->next = NULL; // 最后一个节点的 next 设为 NULL
//}
//
///**
// * 显示链表
// * @param head 链表头节点
// */
//void displayList(const LinkList head) {
//    const LNode *cur = head->next;
//    while (cur) {
//        printf("%d ", cur->data);
//        cur = cur->next;
//    }
//    printf("\n");
//}
//
///**
// * 反转链表
// * @param head 链表头节点的引用
// */
//void reverseList(LinkList &head) {
//    LNode *cur = head->next, *nextNode;
//    head->next = NULL; // 先将头节点的 next 置为 NULL
//
//    // 反转链表的节点指向
//    while (cur) {
//        nextNode = cur->next; // 保存下一个节点
//        cur->next = head->next; // 当前节点指向头节点的 next
//        head->next = cur; // 将当前节点移动到头节点之后
//        cur = nextNode; // 移动到下一个节点
//    }
//}
//
//int main() {
//    LinkList head;
//
//    buildList(head);  // 构建链表
//    printf("Original list:\n");
//    displayList(head); // 显示原始链表
//
//    printf("Reversed list:\n");
//    reverseList(head); // 反转链表
//    displayList(head); // 显示反转后的链表
//
//    return 0; // 程序结束
//}
//

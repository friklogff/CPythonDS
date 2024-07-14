//06.设C= {a, by, az, b,…, an b}为线性表，采用带头结点的单链表存放，


//设计一个就地算法，将其拆分为两个线性表，使得A= {a, az,"…" , a}，B= {bw.…, b2, b}。
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
int arr[] = {2, 7, 4, 1, 9};
int len = sizeof(arr) / sizeof(arr[0]);

/**
 * 构建链表
 * @param head 链表头节点的指针
 */
void buildList(LinkList &head) {
	head = (LinkList)malloc(sizeof(LNode));    // 分配头节点空间
	LNode *cur = head, *newNode;

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
void displayList(LinkList head) {
	LNode *cur = head->next; // 从头节点的下一个节点开始
	while (cur) {
		printf("%d ", cur->data);  // 打印当前节点数据
		cur = cur->next;           // 移动到下一个节点
	}
	printf("\n");
}

/**
 * 将链表 L1 分成两个链表：一个包含原链表中奇数位置的节点，另一个包含偶数位置的节点
 * @param L1 链表1头节点的引用
 * @return 新链表 L2 的头节点
 */
LinkList splitList(LinkList &L1) {
	// 创建新的链表 L2
	LinkList L2 = (LinkList)malloc(sizeof(LNode));
	L2->next = NULL;

	LNode *cur1 = L1;            // L1 的当前节点
	LNode *cur2 = L2;             // L2 的当前节点
	LNode *origNext = L1->next; // 用于遍历的指针
	int index = 0;                // 记录节点的位置

	// 断开L1的头节点
	L1->next = NULL;

	// 遍历原链表，并将节点分配到L1和L2
	while (origNext != NULL) {
		index++;
		if (index % 2 == 0) {
			cur2->next = origNext;
			cur2 = origNext;
		} else {
			cur1->next = origNext;
			cur1 = origNext;
		}
		origNext = origNext->next;
	}

	// 断开L1和L2的末尾节点
	cur1->next = NULL;
	cur2->next = NULL;

	return L2; // 返回新的链表L2
}

int main() {
	LinkList L1;

	buildList(L1);  // 构建链表
	printf("原始链表：\n");
	displayList(L1); // 显示原始链表

	// 分割链表
	LinkList L2 = splitList(L1);
	printf("L1 (奇数位置的节点)：\n");
	displayList(L1); // 显示链表L1

	printf("L2 (偶数位置的节点)：\n");
	displayList(L2); // 显示链表L2

	return 0;
}


//17.【2009统考真题】已知一个带有表头结点的单链表，结点结构为
//data
//link
//假设该链表只给出了头指针list。在不改变链表的前提下，请设计一个尽可能高效的算法，查找链表中倒数第k个位置上的结点(k为正整数)。若查找成功，算法输出该结点的data域的值，并返回1;否则，只返回0。要求:
//1)描述算法的基本设计思想。
//2)描述算法的详细实现步骤.
//3）根据设计思想和实现步骤，采用程序设计语言描述算法（使用C、C++或Java 语言
//实现)，关键之处请给出简要注释。
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
int a[5] = {5, 4, 3, 10, 1};
int n = 5;

/**
 * @brief 构建单向链表
 * @param L 链表头节点的指针
 */
void BuildList(LinkList *L) {
	*L = (LinkList)malloc(sizeof(LNode)); // 分配头节点空间
	LNode *newNode, *lastNode = *L; // 使用 lastNode 指向链表的最后一个节点
	for (int i = 0; i < n; i++) {
		newNode = (LNode *)malloc(sizeof(LNode)); // 为新节点分配空间
		newNode->data = a[i]; // 将数据赋值给新节点
		lastNode->next = newNode; // 将新节点连接到链表末尾
		lastNode = lastNode->next; // 移动到新的链表末尾
	}
	lastNode->next = NULL; // 最后一个节点的 next 设为 NULL
}

/**
 * @brief 查找链表中倒数第k个节点的值
 * @param L 链表头节点
 * @param k 倒数第k个节点
 * @return 成功找到返回1，否则返回0
 */
int FindKthFromEnd(LinkList L, int k) {
	LNode *p = L->next, *q = L->next; // 初始化两个指针，指向链表的第一个节点
	int num = 0; // 统计节点数量

	// p指针遍历整个链表
	while (p != NULL) {
		if (num < k)
			num++; // 统计前k个节点
		else
			q = q->next; // p与q间隔k个节点一起移动

		p = p->next; // 移动到下一个节点
	}

	// 如果链表中节点数量少于k，返回0
	if (num < k)
		return 0;
	else {
		printf("倒数第%d个结点的值为:%d\n", k, q->data); // 输出倒数第k个节点的值
		return 1;
	}
}

int main() {
	LinkList L;
	BuildList(&L); // 构建链表
	int k = 5; // 查找倒数第5个节点
	int result = FindKthFromEnd(L, k); // 查找
	if (result)
		printf("查找成功。\n");
	else
		printf("查找失败，链表中节点数量不足%d个。\n", k);
	return 0;
}

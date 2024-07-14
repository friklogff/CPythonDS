//15．单链表有环，是指单链表的最后一个结点的指针指向了链表中的某个结点（通常单链表
//的最后一个结点的指针域是空的)。试编写算法判断单链表是否存在环。
//1 )给出算法的基本设计思想。
//2)根据设计思想，采用C或C++语言描述算法，关键之处给出注释。
//3 )说明你所设计算法的时间复杂度和空间复杂度。

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 定义链表元素类型
typedef int ElemType;

// 链表节点结构体定义
typedef struct LNode {
	ElemType data;       // 数据域
	struct LNode *next;  // 指针域，指向下一个节点
} LNode;

// 初始化数组和数组长度
int a[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 4, 5, 6, 7, 8, 9};
int n = 15;

/**
 * @brief 构建单向链表
 * @param L 链表头节点
 */
void BuildList(LNode *L) {
	L->data = a[0]; // 初始化头节点数据
	LNode *s, *r = L; // 使用 r 指向链表的最后一个节点
	for (int i = 1; i < n; i++) {
		s = (LNode *)malloc(sizeof(LNode)); // 为新节点分配空间
		s->data = a[i]; // 将数据赋值给新节点
		r->next = s; // 将新节点连接到链表末尾
		r = r->next; // 移动到新的链表末尾
	}
	r->next = NULL; // 最后一个节点的 next 设为 NULL
}

/**
 * @brief 显示链表元素
 * @param L 链表头节点
 */
void DisplayList(LNode *L) {
	LNode *s = L; // 当前节点指针
	while (s) {
		printf("%d ", s->data); // 打印当前节点数据
		s = s->next; // 移动到下一个节点
	}
	printf("\n");
}

/**
 * @brief 查找链表中的环的入口节点
 * @param L 链表头节点
 * @return 环的入口节点指针，如果没有环则返回 NULL
 */
LNode *FindCycleEntrance(LNode *L) {
	LNode *f = L, *s = L; // 初始化快慢指针

	// 判断链表中是否有环
	while (s != NULL && f != NULL && f->next != NULL) {
		s = s->next; // 慢指针走一步
		f = f->next->next; // 快指针走两步

		// 快慢指针相遇，证明链表中有环
		if (s != NULL && s->data == f->data)
			break;
	}

	// 如果链表中没有环，返回 NULL
	if (s == NULL || f == NULL || f->next == NULL)
		return NULL;

	// 快慢指针相遇后，将慢指针重新指向链表头节点
	LNode *p = L, *q = s;
	// 同时移动两个指针，每次都走一步，直到它们相遇，相遇点即为环的入口
	while (p->data != q->data) {
		p = p->next;
		q = q->next;
	}
	return p; // 返回环的入口节点
}

int main() {
	LNode list; // 声明链表头节点
	LNode *L = &list;
	BuildList(L); // 构建链表
	printf("L:\n");
	DisplayList(L); // 显示链表
	LNode *ans = FindCycleEntrance(L); // 查找环的入口
	if (ans != NULL) {
		printf("环口值为:%d\n", ans->data); // 输出环入口的值
	} else {
		printf("链表中没有环。\n");
	}
	return 0;
}

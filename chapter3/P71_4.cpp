#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 定义链表元素类型
typedef char ElemType;

// 链表节点结构体定义
typedef struct LNode {
	ElemType data;       // 数据域
	struct LNode *next;  // 指针域，指向下一个节点
} LNode, *LinkList;

// 初始化数组和数组长度
char s1[4] = {'a', 'b', 'b', 'c'};
int n = 4;

/**
 * @brief 构建单向链表
 * @param L 链表头节点指针
 */
void BuildList(LinkList *L) {
	*L = (LinkList)malloc(sizeof(LNode)); // 分配头节点空间
	LNode *newNode, *lastNode = *L; // 使用 lastNode 指向链表的最后一个节点
	for (int i = 0; i < n; i++) {
		newNode = (LNode *)malloc(sizeof(LNode)); // 为新节点分配空间
		newNode->data = s1[i]; // 将数据赋值给新节点
		lastNode->next = newNode; // 将新节点连接到链表末尾
		lastNode = lastNode->next; // 移动到新的链表末尾
	}
	lastNode->next = NULL; // 最后一个节点的 next 设为 NULL
}

/**
 * @brief 检查链表是否为回文
 * @param L 链表头节点
 * @param n 链表长度
 * @return true 如果是回文，否则 false
 */
bool IsPalindrome(LinkList L, int n) {
	char str[n / 2]; // 用于存储前半段的字符
	LNode *p = L->next;
	int i;

	// 将前半段字符存入数组
	for (i = 0; i < n / 2; i++) {
		str[i] = p->data;
		p = p->next;
	}
	i--; // 将i调整到最后一个存入字符的位置

	// 如果长度为奇数，跳过中间的字符
	if (n % 2 != 0)
		p = p->next;

	// 检查后半段字符是否与前半段字符对称
	while (p && p->data == str[i]) {
		i--;
		p = p->next;
	}

	// 如果 i == -1，则所有字符匹配，返回true，否则返回false
	return i == -1;
}

int main() {
	LinkList L;
	BuildList(&L); // 构建链表
	if (IsPalindrome(L, n)) // 检查链表是否为回文
		printf("yes\n");
	else
		printf("no\n");
	return 0;
}

//18.【2012统考真题】假定采用带头结点的单链表保存单词，当两个单词有相同的后缀时，
//可共享相同的后缀存储空间，例如，loading 和 being 的存储映像如下图所示。
//strl、
//豳io十a日al
//str2,
//n]一
//豳b十e]
//设str1和str2分别指向两个单词所在单链表的头结点，链表结点结构为data ] next ,请设计一个时间上尽可能高效的算法，找出由strl和str2所指向两个链表共同后缀的起始位置（如图中字符i所在结点的位置p)。要求:
//1)给出算法的基本设计思想。
//2）根据设计思想，采用C或C++或Java语言描述算法，关键之处给出注释。3）说明你所设计算法的时间复杂度。

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char ElemType; // 定义链表元素类型

// 链表节点结构体定义
typedef struct LNode {
	ElemType data;       // 数据域
	struct LNode *next;  // 指针域，指向下一个节点
} LNode, *LinkList;

// 初始化两个字符数组和他们的长度
char a[7] = {'l', 'o', 'a', 'd', 'i', 'n', 'g'};

char b[5] = {'b', 'e', 'i', 'n', 'g'};
int n1 = 7, n2 = 5;

/**
 * @brief   构建单向链表
 * @param   L      链表头节点的指针
 * @param   arr    数组
 * @param   n      数组长度
 */
void BuildList(LinkList *L, char arr[], int n) {
	*L = (LinkList)malloc(sizeof(LNode)); // 分配头节点空间
	LNode *newNode, *lastNode = *L; // 使用 lastNode 指向链表的最后一个节点
	for (int i = 0; i < n; i++) {
		newNode = (LNode *)malloc(sizeof(LNode)); // 为新节点分配空间
		newNode->data = arr[i]; // 将数据赋值给新节点
		lastNode->next = newNode; // 将新节点连接到链表末尾
		lastNode = lastNode->next; // 移动到新的链表末尾
	}
	lastNode->next = NULL; // 最后一个节点的 next 设为 NULL
}

/**
 * @brief   显示链表元素
 * @param   L      链表头节点
 */
void DisplayList(LinkList L) {
	LNode *currentNode = L->next; // 跳过头节点
	while (currentNode) {
		printf("%c ", currentNode->data); // 打印当前节点数据
		currentNode = currentNode->next; // 移动到下一个节点
	}
	printf("\n");
}

/**
 * @brief   计算链表长度
 * @param   L      链表头节点
 * @return  链表长度
 */
int GetListLength(LinkList L) {
	int length = 0; // 初始化长度为 0
	LNode *currentNode = L->next; // 跳过头节点
	while (currentNode) {
		length++; // 每遍历一个节点，长度加 1
		currentNode = currentNode->next; // 移动到下一个节点
	}
	return length;
}

/**
 * @brief   查找两个链表的公共后缀起始节点
 * @param   L1     第一个链表
 * @param   L2     第二个链表
 * @return  公共后缀起始节点的指针
 */
LinkList FindFirstCommonNode(LinkList L1, LinkList L2) {
	int len1 = GetListLength(L1), len2 = GetListLength(L2); // 获取两个链表的长度
	int lengthDifference = abs(len1 - len2); // 计算长度差
	LNode *pNode = L1->next, *qNode = L2->next; // 跳过头节点，指向第一个节点

	// 让较长的链表先走 "长度差" 步
	if (len1 >= len2) {
		while (lengthDifference--) {
			pNode = pNode->next;
		}
	} else {
		while (lengthDifference--) {
			qNode = qNode->next;
		}
	}

	// 同时遍历两个链表，寻找第一个相同的节点
	while (pNode && qNode) {
		if (pNode->data != qNode->data) {
			pNode = pNode->next;
			qNode = qNode->next;
		} else
			return pNode; // 找到第一个相同的节点
	}
	return NULL; // 如果没有找到相同的节点
}

int main() {
	LinkList L1, L2;
	BuildList(&L1, a, n1); // 构建链表 L1
	BuildList(&L2, b, n2); // 构建链表 L2
	printf("L1:\n");
	DisplayList(L1); // 显示链表 L1
	printf("L2:\n");
	DisplayList(L2); // 显示链表 L2
	LinkList commonNode = FindFirstCommonNode(L1, L2); // 查找公共后缀的起始节点
	if (commonNode != NULL) {
		printf("公共后缀的起始结点为: %c\n", commonNode->data); // 显示公共后缀起始节点的值
	} else {
		printf("没有找到公共后缀。\n");
	}
	return 0;
}

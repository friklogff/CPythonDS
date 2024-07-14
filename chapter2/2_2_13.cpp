//13.设有一个带头结点的非循环双链表L，
//其每个结点中除有pre、data和next域外，还有一个访问频度域freq,
//其值均初始化为零.每当在链表中进行一次Locate(L,x)运算时，
//令值为x的结点中freq域的值增1，
//并使此链表中的结点保持按访问频度递减的顺序排列，
//且最近访问的结点排在频度相同的结点之前，
//以便使频繁访问的结点总是靠近表头。
//试编写符合上述要求的Locate(L,x)函数，返回找到结点的地址，类型为指针型。
#include <stdio.h>
#include <stdlib.h>

// 定义链表元素类型
typedef int ElemType;

// 链表节点结构体定义（包含访问频度域 freq）
typedef struct LNode {
	ElemType data;       // 数据域
	int freq;            // 访问频度域
	struct LNode *next;  // 指针域，指向下一个节点
	struct LNode *prior; // 指针域，指向前一个节点
} LNode, *LinkList;

// 初始化数组和数组长度
int arr[] = {1, 2, 3, 4, 5};
int len = sizeof(arr) / sizeof(arr[0]);

/**
 * 构建带访问频度域的双向非循环链表
 * @param head 链表头节点的指针
 */
void buildList(LinkList *head) {
	*head = (LinkList)malloc(sizeof(LNode));
	(*head)->prior = NULL;
	(*head)->next = NULL;

	LNode *cur = *head, *newNode;

	// 构建链表节点并连接
	for (int i = 0; i < len; i++) {
		newNode = (LNode *)malloc(sizeof(LNode));
		newNode->data = arr[i];
		newNode->freq = 0; // 初始化访问频度为0

		newNode->next = cur->next;
		newNode->prior = cur;

		if (cur->next != NULL) {
			cur->next->prior = newNode;
		}
		cur->next = newNode;

		cur = newNode;
	}
}

/**
 * 显示链表
 * @param head 链表头节点
 */
void displayList(const LinkList head) {
	LNode *cur = head->next;

	while (cur != NULL) {
		printf("%d (freq: %d) ", cur->data, cur->freq);
		cur = cur->next;
	}
	printf("\n");
}

/**
 * 查找节点x，并更新其访问频度 freq，同时重新排序链表
 * @param head 链表头节点的引用
 * @param x 查找的节点值
 * @return 找到的节点指针，如果未找到，返回 NULL
 */
LNode *Locate(LinkList *head, ElemType x) {
	LNode *p = (*head)->next;
	LNode *q;

	// 查找节点x
	while (p && p->data != x) {
		p = p->next;
	}

	// 如果未找到节点x，返回NULL
	if (!p) {
		printf("没有x这个节点\n");
		return NULL;
	}

	// 增加访问频度freq
	p->freq++;

	// 将节点p从原位置删除
	if (p->next != NULL) {
		p->next->prior = p->prior;
	}
	p->prior->next = p->next;

	// 寻找新的插入位置
	q = p->prior;
	while (q != *head && q->freq <= p->freq) {
		q = q->prior;
	}

	// 将节点p插入到新位置
	p->next = q->next;
	if (q->next != NULL) {
		q->next->prior = p;
	}
	p->prior = q;
	q->next = p;

	return p;
}

int main() {
	LinkList head;
	buildList(&head);
	displayList(head);

	// 测试 Locate 函数
	Locate(&head, 5);
	Locate(&head, 5);
	Locate(&head, 4);
	Locate(&head, 4);
	displayList(head);

	return 0;
}

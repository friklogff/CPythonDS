#include <stdio.h>
#include <stdlib.h>

// 定义链表节点
typedef struct LNode {
	int data;
	struct LNode *next;
} LNode, *LinkList;

// 尾插法建立不带头结点的单链表
LinkList List_rInsert(LinkList &L) { // 正向建立单链表
	L = NULL; // 初始化为空链表

	LNode *s, *r = NULL; // r指向当前链表的尾节点
	int x;
	printf("请输入结点的值（输入9999表示结束）：\n");
	scanf("%d", &x);
	while (x != 9999) { // 输入9999表示结束
		s = (LNode *)malloc(sizeof(LNode)); // 创建新结点
		s->data = x;
		s->next = NULL; // 新结点指向NULL

		if (L == NULL) {
			L = s; // 如果链表为空，新结点就是链表的第一个结点
		} else {
			r->next = s; // 将新结点插入到当前尾节点的后面
		}
		r = s; // 更新尾节点为新结点

		scanf("%d", &x);
	}

	return L;
}

// 遍历链表
void traverseList(LinkList L) {
	LNode *current = L;
	printf("链表内容: ");
	while (current != NULL) {
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}

int main() {
	LinkList L = NULL; // Initialize L to NULL
	L = List_rInsert(L);
	traverseList(L);

	return 0;
}

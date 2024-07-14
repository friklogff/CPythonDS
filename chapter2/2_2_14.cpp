//14．设将n(n>1)个整数存放到不带头结点的单链表L中，


//设计算法将L中保存的序列循环右移k (0<k<n)个位置。
//例如，若k=1，则将链表{0,1,2,3}变为{3,0,1,2}。要求:
//1)给出算法的基本设计思想。
//2)根据设计思想，采用C或C++语言描述算法，关键之处给出注释。
//3 )说明你所设计算法的时间复杂度和空间复杂度。
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType; // 定义链表元素类型

typedef struct LNode {
	ElemType data;
	struct LNode *next;
} LNode, *LinkList;

int a[4] = {2, 3, 4, 9};
int n1 = 4;

int b[5] = {4, 7, 9, 10, 11};
int n2 = 5;

void buildList(LinkList &L, int aa[], int n) {
	L = (LinkList)malloc(sizeof(LNode));
	LNode *s, *r = L;
	for (int i = 0; i < n; i++) {
		s = (LNode *)malloc(sizeof(LNode));
		s->data = aa[i];
		r->next = s;
		r = r->next;
	}
	r->next = NULL;
}

void disp(LinkList L) {
	LNode *s = L->next;
	while (s) {
		printf("%d ", s->data);
		s = s->next;
	}
	printf("\n");
}

LinkList L3;

void buildNew(LinkList L1, LinkList L2) {
	L3 = (LinkList)malloc(sizeof(LNode));
	LNode *p1 = L1->next, *p2 = L2->next, *s, *r;
	r = L3;
	while (p1 && p2) {
		if (p1->data < p2->data)
			p1 = p1->next;
		else if (p1->data > p2->data)
			p2 = p2->next;
		else {
			s = (LNode *)malloc(sizeof(LNode));
			s->data = p1->data;
			r->next = s;
			r = s;
			p1 = p1->next;
			p2 = p2->next;
		}
	}
	r->next = NULL;
}

int main() {
	LinkList L1, L2;
	buildList(L1, a, n1);
	buildList(L2, b, n2);
	printf("L1:\n");
	disp(L1);
	printf("L2:\n");
	disp(L2);
	buildNew(L1, L2);
	printf("L3:\n");
	disp(L3);
	return 0;
}

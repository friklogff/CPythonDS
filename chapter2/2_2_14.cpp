//14���轫n(n>1)��������ŵ�����ͷ���ĵ�����L�У�


//����㷨��L�б��������ѭ������k (0<k<n)��λ�á�
//���磬��k=1��������{0,1,2,3}��Ϊ{3,0,1,2}��Ҫ��:
//1)�����㷨�Ļ������˼�롣
//2)�������˼�룬����C��C++���������㷨���ؼ�֮������ע�͡�
//3 )˵����������㷨��ʱ�临�ӶȺͿռ临�Ӷȡ�
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType; // ��������Ԫ������

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

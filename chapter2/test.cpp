#include <stdio.h>
#include <stdlib.h>

// ��������ڵ�
typedef struct LNode {
	int data;
	struct LNode *next;
} LNode, *LinkList;

// β�巨��������ͷ���ĵ�����
LinkList List_rInsert(LinkList &L) { // ������������
	L = NULL; // ��ʼ��Ϊ������

	LNode *s, *r = NULL; // rָ��ǰ�����β�ڵ�
	int x;
	printf("���������ֵ������9999��ʾ��������\n");
	scanf("%d", &x);
	while (x != 9999) { // ����9999��ʾ����
		s = (LNode *)malloc(sizeof(LNode)); // �����½��
		s->data = x;
		s->next = NULL; // �½��ָ��NULL

		if (L == NULL) {
			L = s; // �������Ϊ�գ��½���������ĵ�һ�����
		} else {
			r->next = s; // ���½����뵽��ǰβ�ڵ�ĺ���
		}
		r = s; // ����β�ڵ�Ϊ�½��

		scanf("%d", &x);
	}

	return L;
}

// ��������
void traverseList(LinkList L) {
	LNode *current = L;
	printf("��������: ");
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

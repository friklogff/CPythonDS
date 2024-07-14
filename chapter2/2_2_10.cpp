//10.������������A=a, az, as,��", am��B=b;, b,b3,.��, b��
//�Ѿ����������������У����һ���㷨���ж�����B�Ƿ�������A�����������С�

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType; // ��������Ԫ������

typedef struct LNode {
	ElemType data;
	struct LNode *next;
} LNode, *LinkList;

// ��ʼ����������鳤��
int a[] = {1, 2, 3, 4, 5, 6};
int n1 = sizeof(a) / sizeof(a[0]);
int b[] = {3, 4, 7};
int n2 = sizeof(b) / sizeof(b[0]);

/**
 * ��������
 * @param L ����ͷ�ڵ��ָ��
 * @param arr ����
 * @param n ���鳤��
 */
void buildList(LinkList *L, int arr[], int n) {
	*L = (LinkList)malloc(sizeof(LNode));
	LNode *cur = *L, *newNode;
	for (int i = 0; i < n; i++) {
		newNode = (LNode *)malloc(sizeof(LNode));
		newNode->data = arr[i];
		cur->next = newNode;
		cur = newNode;
	}
	cur->next = NULL;
}

/**
 * �������L2�Ƿ�������L1��������
 * @param L1 ����1ͷ�ڵ�
 * @param L2 ����2ͷ�ڵ�
 * @return ���L2��L1�������У�����true�����򷵻�false
 */
bool isSubsequence(LinkList L1, LinkList L2) {
	LNode *p1 = L1->next;
	LNode *p2 = L2->next;

	while (p1) {
		// ���L2�Ѿ������꣬˵��L2��L1��������
		if (!p2)
			return true;

		// ��鵱ǰ�ڵ�ֵ�Ƿ����
		if (p1->data == p2->data) {
			p2 = p2->next; // ƥ�䣬�ƶ�L2��ָ��
		} else {
			p2 = L2->next; // ��ƥ�䣬����L2��ָ���ͷ��ʼ
		}
		p1 = p1->next;
	}

	// ����Ƿ�����L2�Ľڵ㶼ƥ��
	return p2 == NULL;
}

int main() {
	LinkList L1, L2;
	buildList(&L1, a, n1);
	buildList(&L2, b, n2);

	if (isSubsequence(L1, L2)) {
		printf("yes\n");
	} else {
		printf("no\n");
	}

	// �ͷ�������ڴ�
	LNode *p;
	while (L1 != NULL) {
		p = L1;
		L1 = L1->next;
		free(p);
	}
	while (L2 != NULL) {
		p = L2;
		L2 = L2->next;
		free(p);
	}

	return 0;
}

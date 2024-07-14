//13.����һ����ͷ���ķ�ѭ��˫����L��
//��ÿ������г���pre��data��next���⣬����һ������Ƶ����freq,
//��ֵ����ʼ��Ϊ��.ÿ���������н���һ��Locate(L,x)����ʱ��
//��ֵΪx�Ľ����freq���ֵ��1��
//��ʹ�������еĽ�㱣�ְ�����Ƶ�ȵݼ���˳�����У�
//��������ʵĽ������Ƶ����ͬ�Ľ��֮ǰ��
//�Ա�ʹƵ�����ʵĽ�����ǿ�����ͷ��
//�Ա�д��������Ҫ���Locate(L,x)�����������ҵ����ĵ�ַ������Ϊָ���͡�
#include <stdio.h>
#include <stdlib.h>

// ��������Ԫ������
typedef int ElemType;

// ����ڵ�ṹ�嶨�壨��������Ƶ���� freq��
typedef struct LNode {
	ElemType data;       // ������
	int freq;            // ����Ƶ����
	struct LNode *next;  // ָ����ָ����һ���ڵ�
	struct LNode *prior; // ָ����ָ��ǰһ���ڵ�
} LNode, *LinkList;

// ��ʼ����������鳤��
int arr[] = {1, 2, 3, 4, 5};
int len = sizeof(arr) / sizeof(arr[0]);

/**
 * ����������Ƶ�����˫���ѭ������
 * @param head ����ͷ�ڵ��ָ��
 */
void buildList(LinkList *head) {
	*head = (LinkList)malloc(sizeof(LNode));
	(*head)->prior = NULL;
	(*head)->next = NULL;

	LNode *cur = *head, *newNode;

	// ��������ڵ㲢����
	for (int i = 0; i < len; i++) {
		newNode = (LNode *)malloc(sizeof(LNode));
		newNode->data = arr[i];
		newNode->freq = 0; // ��ʼ������Ƶ��Ϊ0

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
 * ��ʾ����
 * @param head ����ͷ�ڵ�
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
 * ���ҽڵ�x�������������Ƶ�� freq��ͬʱ������������
 * @param head ����ͷ�ڵ������
 * @param x ���ҵĽڵ�ֵ
 * @return �ҵ��Ľڵ�ָ�룬���δ�ҵ������� NULL
 */
LNode *Locate(LinkList *head, ElemType x) {
	LNode *p = (*head)->next;
	LNode *q;

	// ���ҽڵ�x
	while (p && p->data != x) {
		p = p->next;
	}

	// ���δ�ҵ��ڵ�x������NULL
	if (!p) {
		printf("û��x����ڵ�\n");
		return NULL;
	}

	// ���ӷ���Ƶ��freq
	p->freq++;

	// ���ڵ�p��ԭλ��ɾ��
	if (p->next != NULL) {
		p->next->prior = p->prior;
	}
	p->prior->next = p->next;

	// Ѱ���µĲ���λ��
	q = p->prior;
	while (q != *head && q->freq <= p->freq) {
		q = q->prior;
	}

	// ���ڵ�p���뵽��λ��
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

	// ���� Locate ����
	Locate(&head, 5);
	Locate(&head, 5);
	Locate(&head, 4);
	Locate(&head, 4);
	displayList(head);

	return 0;
}

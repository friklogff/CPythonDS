//12��������ѭ������������ͷָ��ֱ�Ϊh1�� h2��
//��дһ������������h2���ӵ�����h1֮��
//Ҫ�����Ӻ�������Ա���ѭ��������ʽ��
#include <stdio.h>
#include <stdlib.h>

// ��������Ԫ������
typedef int ElemType;

// ����ڵ�ṹ�嶨�壨����ѭ������
typedef struct LNode {
	ElemType data;        // ������
	struct LNode *next;   // ָ����ָ����һ���ڵ�
} LNode, *LinkList;

// ��ʼ����������鳤��
int arr1[] = {1, 2, 3, 4};
int len1 = sizeof(arr1) / sizeof(arr1[0]);

int arr2[] = {5, 6, 7, 8, 9};
int len2 = sizeof(arr2) / sizeof(arr2[0]);

/**
 * ��������ѭ������
 * @param head ����ͷ�ڵ��ָ��
 * @param arr ����
 * @param len ���鳤��
 */
void buildList(LinkList *head, int arr[], int len) {
	*head = (LinkList)malloc(sizeof(LNode));    // ����ͷ�ڵ�ռ�
	LNode *cur = *head, *newNode;

	// ��������ڵ㲢����
	for (int i = 0; i < len; i++) {
		newNode = (LNode *)malloc(sizeof(LNode));
		newNode->data = arr[i];
		cur->next = newNode;
		cur = newNode;
	}
	cur->next = *head;   // ���һ���ڵ�� next ��Ϊͷ�ڵ㣬�γ�ѭ��
}

/**
 * ��ʾ����ѭ������
 * @param head ����ͷ�ڵ�
 */
void displayList(const LinkList head) {
	const LNode *cur = head->next;
	while (cur != head) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

/**
 * ����������ѭ���������ӳ�һ��ѭ������
 * @param L1 ����1��ͷ�ڵ��ָ��
 * @param L2 ����2��ͷ�ڵ��ָ��
 */
void mergeLists(LinkList *L1, LinkList *L2) {
	LNode *p = (*L1)->next; // ָ������1�ĵ�һ���ڵ�
	LNode *q = (*L2)->next; // ָ������2�ĵ�һ���ڵ�

	// �ҵ�����1�����һ���ڵ�
	while (p->next != *L1) {
		p = p->next;
	}

	// �ҵ�����2�����һ���ڵ�
	while (q->next != *L2) {
		q = q->next;
	}

	// ������1�����һ���ڵ�ָ������2�ĵ�һ���ڵ�
	p->next = (*L2)->next;

	// ������2�����һ���ڵ�ָ������1��ͷ�ڵ�
	q->next = *L1;
}

int main() {
	LinkList L1, L2;

	// ��������L1��L2
	buildList(&L1, arr1, len1);
	buildList(&L2, arr2, len2);

	// ��ʾ����L1
	printf("����L1:\n");
	displayList(L1);

	// ��ʾ����L2
	printf("����L2:\n");
	displayList(L2);

	// ����������ѭ���������ӳ�һ��ѭ������
	mergeLists(&L1, &L2);

	// ��ʾ�ϲ��������L1
	printf("�ϲ��������L1:\n");
	displayList(L1);

	// �ͷ�������ڴ�
	LNode *p = L1->next;
	while (p != L1) {
		LNode *temp = p;
		p = p->next;
		free(temp);
	}
	free(L1);

	return 0;
}

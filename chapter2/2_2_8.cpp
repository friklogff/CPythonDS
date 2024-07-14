//08.��A��B��������������ͷ���)������Ԫ�ص����������һ���㷨��A��B�е�
//����Ԫ�ز���������C��Ҫ���ƻ�A��B�Ľ�㡣

#include <stdio.h>
#include <stdlib.h>

// ��������Ԫ������
typedef int ElemType;

// ����ڵ�ṹ�嶨��
typedef struct LNode {
	ElemType data;        // ������
	struct LNode *next;   // ָ����ָ����һ���ڵ�
} LNode, *LinkList;

// ��ʼ����������鳤��
int arr1[] = {2, 3, 4, 9};
int len1 = sizeof(arr1) / sizeof(arr1[0]);

int arr2[] = {4, 7, 9, 10, 11};
int len2 = sizeof(arr2) / sizeof(arr2[0]);

/**
 * ��������
 * @param head ����ͷ�ڵ������
 * @param arr ����
 * @param len ���鳤��
 */
void buildList(LinkList &head, int arr[], int len) {
	head = (LinkList)malloc(sizeof(LNode));    // ����ͷ�ڵ�ռ�
	LNode *cur = head, *newNode;

	// ��������ڵ㲢����
	for (int i = 0; i < len; i++) {
		newNode = (LNode *)malloc(sizeof(LNode));
		newNode->data = arr[i];
		cur->next = newNode;
		cur = newNode;
	}
	cur->next = NULL;   // ���һ���ڵ��next��ΪNULL
}

/**
 * ��ʾ����
 * @param head ����ͷ�ڵ�
 */
void displayList(const LinkList head) {
	const LNode *cur = head->next; // ��ͷ�ڵ����һ���ڵ㿪ʼ
	while (cur) {
		printf("%d ", cur->data);  // ��ӡ��ǰ�ڵ�����
		cur = cur->next;           // �ƶ�����һ���ڵ�
	}
	printf("\n");
}

/**
 * ����һ���µ���������L1��L2�еĹ���Ԫ��
 * @param L1 ����1��ͷ�ڵ�
 * @param L2 ����2��ͷ�ڵ�
 * @return �µ�����L3��ͷ�ڵ�
 */
LinkList buildCommonList(LinkList L1, LinkList L2) {
	LinkList L3 = (LinkList)malloc(sizeof(LNode));
	LNode *p1 = L1->next, *p2 = L2->next, *cur = L3;

	// ����L1��L2���ҵ����ǵĹ������֣�������L3
	while (p1 && p2) {
		if (p1->data < p2->data) {
			p1 = p1->next;
		} else if (p1->data > p2->data) {
			p2 = p2->next;
		} else {
			LNode *newNode = (LNode *)malloc(sizeof(LNode));
			newNode->data = p1->data;
			cur->next = newNode;
			cur = newNode;
			p1 = p1->next;
			p2 = p2->next;
		}
	}
	cur->next = NULL; // ���һ���ڵ��next��ΪNULL
	return L3;
}

int main() {
	LinkList L1, L2;

	// ��������L1��L2
	buildList(L1, arr1, len1);
	buildList(L2, arr2, len2);

	// ��ʾ����L1
	printf("����L1:\n");
	displayList(L1);

	// ��ʾ����L2
	printf("����L2:\n");
	displayList(L2);

	// �����µ�����L3������L1��L2�еĹ���Ԫ��
	LinkList L3 = buildCommonList(L1, L2);
	printf("����L3 (L1��L2�еĹ���Ԫ��):\n");
	displayList(L3);

	return 0;
}

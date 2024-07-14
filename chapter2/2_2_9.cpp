//09.����֪��������A��B�ֱ��ʾ�������ϣ���Ԫ�ص������С����ƺ�����
//��A��B�Ľ������������A�����С�
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
int arr1[] = {1, 2, 3, 4};
int len1 = sizeof(arr1) / sizeof(arr1[0]);

int arr2[] = {2, 4, 5, 6, 7, 8};
int len2 = sizeof(arr2) / sizeof(arr2[0]);

/**
 * ��������
 * @param L ����ͷ�ڵ��ָ��
 * @param arr ����
 * @param len ���鳤��
 */
void buildList(LinkList &L, int arr[], int len) {
	L = (LinkList)malloc(sizeof(LNode));    // ����ͷ�ڵ�ռ�
	LNode *cur = L, *newNode;

	// ��������ڵ㲢����
	for (int i = 0; i < len; i++) {
		newNode = (LNode *)malloc(sizeof(LNode));
		newNode->data = arr[i];
		cur->next = newNode;
		cur = newNode;
	}
	cur->next = NULL;    // ���һ���ڵ��next��ΪNULL
}

/**
 * ��ʾ����
 * @param L ����ͷ�ڵ�
 */
void displayList(const LinkList L) {
	const LNode *cur = L->next; // ��ͷ�ڵ����һ���ڵ㿪ʼ
	while (cur) {
		printf("%d ", cur->data);  // ��ӡ��ǰ�ڵ�����
		cur = cur->next;           // �ƶ�����һ���ڵ�
	}
	printf("\n");
}

/**
 * ������B������A�Ľ������������A��
 * @param A ����A��ͷ�ڵ������
 * @param B ����B��ͷ�ڵ�
 */
void Union(LinkList &A, LinkList B) {
	LNode *curA = A->next, *curB = B->next, *prevA = A;
	LNode *temp;

	while (curA && curB) {
		if (curA->data < curB->data) {
			// ɾ������A�е�ǰ�ڵ�
			temp = curA;
			curA = curA->next;
			prevA->next = curA;
			free(temp);
		} else if (curA->data > curB->data) {
			curB = curB->next;
		} else {
			// ��ǰ�ڵ���A��B�ж��У�����ɾ�����ƶ�����һ���ڵ�
			prevA = curA;
			curA = curA->next;
			curB = curB->next;
		}
	}

	// ɾ������A��ʣ��Ľڵ�
	while (curA) {
		temp = curA;
		curA = curA->next;
		prevA->next = curA;
		free(temp);
	}
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

	// ��A��B�Ľ������������A������
	Union(L1, L2);

	// ��ʾ�󽻼��������L1
	printf("�󽻼��������L1:\n");
	displayList(L1);

	// �ͷ�������ڴ�
	LNode *p;
	while (L2 != NULL) {
		p = L2;
		L2 = L2->next;
		free(p);
	}

	return 0;
}

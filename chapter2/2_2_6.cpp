//06.��C= {a, by, az, b,��, an b}Ϊ���Ա����ô�ͷ���ĵ������ţ�


//���һ���͵��㷨��������Ϊ�������Ա�ʹ��A= {a, az,"��" , a}��B= {bw.��, b2, b}��
#include <stdio.h>
#include <stdlib.h>

// ��������Ԫ������
typedef int ElemType;

// ����ڵ�ṹ�嶨��
typedef struct LNode {
	ElemType data;       // ������
	struct LNode *next;  // ָ����ָ����һ���ڵ�
} LNode, *LinkList;

// ��ʼ����������鳤��
int arr[] = {2, 7, 4, 1, 9};
int len = sizeof(arr) / sizeof(arr[0]);

/**
 * ��������
 * @param head ����ͷ�ڵ��ָ��
 */
void buildList(LinkList &head) {
	head = (LinkList)malloc(sizeof(LNode));    // ����ͷ�ڵ�ռ�
	LNode *cur = head, *newNode;

	// ��������ڵ㲢����
	for (int i = 0; i < len; i++) {
		newNode = (LNode *)malloc(sizeof(LNode));
		newNode->data = arr[i];
		cur->next = newNode;
		cur = newNode;
	}
	cur->next = NULL;   // ���һ���ڵ�� next ��Ϊ NULL
}

/**
 * ��ʾ����
 * @param head ����ͷ�ڵ�
 */
void displayList(LinkList head) {
	LNode *cur = head->next; // ��ͷ�ڵ����һ���ڵ㿪ʼ
	while (cur) {
		printf("%d ", cur->data);  // ��ӡ��ǰ�ڵ�����
		cur = cur->next;           // �ƶ�����һ���ڵ�
	}
	printf("\n");
}

/**
 * ������ L1 �ֳ���������һ������ԭ����������λ�õĽڵ㣬��һ������ż��λ�õĽڵ�
 * @param L1 ����1ͷ�ڵ������
 * @return ������ L2 ��ͷ�ڵ�
 */
LinkList splitList(LinkList &L1) {
	// �����µ����� L2
	LinkList L2 = (LinkList)malloc(sizeof(LNode));
	L2->next = NULL;

	LNode *cur1 = L1;            // L1 �ĵ�ǰ�ڵ�
	LNode *cur2 = L2;             // L2 �ĵ�ǰ�ڵ�
	LNode *origNext = L1->next; // ���ڱ�����ָ��
	int index = 0;                // ��¼�ڵ��λ��

	// �Ͽ�L1��ͷ�ڵ�
	L1->next = NULL;

	// ����ԭ���������ڵ���䵽L1��L2
	while (origNext != NULL) {
		index++;
		if (index % 2 == 0) {
			cur2->next = origNext;
			cur2 = origNext;
		} else {
			cur1->next = origNext;
			cur1 = origNext;
		}
		origNext = origNext->next;
	}

	// �Ͽ�L1��L2��ĩβ�ڵ�
	cur1->next = NULL;
	cur2->next = NULL;

	return L2; // �����µ�����L2
}

int main() {
	LinkList L1;

	buildList(L1);  // ��������
	printf("ԭʼ����\n");
	displayList(L1); // ��ʾԭʼ����

	// �ָ�����
	LinkList L2 = splitList(L1);
	printf("L1 (����λ�õĽڵ�)��\n");
	displayList(L1); // ��ʾ����L1

	printf("L2 (ż��λ�õĽڵ�)��\n");
	displayList(L2); // ��ʾ����L2

	return 0;
}


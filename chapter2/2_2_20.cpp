//20.��2019ͳ�����⡿�����Ա�L=(a,as,a,��",a-2,aa- ,a,)���ô�ͷ���ĵ������棬��
//���еĽ�㶨������:
//typedef struct node{ int data;
//struct node*next;}NODE;
//�����һ���ռ临�Ӷ�ΪO(1)��ʱ���Ͼ����ܸ�Ч���㷨����������L�еĸ���㣬�õ����Ա�L'=(a,,am,az,a.j,a, ,a-2��)��Ҫ��:
//1)�����㷨�Ļ������˼��.
//2���������˼�룬����C��C++���������㷨���ؼ�֮������ע�͡�3��˵��������Ƶ��㷨��ʱ�临�Ӷȡ�

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
int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
int len = sizeof(arr) / sizeof(arr[0]);

/**
 * ������������
 * @param head ����ͷ�ڵ��ָ��
 */
void buildList(LinkList *head) {
	*head = (LinkList)malloc(sizeof(LNode));     // ����ͷ�ڵ�ռ�
	LNode *cur = *head, *newNode;

	// ��������ڵ㲢����
	for (int i = 0; i < len; i++) {
		newNode = (LNode *)malloc(sizeof(LNode));
		newNode->data = arr[i];
		cur->next = newNode;
		cur = newNode;
	}
	cur->next = NULL;    // ���һ���ڵ�� next ��Ϊ NULL
}

/**
 * ��ʾ��������
 * @param head ����ͷ�ڵ�
 */
void displayList(const LinkList head) {
	const LNode *cur = head->next;    // ��ͷ�ڵ����һ���ڵ㿪ʼ
	while (cur) {
		printf("%d ", cur->data);     // ��ӡ��ǰ�ڵ�����
		cur = cur->next;              // �ƶ�����һ���ڵ�
	}
	printf("\n");
}

/**
 * ��ת����ĺ�벿�ֲ�������ϲ���ԭ����
 * @param head ����ͷ�ڵ��ָ��
 */
void mergeReversedHalf(LinkList *head) {
	LNode *slow = *head, *fast = *head;

	// ʹ�ÿ���ָ���ҵ�������м�ڵ�
	while (fast->next != NULL && fast->next->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}

	// �ָ������ǰ��������
	LNode *secondHalf = slow->next;
	slow->next = NULL;

	// ��ת����ĵڶ�����
	LNode *prev = NULL, *curr = secondHalf, *next;
	while (curr != NULL) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	secondHalf = prev;

	// �ϲ���������
	LNode *firstHalf = (*head)->next;
	while (secondHalf != NULL) {
		LNode *tmp1 = firstHalf->next;
		LNode *tmp2 = secondHalf->next;

		firstHalf->next = secondHalf;
		secondHalf->next = tmp1;

		firstHalf = tmp1;
		secondHalf = tmp2;
	}
}

int main() {
	LinkList head;

	buildList(&head);     // ��������
	printf("ԭʼ����\n");
	displayList(head);    // ��ʾ����

	mergeReversedHalf(&head);  // ��ת����ĺ�벿�ֲ��ϲ�
	printf("����������\n");
	displayList(head);    // ��ʾ����������

	// �ͷ�������ڴ�
	LNode *p;
	while (head != NULL) {
		p = head;
		head = head->next;
		free(p);
	}

	return 0;
}

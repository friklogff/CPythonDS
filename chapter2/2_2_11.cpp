//11�����һ���㷨�����жϴ�ͷ����ѭ��˫�����Ƿ�Գơ�
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ��������Ԫ������
typedef int ElemType;

// ����ڵ�ṹ�嶨�� (˫��ѭ������)
typedef struct LNode {
	ElemType data;        // ������
	struct LNode *next;   // ָ����ָ����һ���ڵ�
	struct LNode *prior;  // ָ����ָ��ǰһ���ڵ�
} LNode, *LinkList;

// ��ʼ����������鳤��
int arr[] = {1, 2, 3, 4, 2, 1};
int len = sizeof(arr) / sizeof(arr[0]);

/**
 * ����˫��ѭ������
 * @param head ����ͷ�ڵ��ָ��
 */
void buildList(LinkList *head) {
	*head = (LinkList)malloc(sizeof(LNode));
	(*head)->prior = *head;
	(*head)->next = *head;

	LNode *cur = *head, *newNode;

	// ��������ڵ㲢����
	for (int i = 0; i < len; i++) {
		newNode = (LNode *)malloc(sizeof(LNode));
		newNode->data = arr[i];

		newNode->next = cur->next;
		cur->next->prior = newNode;

		newNode->prior = cur;
		cur->next = newNode;

		cur = newNode;
		(*head)->prior = cur;
	}
}

/**
 * ��ʾ˫��ѭ������
 * @param head ����ͷ�ڵ�
 */
void displayList(const LinkList head) {
	LNode *cur = head->next;

	while (cur != head) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

/**
 * ���˫��ѭ�������Ƿ��ǻ�������
 * @param head ����ͷ�ڵ�
 * @return ����ǻ���������true�����򷵻�false
 */
bool isPalindrome(LinkList head) {
	LNode *p = head->next;
	LNode *q = head->prior;

	while (p != q && q->next != p) {
		if (p->data == q->data) {
			p = p->next;
			q = q->prior;
		} else {
			return false;
		}
	}
	return true;
}

int main() {
	LinkList head;

	buildList(&head);       // ��������
	displayList(head);      // ��ʾ����

	if (isPalindrome(head)) {    // ����Ƿ��ǻ�������
		printf("�ǻ�������\n");
	} else {
		printf("���ǻ�������\n");
	}

	// �ͷ�������ڴ�
	LNode *cur = head->next;
	while (cur != head) {
		LNode *temp = cur;
		cur = cur->next;
		free(temp);
	}
	free(head);

	return 0;
}

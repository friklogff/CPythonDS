//07����һ����������ĵ������У������ظ���Ԫ�ء�����㷨ɾ���ظ���Ԫ�أ�����(7,10,
//10,21,30,42,42,42,51,70������Ϊ( 7,10,21,30,42,51,70 ).

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ��������Ԫ������
typedef int ElemType;

// ����ڵ�ṹ�嶨��
typedef struct LNode {
	ElemType data;       // ������
	struct LNode *next;  // ָ����ָ����һ���ڵ�
} LNode, *LinkList;

// ��ʼ����������鳤��
int arr[] = {10, 21, 30, 42, 42, 42, 51, 70};
int len = sizeof(arr) / sizeof(arr[0]);

/**
 * ��������
 * @param head ����ͷ�ڵ��ָ��
 */
void buildList(LinkList *head) {
	*head = (LinkList)malloc(sizeof(LNode));    // ����ͷ�ڵ�ռ�
	LNode *cur = *head, *newNode;

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
void displayList(const LinkList head) {
	const LNode *cur = head->next; // ��ͷ�ڵ����һ���ڵ㿪ʼ
	while (cur) {
		printf("%d ", cur->data);  // ��ӡ��ǰ�ڵ�����
		cur = cur->next;           // �ƶ�����һ���ڵ�
	}
	printf("\n");
}

/**
 * ɾ�������е��ظ��ڵ�
 * @param head ����ͷ�ڵ��ָ��
 */
void deleteDuplicates(LinkList *head) {
	if ((*head)->next == NULL)
		return; // �������Ϊ�ջ�ֻ��һ���ڵ㣬ֱ�ӷ���

	LNode *cur = (*head)->next;
	LNode *nextNode;

	// ������������ظ��ڵ㲢ɾ��
	while (cur->next != NULL) {
		if (cur->data == cur->next->data) {
			nextNode = cur->next;       // ������һ���ڵ�
			cur->next = nextNode->next; // ��ǰ�ڵ�� next ������һ���ڵ�
			free(nextNode);             // �ͷű�ɾ���Ľڵ�
		} else {
			cur = cur->next;            // �ƶ�����һ���ڵ�
		}
	}
}

int main() {
	LinkList head;

	buildList(&head); // ��������
	printf("ɾ��ǰ:\n");
	displayList(head); // ��ʾԭʼ����

	deleteDuplicates(&head); // ɾ�������е��ظ��ڵ�
	printf("ɾ����:\n");
	displayList(head); // ��ʾɾ���ظ��ڵ�������

	return 0; // �������
}

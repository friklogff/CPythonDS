/*
�Ա�д�ڴ�ͷ���ĵ�������ɾ��һ����Сֵ���ĸ�Ч�㷨
������ý��Ψһ)��
*/
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType; // ��������Ԫ������

// ����ڵ�ṹ�嶨��
typedef struct LNode {
	ElemType data;          // ������
	struct LNode *next;     // ָ����ָ����һ���ڵ�
} LNode, *LinkList;

/**
 * ɾ��������ֵ��С�Ľڵ�
 * @param head ����ͷ�ڵ������
 */
void deleteMinNode(LinkList &head) {
	LNode *prev = head, *cur = head->next;
	LNode *minPrev = prev, *minCur = cur;

	// ��������Ѱ����Сֵ�ڵ�
	while (cur != NULL) {
		if (cur->data < minCur->data) {
			minCur = cur;   // ������Сֵ�ڵ�
			minPrev = prev; // ������Сֵ�ڵ��ǰ���ڵ�
		}
		prev = cur;
		cur = cur->next;
	}

	// ɾ����Сֵ�ڵ�
	if (minCur != NULL) {
		minPrev->next = minCur->next; // ����Сֵ�ڵ�������жϿ�
		free(minCur);                 // �ͷ���Сֵ�ڵ���ڴ�
	}
}

int main() {
	LinkList head = (LinkList)malloc(sizeof(LNode)); // ��̬����ͷ�ڵ�
	head->next = NULL;

	// ���Ԫ�ص�����
	int arr[5] = {5, 3, 8, 1, 6};
	LNode *current = head;
	for (int i = 0; i < 5; i++) {
		LNode *newNode = (LNode *)malloc(sizeof(LNode)); // ��̬�����½ڵ�
		newNode->data = arr[i];                          // �����½ڵ������
		newNode->next = NULL;                            // ��ʼ���½ڵ�� next Ϊ NULL
		current->next = newNode;                         // �����½ڵ�
		current = newNode;                               // �ƶ����½ڵ�
	}

	// ��ӡԭʼ����
	printf("Original linked list:\n");
	current = head->next;
	while (current != NULL) {
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");

	// ɾ��������ֵ��С�Ľڵ�
	deleteMinNode(head);

	// ��ӡɾ����Сֵ�ڵ�������
	printf("After deleting the minimum element:\n");
	current = head->next;
	while (current != NULL) {
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");

	return 0;
}

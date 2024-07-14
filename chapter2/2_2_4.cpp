//04������һ������ͷ���ĵ������У����н���Ԫ��ֵ����
//�Ա�дһ��������ɾ���������н��ڸ���������ֵ����Ϊ��������������
//֮���Ԫ�أ�������).
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType; // ��������Ԫ������

// ����ڵ�ṹ�嶨��
typedef struct LNode {
	ElemType data;         // ������
	struct LNode *next;    // ָ����ָ����һ���ڵ�
} LNode, *LinkList;

// ��ʼ����������鳤��
int arr[] = {1, 5, 3, 4, 2};
int len = sizeof(arr) / sizeof(arr[0]);

/**
 * ��������
 * @param head ����ͷ�ڵ������
 */
void buildList(LinkList &head) {
	head = (LinkList)malloc(sizeof(LNode));  // ����ͷ�ڵ�ռ�
	LNode *cur = head, *newNode;

	// ��������ڵ㲢����
	for (int i = 0; i < len; i++) {
		newNode = (LNode *)malloc(sizeof(LNode));
		newNode->data = arr[i];
		cur->next = newNode;
		cur = newNode;
	}
	cur->next = NULL; // ���һ���ڵ�� next ��Ϊ NULL
}

/**
 * ��ʾ����
 * @param head ����ͷ�ڵ�
 */
void displayList(const LinkList head) {
	const LNode *cur = head->next;
	while (cur) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

/**
 * ɾ��������ֵ�� (min, max) ֮��Ľڵ�
 * @param head ����ͷ�ڵ������
 * @param min �½�
 * @param max �Ͻ�
 */
void deleteNodesInRange(LinkList &head, int min, int max) {
	LNode *cur = head->next, *prev = head;
	while (cur) {
		if (cur->data > min && cur->data < max) {
			prev->next = cur->next; // ���������Ƴ��ڵ�
			free(cur); // �ͷŽڵ��ڴ�
			cur = prev->next; // �ƶ�����һ���ڵ�
		} else {
			prev = cur;
			cur = cur->next;
		}
	}
}

int main() {
	LinkList head;

	buildList(head); // ��������
	printf("Original list:\n");
	displayList(head); // ��ʾԭʼ����

	deleteNodesInRange(head, 1, 4); // ɾ��ֵ�� (1, 4) ֮��Ľڵ�
	printf("List after deleting nodes with values in range (1, 4):\n");
	displayList(head); // ��ʾɾ���������

	return 0; // �������
}

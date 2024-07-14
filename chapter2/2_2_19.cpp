//19.��2015ͳ�����⡿�õ�������m�����������ĽṹΪ[data] [link]����|data|��
//n (nΪ������)����Ҫ�����һ��ʱ�临�ӶȾ����ܸ�Ч���㷨������������ data��
//����ֵ��ȵĽ�㣬��������һ�γ��ֵĽ���ɾ���������ֵ��ȵĽ�㡣���磬�������ĵ�����head����:
//head
//��һ����-һ����������
//��ɾ�������headΪ
//head
//`2��-ts��-7
//Ҫ��:
//1)�����㷨�Ļ������˼�롣
//2��ʹ��C��C++���ԣ���������������������Ͷ��塣
//3)�������˼�룬����C��C++���������㷨���ؼ�֮������ע�͡�4 )˵����������㷨��ʱ�临�ӶȺͿռ临�Ӷȡ�

#include <stdio.h>
#include <stdlib.h>

// ��������Ԫ������
typedef int ElemType;

// ����ڵ�ṹ�嶨��
typedef struct LNode {
	ElemType data;       // ������
	struct LNode *next;  // ָ����ָ����һ���ڵ�
} LNode, *LinkList;

// ��ʼ������ͳ���
int arr[] = {1, -4, 2, 3, 4, -2};
int length = sizeof(arr) / sizeof(arr[0]);

/**
 * ������������
 * @param head ����ͷ�ڵ��ָ��
 */
void buildList(LinkList *head) {
	*head = (LinkList)malloc(sizeof(LNode));  // ����ͷ�ڵ�ռ�
	LNode *cur = *head, *newNode;

	// ��������ڵ㲢����
	for (int i = 0; i < length; i++) {
		newNode = (LNode *)malloc(sizeof(LNode));
		newNode->data = arr[i];
		cur->next = newNode;
		cur = newNode;
	}
	cur->next = NULL;  // ���һ���ڵ�� next ��Ϊ NULL
}

/**
 * ��ʾ��������
 * @param head ����ͷ�ڵ�
 */
void displayList(const LinkList head) {
	const LNode *cur = head->next;  // ��ͷ�ڵ����һ���ڵ㿪ʼ
	while (cur) {
		printf("%d ", cur->data);  // ��ӡ��ǰ�ڵ�����
		cur = cur->next;  // �ƶ�����һ���ڵ�
	}
	printf("\n");
}

/**
 * ɾ�������о���ֵ��ͬ�Ľڵ㣬��������һ�����ֵĽڵ�
 * @param head ����ͷ�ڵ��ָ��
 * @param n ������Ԫ�صľ���ֵ��󳤶�
 */
void removeDuplicates(LinkList *head, int n) {
	LNode *p = *head;  // ָ������ĵ�ǰ�ڵ�
	int *seen;         // ���ڼ�¼�Ѿ����ڵľ���ֵ
	seen = (int *)malloc(sizeof(int) * (n + 1));
	for (int i = 0; i <= n; i++)
		seen[i] = 0;

	int absValue;  // ���ڴ洢�ڵ�ľ���ֵ
	LNode *temp;   // �����ݴ潫Ҫɾ���Ľڵ�

	while (p->next != NULL) {
		absValue = abs(p->next->data);  // ���㵱ǰ�ڵ����ݵľ���ֵ

		if (seen[absValue] == 0) {
			// �����ǰ����ֵδ���ֹ������Ϊ�Ѿ�����
			seen[absValue] = 1;
			p = p->next;  // �ƶ�����һ���ڵ�
		} else {
			// �����ǰ����ֵ�Ѿ����ֹ���ɾ����ǰ�ڵ�
			temp = p->next;
			p->next = temp->next;
			free(temp);
		}
	}
	free(seen);  // �ͷŶ�̬������ڴ�
}

int main() {
	LinkList head;
	buildList(&head);
	printf("��������: \n");
	displayList(head);
	removeDuplicates(&head, 4);
	printf("�������������: \n");
	displayList(head);

	// �ͷ�������ڴ�
	LNode *cur = head;
	while (cur != NULL) {
		LNode *temp = cur;
		cur = cur->next;
		free(temp);
	}

	return 0;
}

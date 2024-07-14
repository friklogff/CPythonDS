/*�ڴ�ͷ���ĵ������У�ɾ������ֵΪx�Ľ�㣬���ͷ���ռ䣬
����ֵΪ���Ľ�㲻Ψһ���Ա�д�㷨��ʵ������������
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ����ڵ�ṹ�嶨��
typedef struct LNode {
	int data;           // ������
	struct LNode *next; // ָ����ָ����һ���ڵ�
} LNode, *LinkList;

// ��ʼ����������鳤��
int arr[] = {1, 3, 3, 4};
int len = sizeof(arr) / sizeof(arr[0]);

/**
 * ��������
 * @param L ����ͷ�ڵ�
 */
void buildList(LinkList L) {
	LNode *newNode, *cur = L;
	cur->data = arr[0]; // ����ͷ�ڵ�����
	cur->next = NULL;   // ��ʼ��ͷ�ڵ�� next Ϊ NULL

	// �������鹹������
	for (int i = 1; i < len; i++) {
		newNode = (LNode *)malloc(sizeof(LNode)); // ��̬�����½ڵ�
		newNode->data = arr[i];                   // �����½ڵ�����
		newNode->next = NULL;                     // ��ʼ���½ڵ�� next Ϊ NULL
		cur->next = newNode;                      // ��ǰ�ڵ� next ָ���½ڵ�
		cur = newNode;                            // �ƶ����½ڵ�
	}
}

/**
 * ��ʾ����
 * @param L ����ͷ�ڵ�
 */
void displayList(const LinkList L) {
	const LNode *cur = L;
	while (cur) {
		printf("%d ", cur->data); // ��ӡ��ǰ�ڵ�����
		cur = cur->next;          // �ƶ�����һ���ڵ�
	}
	printf("\n");
}

/**
 * ɾ��������ֵΪ x �Ľڵ㷽��һ
 * @param L ����ͷ�ڵ������
 * @param x Ҫɾ����ֵ
 */
void del_x_1(LinkList &L, int x) {
	LNode *p = L->next, *pre = L, *q;
	while (p != NULL) {
		if (p->data == x) {
			q = p;            // q ָ��ɾ�ڵ�
			p = p->next;      // p ָ����һ���ڵ�
			pre->next = p;    // �� q �ڵ�������жϿ�
			free(q);          // �ͷ� q �ڵ�Ŀռ�
		} else {
			pre = p;          // ����, pre �� p ͬ������
			p = p->next;      // p ָ����һ���ڵ�
		}
	}
}

/**
 * ɾ��������ֵΪ x �Ľڵ㷽����
 * @param L ����ͷ�ڵ�
 * @param x Ҫɾ����ֵ
 */
void del_x_2(LinkList L, int x) {
	LNode *p = L->next, *r = L, *q; // r ָ��β��㣬���ֵΪͷ���
	while (p != NULL) {
		if (p->data != x) { // �� p �ڵ�ֵ��Ϊ x ʱ�������ӵ� r β��
			r->next = p;
			r = p;
			p = p->next;    // ����ɨ��
		} else {
			q = p;          // p �ڵ�ֵΪ x ʱ�����ͷ�
			p = p->next;    // ����ɨ��
			free(q);        // �ͷſռ�
		}
	}
	r->next = NULL;         // �����������β���ָ��Ϊ NULL
}

int main() {
	LinkList L = (LinkList)malloc(sizeof(LNode)); // ��̬����ͷ�ڵ�
	buildList(L); // ��������

	printf("Original list:\n");
	displayList(L); // ��ʾ����

	// ʹ�÷���һɾ��ֵΪ 3 �Ľڵ�
	del_x_1(L, 3);
	printf("List after deleting value 3 using method 1:\n");
	displayList(L); // ��ʾ����

	// ���¹��������Բ��Է�����
	buildList(L);

	// ʹ�÷�����ɾ��ֵΪ 3 �Ľڵ�
	del_x_2(L, 3);
	printf("List after deleting value 3 using method 2:\n");
	displayList(L); // ��ʾ����

	return 0; // �������
}

/*
�Ա�д�㷨����ͷ���ĵ�����͵����ã�
��ν"�͵�"��ָ�����ռ临�Ӷ�ΪO(1)��
*/
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
int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
int len = sizeof(arr) / sizeof(arr[0]);

/**
 * ��������
 * @param head ����ͷ�ڵ������
 */
void buildList(LinkList &head) {
	head = (LinkList)malloc(sizeof(LNode));
	LNode *cur = head, *newNode;

	// ��������ڵ㲢����
	for (int i = 0; i < len; i++) {
		newNode = (LNode *)malloc(sizeof(LNode));
		newNode->data = arr[i];
		cur->next = newNode;
		cur = newNode;
	}
	cur->next = NULL;
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
 * ��ת���� (�ⷨ1)
 * @param head ����ͷ�ڵ�
 * @return ��ת�������ͷ�ڵ�
 */
LinkList reverseList1(LinkList head) {
	LNode *p, *r;
	p = head->next; // �ӵ�һ��Ԫ�ؽڵ㿪ʼ
	head->next = NULL; // �Ƚ�ͷ�ڵ�� next ��Ϊ NULL

	while (p != NULL) {
		r = p->next;       // �ݴ� p �ĺ��
		p->next = head->next; // �� p �ڵ���뵽ͷ�ڵ�֮��
		head->next = p;
		p = r;
	}
	return head;
}

/**
 * ��ת���� (�ⷨ2)
 * @param head ����ͷ�ڵ�
 * @return ��ת�������ͷ�ڵ�
 */
LinkList reverseList2(LinkList head) {
	LNode *pre = NULL, *p = head->next, *r;
	if (p != NULL) {
		r = p->next;
		p->next = NULL;  // �����һ���ڵ�
	}

	while (r != NULL) {
		pre = p;         // pre �Ƶ� p
		p = r;           // p �Ƶ� r
		r = r->next;     // r �Ƶ���һ���ڵ�
		p->next = pre;   // ��ת p ��ָ��
	}
	head->next = p;     // �������һ���ڵ�
	return head;
}

int main() {
	LinkList head;

	buildList(head); // ��������

	printf("Original list:\n");
	displayList(head); // ��ʾԭʼ����

	// ʹ�ýⷨ1��ת����
	head = reverseList1(head);
	printf("Reversed list using method 1:\n");
	displayList(head); // ��ʾ��ת�������

	// ���¹��������Բ��Խⷨ2
	buildList(head);

	// ʹ�ýⷨ2��ת����
	head = reverseList2(head);
	printf("Reversed list using method 2:\n");
	displayList(head); // ��ʾ��ת�������

	return 0;
}






//
//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//
//typedef int ElemType; // ��������Ԫ������
//
//// ����ڵ�ṹ�嶨��
//typedef struct LNode {
//    ElemType data;        // ������
//    struct LNode *next;   // ָ����ָ����һ���ڵ�
//} LNode, *LinkList;
//
//// ��ʼ����������鳤��
//int arr[] = {1, 2, 3, 4};
//int len = sizeof(arr) / sizeof(arr[0]);
//
///**
// * ��������
// * @param head ����ͷ�ڵ������
// */
//void buildList(LinkList &head) {
//    head = (LinkList)malloc(sizeof(LNode));  // ����ͷ�ڵ�ռ�
//    LNode *cur = head, *newNode;
//
//    // ��������ڵ㲢����
//    for (int i = 0; i < len; i++) {
//        newNode = (LNode *)malloc(sizeof(LNode));
//        newNode->data = arr[i];
//        cur->next = newNode;
//        cur = newNode;
//    }
//    cur->next = NULL; // ���һ���ڵ�� next ��Ϊ NULL
//}
//
///**
// * ��ʾ����
// * @param head ����ͷ�ڵ�
// */
//void displayList(const LinkList head) {
//    const LNode *cur = head->next;
//    while (cur) {
//        printf("%d ", cur->data);
//        cur = cur->next;
//    }
//    printf("\n");
//}
//
///**
// * ��ת����
// * @param head ����ͷ�ڵ������
// */
//void reverseList(LinkList &head) {
//    LNode *cur = head->next, *nextNode;
//    head->next = NULL; // �Ƚ�ͷ�ڵ�� next ��Ϊ NULL
//
//    // ��ת����Ľڵ�ָ��
//    while (cur) {
//        nextNode = cur->next; // ������һ���ڵ�
//        cur->next = head->next; // ��ǰ�ڵ�ָ��ͷ�ڵ�� next
//        head->next = cur; // ����ǰ�ڵ��ƶ���ͷ�ڵ�֮��
//        cur = nextNode; // �ƶ�����һ���ڵ�
//    }
//}
//
//int main() {
//    LinkList head;
//
//    buildList(head);  // ��������
//    printf("Original list:\n");
//    displayList(head); // ��ʾԭʼ����
//
//    printf("Reversed list:\n");
//    reverseList(head); // ��ת����
//    displayList(head); // ��ʾ��ת�������
//
//    return 0; // �������
//}
//

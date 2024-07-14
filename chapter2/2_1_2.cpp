#include <stdio.h>
#include <stdbool.h>

#define Max 50 // ����˳������󳤶�

// �ṹ�嶨�壬��ʾ˳��� (Sequence List)
typedef struct {
	int data[Max]; // ������������Ԫ��
	int length;    // ���Ա�ĵ�ǰ����
} SqList; // ���Ա�����Ͷ���

/**
 * ��ʼ��˳���
 * @param list ˳���
 */
void initializeList(SqList &list) {
	// �����ʼ������
	int initValues[] = {1, 4, 6, 3, 2, 8, 7};
	int initLength = sizeof(initValues) / sizeof(initValues[0]);

	// ����ʼֵ����˳���
	for (int i = 0; i < initLength; i++) {
		list.data[i] = initValues[i];
	}
	list.length = initLength; // ����˳�����
}

/**
 * ��ת˳���
 * @param list ˳���
 */
void reverseList(SqList &list) {
	// ����˳����жԳ�λ�õ�Ԫ��
	for (int i = 0; i < list.length / 2; i++) {
		int temp = list.data[i];
		list.data[i] = list.data[list.length - i - 1];
		list.data[list.length - i - 1] = temp;
	}
}

/**
 * ��ӡ˳���
 * @param list ˳���
 */
void printList(const SqList &list) {
	// ���˳����е�ÿ��Ԫ��
	for (int i = 0; i < list.length; i++) {
		printf("%d ", list.data[i]);
	}
	printf("\n");
}

int main() {
	SqList list; // ����һ��˳���
	initializeList(list); // ��ʼ��˳���

	printf("Original list:\n");
	printList(list); // ��ӡԭʼ˳���

	reverseList(list); // ��ת˳���

	printf("Reversed list:\n");
	printList(list); // ��ӡ��ת���˳���

	return 0; // �������
}

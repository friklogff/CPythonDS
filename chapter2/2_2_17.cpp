//17.��2009ͳ�����⡿��֪һ�����б�ͷ���ĵ��������ṹΪ
//data
//link
//���������ֻ������ͷָ��list���ڲ��ı������ǰ���£������һ�������ܸ�Ч���㷨�����������е�����k��λ���ϵĽ��(kΪ������)�������ҳɹ����㷨����ý���data���ֵ��������1;����ֻ����0��Ҫ��:
//1)�����㷨�Ļ������˼�롣
//2)�����㷨����ϸʵ�ֲ���.
//3���������˼���ʵ�ֲ��裬���ó���������������㷨��ʹ��C��C++��Java ����
//ʵ��)���ؼ�֮���������Ҫע�͡�
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
int a[5] = {5, 4, 3, 10, 1};
int n = 5;

/**
 * @brief ������������
 * @param L ����ͷ�ڵ��ָ��
 */
void BuildList(LinkList *L) {
	*L = (LinkList)malloc(sizeof(LNode)); // ����ͷ�ڵ�ռ�
	LNode *newNode, *lastNode = *L; // ʹ�� lastNode ָ����������һ���ڵ�
	for (int i = 0; i < n; i++) {
		newNode = (LNode *)malloc(sizeof(LNode)); // Ϊ�½ڵ����ռ�
		newNode->data = a[i]; // �����ݸ�ֵ���½ڵ�
		lastNode->next = newNode; // ���½ڵ����ӵ�����ĩβ
		lastNode = lastNode->next; // �ƶ����µ�����ĩβ
	}
	lastNode->next = NULL; // ���һ���ڵ�� next ��Ϊ NULL
}

/**
 * @brief ���������е�����k���ڵ��ֵ
 * @param L ����ͷ�ڵ�
 * @param k ������k���ڵ�
 * @return �ɹ��ҵ�����1�����򷵻�0
 */
int FindKthFromEnd(LinkList L, int k) {
	LNode *p = L->next, *q = L->next; // ��ʼ������ָ�룬ָ������ĵ�һ���ڵ�
	int num = 0; // ͳ�ƽڵ�����

	// pָ�������������
	while (p != NULL) {
		if (num < k)
			num++; // ͳ��ǰk���ڵ�
		else
			q = q->next; // p��q���k���ڵ�һ���ƶ�

		p = p->next; // �ƶ�����һ���ڵ�
	}

	// ��������нڵ���������k������0
	if (num < k)
		return 0;
	else {
		printf("������%d������ֵΪ:%d\n", k, q->data); // ���������k���ڵ��ֵ
		return 1;
	}
}

int main() {
	LinkList L;
	BuildList(&L); // ��������
	int k = 5; // ���ҵ�����5���ڵ�
	int result = FindKthFromEnd(L, k); // ����
	if (result)
		printf("���ҳɹ���\n");
	else
		printf("����ʧ�ܣ������нڵ���������%d����\n", k);
	return 0;
}

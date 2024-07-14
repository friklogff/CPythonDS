//15���������л�����ָ�����������һ������ָ��ָ���������е�ĳ����㣨ͨ��������
//�����һ������ָ�����ǿյ�)���Ա�д�㷨�жϵ������Ƿ���ڻ���
//1 )�����㷨�Ļ������˼�롣
//2)�������˼�룬����C��C++���������㷨���ؼ�֮������ע�͡�
//3 )˵����������㷨��ʱ�临�ӶȺͿռ临�Ӷȡ�

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ��������Ԫ������
typedef int ElemType;

// �����ڵ�ṹ�嶨��
typedef struct LNode {
	ElemType data;       // ������
	struct LNode *next;  // ָ����ָ����һ���ڵ�
} LNode;

// ��ʼ����������鳤��
int a[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 4, 5, 6, 7, 8, 9};
int n = 15;

/**
 * @brief ������������
 * @param L ����ͷ�ڵ�
 */
void BuildList(LNode *L) {
	L->data = a[0]; // ��ʼ��ͷ�ڵ�����
	LNode *s, *r = L; // ʹ�� r ָ�����������һ���ڵ�
	for (int i = 1; i < n; i++) {
		s = (LNode *)malloc(sizeof(LNode)); // Ϊ�½ڵ����ռ�
		s->data = a[i]; // �����ݸ�ֵ���½ڵ�
		r->next = s; // ���½ڵ����ӵ�����ĩβ
		r = r->next; // �ƶ����µ�����ĩβ
	}
	r->next = NULL; // ���һ���ڵ�� next ��Ϊ NULL
}

/**
 * @brief ��ʾ����Ԫ��
 * @param L ����ͷ�ڵ�
 */
void DisplayList(LNode *L) {
	LNode *s = L; // ��ǰ�ڵ�ָ��
	while (s) {
		printf("%d ", s->data); // ��ӡ��ǰ�ڵ�����
		s = s->next; // �ƶ�����һ���ڵ�
	}
	printf("\n");
}

/**
 * @brief ���������еĻ�����ڽڵ�
 * @param L ����ͷ�ڵ�
 * @return ������ڽڵ�ָ�룬���û�л��򷵻� NULL
 */
LNode *FindCycleEntrance(LNode *L) {
	LNode *f = L, *s = L; // ��ʼ������ָ��

	// �ж��������Ƿ��л�
	while (s != NULL && f != NULL && f->next != NULL) {
		s = s->next; // ��ָ����һ��
		f = f->next->next; // ��ָ��������

		// ����ָ��������֤���������л�
		if (s != NULL && s->data == f->data)
			break;
	}

	// ���������û�л������� NULL
	if (s == NULL || f == NULL || f->next == NULL)
		return NULL;

	// ����ָ�������󣬽���ָ������ָ������ͷ�ڵ�
	LNode *p = L, *q = s;
	// ͬʱ�ƶ�����ָ�룬ÿ�ζ���һ����ֱ�����������������㼴Ϊ�������
	while (p->data != q->data) {
		p = p->next;
		q = q->next;
	}
	return p; // ���ػ�����ڽڵ�
}

int main() {
	LNode list; // ��������ͷ�ڵ�
	LNode *L = &list;
	BuildList(L); // ��������
	printf("L:\n");
	DisplayList(L); // ��ʾ����
	LNode *ans = FindCycleEntrance(L); // ���һ������
	if (ans != NULL) {
		printf("����ֵΪ:%d\n", ans->data); // �������ڵ�ֵ
	} else {
		printf("������û�л���\n");
	}
	return 0;
}
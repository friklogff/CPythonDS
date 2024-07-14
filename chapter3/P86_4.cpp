#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Max 10 // ջ�Ͷ��е��������

// ����ջ�ṹ��
typedef struct {
	int data[Max]; // ������
	int top;       // ջ��ָ��
} Stack;

/**
 * @brief �ж�ջ�Ƿ�Ϊ��
 * @param s ջ
 * @return true ���Ϊ�գ����� false
 */
bool IsStackEmpty(Stack s) {
	return s.top == -1;
}

/**
 * @brief �ж�ջ�Ƿ�����
 * @param s ջ
 * @return true ������������� false
 */
bool IsStackFull(Stack s) {
	return s.top == Max - 1;
}

/**
 * @brief ��Ԫ�� x ��ջ
 * @param s ջָ��
 * @param x Ҫ��ջ��Ԫ��
 * @return true ��ʾ�����ɹ���false ��ʾ����ʧ��
 */
bool Push(Stack *s, int x) {
	if (IsStackFull(*s))
		return false;
	s->data[++s->top] = x;
	return true;
}

/**
 * @brief ��ջ�г�ջһ��Ԫ��
 * @param s ջָ��
 * @param x ָ�򱣴��ջԪ�ص�ָ��
 * @return 1 ��ʾ�����ɹ���0 ��ʾ����ʧ��
 */
int Pop(Stack *s, int *x) {
	if (IsStackEmpty(*s)) {
		printf("ջ��\n");
		return 0;
	}
	*x = s->data[s->top--];
	return 1;
}

/**
 * @brief ��ʾջ�е�Ԫ��
 * @param s ջ
 */
void DisplayStack(Stack s) {
	int tempTop = s.top;
	while (tempTop != -1) {
		printf("%d ", s.data[tempTop--]);
	}
	printf("\n");
}

/**
 * @brief ��Ԫ�� x ���
 * @param s1 ������ջ������ջ
 * @param s2 ���ڳ�ջ������ջ
 * @param x Ҫ��ӵ�Ԫ��
 * @return 1 ��ʾ�����ɹ���0 ��ʾ����ʧ��
 */
int Enqueue(Stack *s1, Stack *s2, int x) {
	if (!IsStackFull(*s1)) {
		Push(s1, x);
		return 1;
	} else if (IsStackFull(*s1) && !IsStackEmpty(*s2)) {
		printf("����\n");
		return 0;
	} else if (IsStackFull(*s1) && IsStackEmpty(*s2)) {
		int temp;
		while (!IsStackEmpty(*s1)) {
			Pop(s1, &temp);
			Push(s2, temp);
		}
	}
	Push(s1, x);
	return 1;
}

/**
 * @brief ��Ԫ�س���
 * @param s1 ������ջ������ջ
 * @param s2 ���ڳ�ջ������ջ
 * @param x ָ�򱣴����Ԫ�ص�ָ��
 */
void Dequeue(Stack *s1, Stack *s2, int *x) {
	if (!IsStackEmpty(*s2)) {
		Pop(s2, x);
	} else if (IsStackEmpty(*s1)) {
		printf("�ӿ�\n");
	} else {
		int temp;
		while (!IsStackEmpty(*s1)) {
			Pop(s1, &temp);
			Push(s2, temp);
		}
		Pop(s2, x);
	}
}

/**
 * @brief �ж϶����Ƿ�Ϊ��
 * @param s1 ��ջ������ջ
 * @param s2 ��ջ������ջ
 * @return true ���Ϊ�գ����� false
 */
bool IsQueueEmpty(Stack s1, Stack s2) {
	return IsStackEmpty(s1) && IsStackEmpty(s2);
}

int main() {
	Stack s1, s2;
	s1.top = -1;
	s2.top = -1;

	// ��0��9��10��Ԫ����ջ1
	for (int i = 0; i < Max; i++) {
		Push(&s1, i);
	}

	// ��ʾջ1�е�Ԫ��
	printf("s1:\n");
	DisplayStack(s1);

	// ִ�г��Ӳ���
	int x = 0;
	Dequeue(&s1, &s2, &x);
	printf("����Ԫ��Ϊ: %d\n", x);

	// ��ʾջ2�е�Ԫ��
	printf("s2:\n");
	DisplayStack(s2);

	return 0;
}

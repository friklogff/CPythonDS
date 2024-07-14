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
bool IsEmpty(Stack s) {
	return s.top == -1;
}

/**
 * @brief �ж�ջ�Ƿ�����
 * @param s ջ
 * @return true ������������� false
 */
bool IsFull(Stack s) {
	return s.top == Max - 1;
}

/**
 * @brief ��Ԫ�� x ��ջ
 * @param s ջָ��
 * @param x Ҫ��ջ��Ԫ��
 * @return true ��ʾ�����ɹ���false ��ʾ����ʧ��
 */
bool Push(Stack *s, int x) {
	if (IsFull(*s))
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
	if (IsEmpty(*s)) {
		printf("ջ��\n");
		return 0;
	}
	*x = s->data[s->top--];
	return 1;
}

/**
 * @brief ��ʾջ�е�Ԫ��
 * @param s ջָ��
 */
void DisplayStack(Stack *s) {
	int tempTop = s->top;
	while (tempTop != -1) {
		printf("%d ", s->data[tempTop]);
		tempTop--;
	}
	printf("\n");
}

/**
 * @brief ��Ԫ�� x ���
 * @param stack1 ������ջ������ջ
 * @param stack2 ���ڳ�ջ������ջ
 * @param x Ҫ��ӵ�Ԫ��
 * @return 1 ��ʾ�����ɹ���0 ��ʾ����ʧ��
 */
int Enqueue(Stack *stack1, Stack *stack2, int x) {
	if (!IsFull(*stack1)) {
		Push(stack1, x);
		return 1;
	} else if (IsFull(*stack1) && !IsEmpty(*stack2)) {
		printf("����\n");
		return 0;
	} else if (IsFull(*stack1) && IsEmpty(*stack2)) {
		int temp;
		while (!IsEmpty(*stack1)) {
			Pop(stack1, &temp);
			Push(stack2, temp);
		}
	}
	Push(stack1, x);
	return 1;
}

/**
 * @brief ��Ԫ�س���
 * @param stack1 ������ջ������ջ
 * @param stack2 ���ڳ�ջ������ջ
 * @param x ָ�򱣴����Ԫ�ص�ָ��
 */
void Dequeue(Stack *stack1, Stack *stack2, int *x) {
	if (!IsEmpty(*stack2)) {
		Pop(stack2, x);
	} else if (IsEmpty(*stack1)) {
		printf("ջ��\n");
	} else {
		int temp;
		while (!IsEmpty(*stack1)) {
			Pop(stack1, &temp);
			Push(stack2, temp);
		}
		Pop(stack2, x);
	}
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
	printf("s1: ");
	DisplayStack(&s1);

	// ִ�г��Ӳ���
	int x = 0;
	Dequeue(&s1, &s2, &x);
	printf("���ӵ�Ԫ�� x = %d\n", x);

	// ��ʾջ2�е�Ԫ��
	printf("s2: ");
	DisplayStack(&s2);

	return 0;
}

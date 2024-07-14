#include <iostream>
#include <cstdlib>
#include <stdbool.h>

#define MAXSIZE 100  // ջ���������

typedef int ElemType;

// ջ�Ľṹ�嶨��
typedef struct {
	ElemType data[MAXSIZE];
	int top;
} SqStack;

// ��ʼ��ջ
void InitStack(SqStack &S) {
	S.top = -1;
}

// ����ջ
void DestroyStack(SqStack &S) {
	S.top = -1;
}

// �ж�ջ�Ƿ�Ϊ��
bool StackEmpty(SqStack S) {
	return S.top == -1;
}

// ��ջ
bool Push(SqStack &S, ElemType x) {
	if (S.top == MAXSIZE - 1) {
		std::cout << "ջ�����޷���ջ" << std::endl;
		return false;
	}
	S.data[++S.top] = x;
	return true;
}

// ��ջ
bool Pop(SqStack &S, ElemType &x) {
	if (StackEmpty(S)) {
		std::cout << "ջ�գ��޷���ջ" << std::endl;
		return false;
	}
	x = S.data[S.top--];
	return true;
}

// ��ջ��Ԫ��
bool GetTop(SqStack S, ElemType &x) {
	if (StackEmpty(S)) {
		std::cout << "ջ�գ��޷���ȡջ��" << std::endl;
		return false;
	}
	x = S.data[S.top];
	return true;
}

int main() {
	SqStack S;
	InitStack(S);

	Push(S, 10);
	Push(S, 20);

	ElemType x;
	if (GetTop(S, x))
		std::cout << "ջ��Ԫ��: " << x << std::endl;

	if (Pop(S, x))
		std::cout << "��ջԪ��: " << x << std::endl;

	if (Pop(S, x))
		std::cout << "��ջԪ��: " << x << std::endl;

	if (StackEmpty(S)) {
		std::cout << "ջΪ��" << std::endl;
	}

	DestroyStack(S);
	return 0;
}

#include <iostream>
#define MaxSize 10

typedef int ElemType;

// ���干��ջ�ṹ��
typedef struct {
	ElemType data[MaxSize]; // ��̬������ջ��Ԫ��
	int top0; // 0��ջջ��ָ��
	int top1; // 1��ջջ��ָ��
} ShStack;

// ��ʼ��ջ
void InitStack(ShStack &S) {
	S.top0 = -1; // ��ʼ��0��ջջ��ָ��
	S.top1 = MaxSize; // ��ʼ��1��ջջ��ָ��
}

// 0��ջ��ջ����
bool Push0(ShStack &S, ElemType e) {
	if (S.top0 + 1 == S.top1) {
		std::cout << "Stack Overflow" << std::endl;
		return false; // ջ��
	}
	S.data[++S.top0] = e;
	return true;
}

// 1��ջ��ջ����
bool Push1(ShStack &S, ElemType e) {
	if (S.top0 + 1 == S.top1) {
		std::cout << "Stack Overflow" << std::endl;
		return false; // ջ��
	}
	S.data[--S.top1] = e;
	return true;
}

// 0��ջ��ջ����
bool Pop0(ShStack &S, ElemType &e) {
	if (S.top0 == -1) {
		std::cout << "Stack Underflow" << std::endl;
		return false; // ջ��
	}
	e = S.data[S.top0--];
	return true;
}

// 1��ջ��ջ����
bool Pop1(ShStack &S, ElemType &e) {
	if (S.top1 == MaxSize) {
		std::cout << "Stack Underflow" << std::endl;
		return false; // ջ��
	}
	e = S.data[S.top1++];
	return true;
}

int main() {
	ShStack S;
	InitStack(S);

	// ����һЩ����
	Push0(S, 1);
	Push0(S, 2);
	Push1(S, 9);
	Push1(S, 8);

	ElemType e;
	Pop0(S, e);
	std::cout << "Popped from 0 stack: " << e << std::endl;
	Pop1(S, e);
	std::cout << "Popped from 1 stack: " << e << std::endl;

	return 0;
}

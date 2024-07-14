#include <iostream>
#include <cstdlib>
#include <stdbool.h>

typedef int ElemType;

typedef struct LinkNode {
	ElemType data;             // ������
	struct LinkNode *next;     // ָ����
} *LiStack;

// ��ʼ��ջ
void InitStack(LiStack &S) {
	S = nullptr;
}

// ����ջ
void DestroyStack(LiStack &S) {
	LiStack p;
	while (S != nullptr) {
		p = S;
		S = S->next;
		free(p);
	}
}

// �ж�ջ�Ƿ�Ϊ��
bool StackEmpty(LiStack S) {
	return S == nullptr;
}

// ��ջ
bool Push(LiStack &S, ElemType x) {
	LiStack p = (LiStack)malloc(sizeof(LinkNode));
	if (p == nullptr) {
		std::cerr << "�ڴ����ʧ��" << std::endl;
		return false;
	}
	p->data = x;
	p->next = S;
	S = p;
	return true;
}

// ��ջ
bool Pop(LiStack &S, ElemType &x) {
	if (StackEmpty(S)) {
		std::cerr << "ջ�գ��޷���ջ" << std::endl;
		return false;
	}
	LiStack p = S;
	x = p->data;
	S = S->next;
	free(p);
	return true;
}

// ��ջ��Ԫ��
bool GetTop(LiStack S, ElemType &x) {
	if (StackEmpty(S)) {
		std::cerr << "ջ�գ��޷���ȡջ��" << std::endl;
		return false;
	}
	x = S->data;
	return true;
}

int main() {
	LiStack S;
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

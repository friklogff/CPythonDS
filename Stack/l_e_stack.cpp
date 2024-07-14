#include <iostream>
#include <cstdlib>
#include <stdbool.h>

typedef int ElemType;

typedef struct LinkNode {
	ElemType data;             // 数据域
	struct LinkNode *next;     // 指针域
} *LiStack;

// 初始化栈
void InitStack(LiStack &S) {
	S = nullptr;
}

// 销毁栈
void DestroyStack(LiStack &S) {
	LiStack p;
	while (S != nullptr) {
		p = S;
		S = S->next;
		free(p);
	}
}

// 判断栈是否为空
bool StackEmpty(LiStack S) {
	return S == nullptr;
}

// 进栈
bool Push(LiStack &S, ElemType x) {
	LiStack p = (LiStack)malloc(sizeof(LinkNode));
	if (p == nullptr) {
		std::cerr << "内存分配失败" << std::endl;
		return false;
	}
	p->data = x;
	p->next = S;
	S = p;
	return true;
}

// 出栈
bool Pop(LiStack &S, ElemType &x) {
	if (StackEmpty(S)) {
		std::cerr << "栈空，无法出栈" << std::endl;
		return false;
	}
	LiStack p = S;
	x = p->data;
	S = S->next;
	free(p);
	return true;
}

// 读栈顶元素
bool GetTop(LiStack S, ElemType &x) {
	if (StackEmpty(S)) {
		std::cerr << "栈空，无法读取栈顶" << std::endl;
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
		std::cout << "栈顶元素: " << x << std::endl;
	if (Pop(S, x))
		std::cout << "出栈元素: " << x << std::endl;
	if (Pop(S, x))
		std::cout << "出栈元素: " << x << std::endl;

	if (StackEmpty(S)) {
		std::cout << "栈为空" << std::endl;
	}

	DestroyStack(S);
	return 0;
}

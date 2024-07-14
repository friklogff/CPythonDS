#include <iostream>
#include <cstdlib>
#include <stdbool.h>

#define MAXSIZE 100  // 栈的最大容量

typedef int ElemType;

// 栈的结构体定义
typedef struct {
	ElemType data[MAXSIZE];
	int top;
} SqStack;

// 初始化栈
void InitStack(SqStack &S) {
	S.top = -1;
}

// 销毁栈
void DestroyStack(SqStack &S) {
	S.top = -1;
}

// 判断栈是否为空
bool StackEmpty(SqStack S) {
	return S.top == -1;
}

// 进栈
bool Push(SqStack &S, ElemType x) {
	if (S.top == MAXSIZE - 1) {
		std::cout << "栈满，无法进栈" << std::endl;
		return false;
	}
	S.data[++S.top] = x;
	return true;
}

// 出栈
bool Pop(SqStack &S, ElemType &x) {
	if (StackEmpty(S)) {
		std::cout << "栈空，无法出栈" << std::endl;
		return false;
	}
	x = S.data[S.top--];
	return true;
}

// 读栈顶元素
bool GetTop(SqStack S, ElemType &x) {
	if (StackEmpty(S)) {
		std::cout << "栈空，无法读取栈顶" << std::endl;
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

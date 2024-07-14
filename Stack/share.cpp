#include <iostream>
#define MaxSize 10

typedef int ElemType;

// 定义共享栈结构体
typedef struct {
	ElemType data[MaxSize]; // 静态数组存放栈中元素
	int top0; // 0号栈栈顶指针
	int top1; // 1号栈栈顶指针
} ShStack;

// 初始化栈
void InitStack(ShStack &S) {
	S.top0 = -1; // 初始化0号栈栈顶指针
	S.top1 = MaxSize; // 初始化1号栈栈顶指针
}

// 0号栈入栈操作
bool Push0(ShStack &S, ElemType e) {
	if (S.top0 + 1 == S.top1) {
		std::cout << "Stack Overflow" << std::endl;
		return false; // 栈满
	}
	S.data[++S.top0] = e;
	return true;
}

// 1号栈入栈操作
bool Push1(ShStack &S, ElemType e) {
	if (S.top0 + 1 == S.top1) {
		std::cout << "Stack Overflow" << std::endl;
		return false; // 栈满
	}
	S.data[--S.top1] = e;
	return true;
}

// 0号栈出栈操作
bool Pop0(ShStack &S, ElemType &e) {
	if (S.top0 == -1) {
		std::cout << "Stack Underflow" << std::endl;
		return false; // 栈空
	}
	e = S.data[S.top0--];
	return true;
}

// 1号栈出栈操作
bool Pop1(ShStack &S, ElemType &e) {
	if (S.top1 == MaxSize) {
		std::cout << "Stack Underflow" << std::endl;
		return false; // 栈空
	}
	e = S.data[S.top1++];
	return true;
}

int main() {
	ShStack S;
	InitStack(S);

	// 进行一些测试
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

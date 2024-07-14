#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Max 50 // 栈的最大容量

// 定义共享空间的双栈结构体
typedef struct {
	int data[Max]; // 数据域
	int top[2];    // 两个栈的栈顶指针
} Stack;

// 全局变量定义
Stack s; // 定义一个共享空间的双栈

/**
 * @brief 将元素 x 压入第i个栈中
 * @param i 栈的编号（0或1）
 * @param x 要压入的元素
 * @return 1 表示操作成功，-1 表示操作失败
 */
int Push(int i, int x) {
	if (i != 0 && i != 1) { // 如果栈编号不为0或1
		printf("无效栈编号\n");
		return -1;
	}
	if (s.top[1] - s.top[0] == 1) { // 如果栈已满
		printf("栈已满\n");
		return -1;
	}
	// 根据栈编号压入相应栈中
	if (i == 0)
		s.data[++s.top[0]] = x; // 0号栈，栈顶指针上移后压入元素
	else
		s.data[--s.top[1]] = x; // 1号栈，栈顶指针下移后压入元素
	return 1;
}

/**
 * @brief 从第i个栈中弹出元素
 * @param i 栈的编号（0或1）
 * @return 弹出的元素或-1表示操作失败
 */
int Pop(int i) {
	if (i != 0 && i != 1) { // 如果栈编号不为0或1
		printf("无效栈编号\n");
		return -1;
	}
	if (i == 0) {
		if (s.top[0] == -1) { // 0号栈为空
			printf("0号栈为空\n");
			return -1;
		}
		return s.data[s.top[0]--]; // 0号栈，弹出元素并栈顶指针下移
	} else {
		if (s.top[1] == Max) { // 1号栈为空
			printf("1号栈为空\n");
			return -1;
		}
		return s.data[s.top[1]++]; // 1号栈，弹出元素并栈顶指针上移
	}
}

int main() {
	// 初始化栈顶指针
	s.top[0] = -1;
	s.top[1] = Max;

	// 测试 0号栈的压栈操作
	if (Push(0, 1) != -1)
		printf("0号栈压栈成功\n");

	// 测试 0号栈的弹栈操作
	int x = Pop(0);
	if (x != -1) {
		printf("0号栈弹栈成功  ");
		printf("0号栈弹栈元素为: %d\n", x);
	}

	// 再次尝试弹栈操作，应该输出 0号栈为空
	int y = Pop(0);

	return 0;
}

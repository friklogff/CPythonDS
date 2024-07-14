#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Max 10 // 栈和队列的最大容量

// 定义栈结构体
typedef struct {
	int data[Max]; // 数据域
	int top;       // 栈顶指针
} Stack;

/**
 * @brief 判断栈是否为空
 * @param s 栈
 * @return true 如果为空，否则 false
 */
bool IsStackEmpty(Stack s) {
	return s.top == -1;
}

/**
 * @brief 判断栈是否已满
 * @param s 栈
 * @return true 如果已满，否则 false
 */
bool IsStackFull(Stack s) {
	return s.top == Max - 1;
}

/**
 * @brief 将元素 x 进栈
 * @param s 栈指针
 * @param x 要进栈的元素
 * @return true 表示操作成功，false 表示操作失败
 */
bool Push(Stack *s, int x) {
	if (IsStackFull(*s))
		return false;
	s->data[++s->top] = x;
	return true;
}

/**
 * @brief 从栈中出栈一个元素
 * @param s 栈指针
 * @param x 指向保存出栈元素的指针
 * @return 1 表示操作成功，0 表示操作失败
 */
int Pop(Stack *s, int *x) {
	if (IsStackEmpty(*s)) {
		printf("栈空\n");
		return 0;
	}
	*x = s->data[s->top--];
	return 1;
}

/**
 * @brief 显示栈中的元素
 * @param s 栈
 */
void DisplayStack(Stack s) {
	int tempTop = s.top;
	while (tempTop != -1) {
		printf("%d ", s.data[tempTop--]);
	}
	printf("\n");
}

/**
 * @brief 将元素 x 入队
 * @param s1 用于入栈操作的栈
 * @param s2 用于出栈操作的栈
 * @param x 要入队的元素
 * @return 1 表示操作成功，0 表示操作失败
 */
int Enqueue(Stack *s1, Stack *s2, int x) {
	if (!IsStackFull(*s1)) {
		Push(s1, x);
		return 1;
	} else if (IsStackFull(*s1) && !IsStackEmpty(*s2)) {
		printf("队满\n");
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
 * @brief 将元素出队
 * @param s1 用于入栈操作的栈
 * @param s2 用于出栈操作的栈
 * @param x 指向保存出队元素的指针
 */
void Dequeue(Stack *s1, Stack *s2, int *x) {
	if (!IsStackEmpty(*s2)) {
		Pop(s2, x);
	} else if (IsStackEmpty(*s1)) {
		printf("队空\n");
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
 * @brief 判断队列是否为空
 * @param s1 入栈操作的栈
 * @param s2 出栈操作的栈
 * @return true 如果为空，否则 false
 */
bool IsQueueEmpty(Stack s1, Stack s2) {
	return IsStackEmpty(s1) && IsStackEmpty(s2);
}

int main() {
	Stack s1, s2;
	s1.top = -1;
	s2.top = -1;

	// 将0到9共10个元素入栈1
	for (int i = 0; i < Max; i++) {
		Push(&s1, i);
	}

	// 显示栈1中的元素
	printf("s1:\n");
	DisplayStack(s1);

	// 执行出队操作
	int x = 0;
	Dequeue(&s1, &s2, &x);
	printf("出队元素为: %d\n", x);

	// 显示栈2中的元素
	printf("s2:\n");
	DisplayStack(s2);

	return 0;
}

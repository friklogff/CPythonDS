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
bool IsEmpty(Stack s) {
	return s.top == -1;
}

/**
 * @brief 判断栈是否已满
 * @param s 栈
 * @return true 如果已满，否则 false
 */
bool IsFull(Stack s) {
	return s.top == Max - 1;
}

/**
 * @brief 将元素 x 进栈
 * @param s 栈指针
 * @param x 要进栈的元素
 * @return true 表示操作成功，false 表示操作失败
 */
bool Push(Stack *s, int x) {
	if (IsFull(*s))
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
	if (IsEmpty(*s)) {
		printf("栈空\n");
		return 0;
	}
	*x = s->data[s->top--];
	return 1;
}

/**
 * @brief 显示栈中的元素
 * @param s 栈指针
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
 * @brief 将元素 x 入队
 * @param stack1 用于入栈操作的栈
 * @param stack2 用于出栈操作的栈
 * @param x 要入队的元素
 * @return 1 表示操作成功，0 表示操作失败
 */
int Enqueue(Stack *stack1, Stack *stack2, int x) {
	if (!IsFull(*stack1)) {
		Push(stack1, x);
		return 1;
	} else if (IsFull(*stack1) && !IsEmpty(*stack2)) {
		printf("队满\n");
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
 * @brief 将元素出队
 * @param stack1 用于入栈操作的栈
 * @param stack2 用于出栈操作的栈
 * @param x 指向保存出队元素的指针
 */
void Dequeue(Stack *stack1, Stack *stack2, int *x) {
	if (!IsEmpty(*stack2)) {
		Pop(stack2, x);
	} else if (IsEmpty(*stack1)) {
		printf("栈空\n");
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

	// 将0到9共10个元素入栈1
	for (int i = 0; i < Max; i++) {
		Push(&s1, i);
	}
	// 显示栈1中的元素
	printf("s1: ");
	DisplayStack(&s1);

	// 执行出队操作
	int x = 0;
	Dequeue(&s1, &s2, &x);
	printf("出队的元素 x = %d\n", x);

	// 显示栈2中的元素
	printf("s2: ");
	DisplayStack(&s2);

	return 0;
}

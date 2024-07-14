#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Max 10 // 队列和栈的最大容量

// 定义栈结构体
typedef struct {
	int data[Max]; // 数据域
	int top;       // 栈顶指针
} Stack;

// 定义循环队列结构体
typedef struct {
	int data[Max]; // 数据域
	int front, rear; // 队头和队尾指针
	int tag;        // 标识队列状态（满或空）
} SQueue;

/**
 * @brief 将元素 x 入队
 * @param queue 队列指针
 * @param x 要入队的元素
 * @return true 表示操作成功，false 表示操作失败
 */
bool Enqueue(SQueue *queue, int x) {
	if (queue->front == queue->rear && queue->tag == 1) { // 判断队列是否已满
		printf("队满 进队失败\n");
		return false;
	}
	queue->data[queue->rear] = x; // 将元素入队
	queue->rear = (queue->rear + 1) % Max; // 更新队尾指针
	queue->tag = 1; // 修改标签为1，表示队列状态
	return true;
}

/**
 * @brief 从队列中出队一个元素
 * @param queue 队列指针
 * @param x 指向保存出队元素的指针
 * @return 1 表示操作成功，0 表示操作失败
 */
int Dequeue(SQueue *queue, int *x) {
	if (queue->front == queue->rear && queue->tag == 0) { // 判断队列是否为空
		printf("队空 出队失败\n");
		return 0;
	}
	*x = queue->data[queue->front]; // 从队头出队元素
	queue->front = (queue->front + 1) % Max; // 更新队头指针
	queue->tag = 0; // 修改标签为0，表示队列状态
	return 1;
}

/**
 * @brief 将元素 x 进栈
 * @param stack 栈指针
 * @param x 要进栈的元素
 * @return true 表示操作成功，false 表示操作失败
 */
bool Push(Stack *stack, int x) {
	if (stack->top == Max - 1) { // 判断栈是否已满
		printf("栈满 进栈失败\n");
		return false;
	}
	stack->data[++stack->top] = x; // 将元素进栈
	return true;
}

/**
 * @brief 从栈中出栈一个元素
 * @param stack 栈指针
 * @param x 指向保存出栈元素的指针
 * @return 1 表示操作成功，0 表示操作失败
 */
int Pop(Stack *stack, int *x) {
	if (stack->top == -1) { // 判断栈是否为空
		printf("栈空 出栈失败\n");
		return 0;
	}
	*x = stack->data[stack->top--]; // 从栈顶出栈元素
	return 1;
}

/**
 * @brief 显示队列中的元素
 * @param queue 队列
 */
void DisplayQueue(SQueue queue) {
	for (int i = 0; i < Max; i++) {
		printf("%d ", queue.data[queue.front]);
		queue.front = (queue.front + 1) % Max;
	}
	printf("\n");
}

int main() {
	SQueue queue;
	Stack stack;
	queue.front = 0, queue.rear = 0, queue.tag = 0; // 初始化队列
	stack.top = -1; // 初始化栈

	// 将0到9共10个元素入队
	for (int i = 0; i < Max; i++) {
		Enqueue(&queue, i);
	}
	// 显示队列中的元素
	printf("初始队列: ");
	DisplayQueue(queue);

	int x = 0;
	// 将队列中的元素依次出队，并压入栈中
	while (!(queue.front == queue.rear && queue.tag == 0)) {
		Dequeue(&queue, &x);
		Push(&stack, x);
	}
	// 将栈中的元素依次出栈，再次入队
	while (stack.top != -1) {
		Pop(&stack, &x);
		Enqueue(&queue, x);
	}
	// 显示队列经过逆序后的元素
	printf("逆序后的队列: ");
	DisplayQueue(queue);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Max 10 // 队列的最大容量

// 定义循环队列结构体
typedef struct {
	int data[Max]; // 数据域
	int front, rear; // 队头和队尾指针
	int tag; // 标识队列状态（满或空）
} SQueue;

/**
 * @brief 将元素 x 入队
 * @param queue 队列指针
 * @param x 要入队的元素
 * @return true 表示操作成功，false 表示操作失败
 */
bool Enqueue(SQueue *queue, int x) {
	// 判断队列是否已满，满则返回 false
	if (queue->front == queue->rear && queue->tag == 1) {
		printf("队满 进队失败\n");
		return false;
	}
	// 队尾指针位置插入元素并后移
	queue->data[queue->rear] = x;
	printf("%d ", queue->data[queue->rear]);
	queue->rear = (queue->rear + 1) % Max;
	queue->tag = 1; // 修改标签为 1，表示队列状态
	return true;
}

/**
 * @brief 将元素出队
 * @param queue 队列指针
 * @param x 指向保存出队元素的指针
 * @return 1 表示操作成功，0 表示操作失败
 */
int Dequeue(SQueue *queue, int *x) {
	// 判断队列是否为空，空则返回 0
	if (queue->front == queue->rear && queue->tag == 0) {
		printf("队空 出队失败\n");
		return 0;
	}
	// 队头指针位置出队并后移
	*x = queue->data[queue->front];
	queue->front = (queue->front + 1) % Max;
	queue->tag = 0; // 修改标签为 0，表示队列状态
	return 1;
}

int main() {
	SQueue queue;
	queue.front = 0;
	queue.rear = 0;
	queue.tag = 0;

	// 测试入队操作
	for (int i = 0; i < 10; i++) {
		Enqueue(&queue, i);
	}
	printf("\n");

	// 测试队满情况
	Enqueue(&queue, 1);

	// 测试出队操作
	int x = 0;
	for (int i = 0; i < 10; i++) {
		Dequeue(&queue, &x);
	}

	// 测试队空情况
	Dequeue(&queue, &x);

	return 0;
}

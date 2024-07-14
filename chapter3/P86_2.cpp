#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Max 10 // ���к�ջ���������

// ����ջ�ṹ��
typedef struct {
	int data[Max]; // ������
	int top;       // ջ��ָ��
} Stack;

// ����ѭ�����нṹ��
typedef struct {
	int data[Max]; // ������
	int front, rear; // ��ͷ�Ͷ�βָ��
	int tag;        // ��ʶ����״̬������գ�
} SQueue;

/**
 * @brief ��Ԫ�� x ���
 * @param queue ����ָ��
 * @param x Ҫ��ӵ�Ԫ��
 * @return true ��ʾ�����ɹ���false ��ʾ����ʧ��
 */
bool Enqueue(SQueue *queue, int x) {
	if (queue->front == queue->rear && queue->tag == 1) { // �ж϶����Ƿ�����
		printf("���� ����ʧ��\n");
		return false;
	}
	queue->data[queue->rear] = x; // ��Ԫ�����
	queue->rear = (queue->rear + 1) % Max; // ���¶�βָ��
	queue->tag = 1; // �޸ı�ǩΪ1����ʾ����״̬
	return true;
}

/**
 * @brief �Ӷ����г���һ��Ԫ��
 * @param queue ����ָ��
 * @param x ָ�򱣴����Ԫ�ص�ָ��
 * @return 1 ��ʾ�����ɹ���0 ��ʾ����ʧ��
 */
int Dequeue(SQueue *queue, int *x) {
	if (queue->front == queue->rear && queue->tag == 0) { // �ж϶����Ƿ�Ϊ��
		printf("�ӿ� ����ʧ��\n");
		return 0;
	}
	*x = queue->data[queue->front]; // �Ӷ�ͷ����Ԫ��
	queue->front = (queue->front + 1) % Max; // ���¶�ͷָ��
	queue->tag = 0; // �޸ı�ǩΪ0����ʾ����״̬
	return 1;
}

/**
 * @brief ��Ԫ�� x ��ջ
 * @param stack ջָ��
 * @param x Ҫ��ջ��Ԫ��
 * @return true ��ʾ�����ɹ���false ��ʾ����ʧ��
 */
bool Push(Stack *stack, int x) {
	if (stack->top == Max - 1) { // �ж�ջ�Ƿ�����
		printf("ջ�� ��ջʧ��\n");
		return false;
	}
	stack->data[++stack->top] = x; // ��Ԫ�ؽ�ջ
	return true;
}

/**
 * @brief ��ջ�г�ջһ��Ԫ��
 * @param stack ջָ��
 * @param x ָ�򱣴��ջԪ�ص�ָ��
 * @return 1 ��ʾ�����ɹ���0 ��ʾ����ʧ��
 */
int Pop(Stack *stack, int *x) {
	if (stack->top == -1) { // �ж�ջ�Ƿ�Ϊ��
		printf("ջ�� ��ջʧ��\n");
		return 0;
	}
	*x = stack->data[stack->top--]; // ��ջ����ջԪ��
	return 1;
}

/**
 * @brief ��ʾ�����е�Ԫ��
 * @param queue ����
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
	queue.front = 0, queue.rear = 0, queue.tag = 0; // ��ʼ������
	stack.top = -1; // ��ʼ��ջ

	// ��0��9��10��Ԫ�����
	for (int i = 0; i < Max; i++) {
		Enqueue(&queue, i);
	}
	// ��ʾ�����е�Ԫ��
	printf("��ʼ����: ");
	DisplayQueue(queue);

	int x = 0;
	// �������е�Ԫ�����γ��ӣ���ѹ��ջ��
	while (!(queue.front == queue.rear && queue.tag == 0)) {
		Dequeue(&queue, &x);
		Push(&stack, x);
	}
	// ��ջ�е�Ԫ�����γ�ջ���ٴ����
	while (stack.top != -1) {
		Pop(&stack, &x);
		Enqueue(&queue, x);
	}
	// ��ʾ���о���������Ԫ��
	printf("�����Ķ���: ");
	DisplayQueue(queue);
	return 0;
}

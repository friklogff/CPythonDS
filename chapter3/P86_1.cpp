#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Max 10 // ���е��������

// ����ѭ�����нṹ��
typedef struct {
	int data[Max]; // ������
	int front, rear; // ��ͷ�Ͷ�βָ��
	int tag; // ��ʶ����״̬������գ�
} SQueue;

/**
 * @brief ��Ԫ�� x ���
 * @param queue ����ָ��
 * @param x Ҫ��ӵ�Ԫ��
 * @return true ��ʾ�����ɹ���false ��ʾ����ʧ��
 */
bool Enqueue(SQueue *queue, int x) {
	// �ж϶����Ƿ����������򷵻� false
	if (queue->front == queue->rear && queue->tag == 1) {
		printf("���� ����ʧ��\n");
		return false;
	}
	// ��βָ��λ�ò���Ԫ�ز�����
	queue->data[queue->rear] = x;
	printf("%d ", queue->data[queue->rear]);
	queue->rear = (queue->rear + 1) % Max;
	queue->tag = 1; // �޸ı�ǩΪ 1����ʾ����״̬
	return true;
}

/**
 * @brief ��Ԫ�س���
 * @param queue ����ָ��
 * @param x ָ�򱣴����Ԫ�ص�ָ��
 * @return 1 ��ʾ�����ɹ���0 ��ʾ����ʧ��
 */
int Dequeue(SQueue *queue, int *x) {
	// �ж϶����Ƿ�Ϊ�գ����򷵻� 0
	if (queue->front == queue->rear && queue->tag == 0) {
		printf("�ӿ� ����ʧ��\n");
		return 0;
	}
	// ��ͷָ��λ�ó��Ӳ�����
	*x = queue->data[queue->front];
	queue->front = (queue->front + 1) % Max;
	queue->tag = 0; // �޸ı�ǩΪ 0����ʾ����״̬
	return 1;
}

int main() {
	SQueue queue;
	queue.front = 0;
	queue.rear = 0;
	queue.tag = 0;

	// ������Ӳ���
	for (int i = 0; i < 10; i++) {
		Enqueue(&queue, i);
	}
	printf("\n");

	// ���Զ������
	Enqueue(&queue, 1);

	// ���Գ��Ӳ���
	int x = 0;
	for (int i = 0; i < 10; i++) {
		Dequeue(&queue, &x);
	}

	// ���Զӿ����
	Dequeue(&queue, &x);

	return 0;
}

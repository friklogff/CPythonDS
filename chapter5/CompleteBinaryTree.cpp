#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// ���н�㶨��
typedef struct QueueNode {
	struct BiTNode *data;
	struct QueueNode *next;
} QueueNode;

// ���ж���
typedef struct {
	QueueNode *front;
	QueueNode *rear;
} Queue;

// ��������㶨��
typedef struct BiTNode {
	int data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// ��ʼ������
void initQueue(Queue *Q) {
	Q->front = Q->rear = (QueueNode *)malloc(sizeof(QueueNode));
	Q->front->next = NULL;
}

// �ж϶����Ƿ�Ϊ��
bool isEmpty(Queue Q) {
	return Q.front == Q.rear;
}

// ��Ӳ���
void enQueue(Queue *Q, BiTNode *x) {
	QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
	newNode->data = x;
	newNode->next = NULL;
	Q->rear->next = newNode;
	Q->rear = newNode;
}

// ���Ӳ���
void deQueue(Queue *Q, BiTNode **x) {
	if (isEmpty(*Q))
		return;
	QueueNode *temp = Q->front->next;
	*x = temp->data;
	Q->front->next = temp->next;
	if (Q->rear == temp)
		Q->rear = Q->front;
	free(temp);
}

// �ж϶������Ƿ�Ϊ��ȫ������
bool isComplete(BiTree T) {
	if (T == NULL)
		return true;
	Queue Q;
	initQueue(&Q);
	enQueue(&Q, T);
	bool flag = false; // ���ڱ���Ƿ�������Ҷ�ӽڵ��ֻ�����ӵĽڵ�

	while (!isEmpty(Q)) {
		BiTNode *p;
		deQueue(&Q, &p);
		if (p->lchild != NULL) {
			if (flag)
				return false; // ����Ѿ�������Ҷ�ӽڵ��ֻ�����ӵĽڵ㣬������ȫ������
			enQueue(&Q, p->lchild);
		} else {
			flag = true; // ����Ҷ�ӽڵ��ֻ�����ӵĽڵ�
		}
		if (p->rchild != NULL) {
			if (flag)
				return false; // ����Ѿ�������Ҷ�ӽڵ��ֻ�����ӵĽڵ㣬������ȫ������
			enQueue(&Q, p->rchild);
		} else {
			flag = true; // ����Ҷ�ӽڵ��ֻ�����ӵĽڵ�
		}
	}
	return true;
}

// ʾ��ʹ��
int main() {
	// ����һ��������ʾ��
	BiTree root = (BiTree)malloc(sizeof(BiTNode));
	root->data = 1;
	root->lchild = (BiTree)malloc(sizeof(BiTNode));
	root->lchild->data = 2;
	root->rchild = (BiTree)malloc(sizeof(BiTNode));
	root->rchild->data = 3;
	root->lchild->lchild = NULL;
	root->lchild->rchild = NULL;
	root->rchild->lchild = NULL;
	root->rchild->rchild = NULL;

	// �ж��Ƿ�Ϊ��ȫ������
	if (isComplete(root)) {
		printf("The binary tree is a complete binary tree.\n");

	} else {
		printf("The binary tree is not a complete binary tree.\n");
	}

	// �ͷ��ڴ�
	free(root->lchild);
	free(root->rchild);
	free(root);

	return 0;
}

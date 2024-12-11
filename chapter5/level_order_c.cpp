#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode {
	int data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// 队列结构体
typedef struct QueueNode {
	BiTree data;
	struct QueueNode *next;
} QueueNode;

typedef struct Queue {
	QueueNode *front, *rear;
} Queue;

void lnitQueue(Queue *Q) {
	Q->front = Q->rear = NULL;
}

void EnQueue(Queue *Q, BiTree x) {
	QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
	newNode->data = x;
	newNode->next = NULL;

	if (Q->rear == NULL) {
		Q->front = Q->rear = newNode;
	} else {
		Q->rear->next = newNode;
		Q->rear = newNode;
	}
}

void DeQueue(Queue *Q) {
	if (Q->front == NULL) {
		return;
	}

	QueueNode *temp = Q->front;
	Q->front = Q->front->next;

	if (Q->front == NULL) {
		Q->rear = NULL;
	}

	free(temp);
}

int isEmpty(Queue Q) {
	return Q.front == NULL;
}

BiTree getFront(Queue *Q) {
	if (Q->front != NULL) {
		return Q->front->data;
	}
	return NULL;
}

void LevelOrder(BiTree T) {
	Queue Q;
	lnitQueue(&Q);
	EnQueue(&Q, T);

	while (!isEmpty(Q)) {
		BiTree p = getFront(&Q);
		DeQueue(&Q);

		printf("%d ", p->data);

		if (p->lchild != NULL) {
			EnQueue(&Q, p->lchild);
		}
		if (p->rchild != NULL) {
			EnQueue(&Q, p->rchild);
		}
	}
}

int main() {
	BiTNode n1, n2, n3, n4, n5;
	n1.data = 1;
	n2.data = 2;
	n3.data = 3;
	n4.data = 4;
	n5.data = 5;
	n1.lchild = &n2;
	n1.rchild = &n3;
	n2.lchild = &n4;
	n2.rchild = &n5;
	n3.lchild = n3.rchild = n4.lchild = n4.rchild = n5.lchild = n5.rchild = NULL;

	BiTree T = &n1;

	printf("Level Order Traversal: ");
	LevelOrder(T);

	return 0;
}

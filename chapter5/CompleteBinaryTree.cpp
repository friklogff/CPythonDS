#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 队列结点定义
typedef struct QueueNode {
	struct BiTNode *data;
	struct QueueNode *next;
} QueueNode;

// 队列定义
typedef struct {
	QueueNode *front;
	QueueNode *rear;
} Queue;

// 二叉树结点定义
typedef struct BiTNode {
	int data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// 初始化队列
void initQueue(Queue *Q) {
	Q->front = Q->rear = (QueueNode *)malloc(sizeof(QueueNode));
	Q->front->next = NULL;
}

// 判断队列是否为空
bool isEmpty(Queue Q) {
	return Q.front == Q.rear;
}

// 入队操作
void enQueue(Queue *Q, BiTNode *x) {
	QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
	newNode->data = x;
	newNode->next = NULL;
	Q->rear->next = newNode;
	Q->rear = newNode;
}

// 出队操作
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

// 判断二叉树是否为完全二叉树
bool isComplete(BiTree T) {
	if (T == NULL)
		return true;
	Queue Q;
	initQueue(&Q);
	enQueue(&Q, T);
	bool flag = false; // 用于标记是否遇到过叶子节点或只有左孩子的节点

	while (!isEmpty(Q)) {
		BiTNode *p;
		deQueue(&Q, &p);
		if (p->lchild != NULL) {
			if (flag)
				return false; // 如果已经遇到过叶子节点或只有左孩子的节点，则不是完全二叉树
			enQueue(&Q, p->lchild);
		} else {
			flag = true; // 遇到叶子节点或只有左孩子的节点
		}
		if (p->rchild != NULL) {
			if (flag)
				return false; // 如果已经遇到过叶子节点或只有左孩子的节点，则不是完全二叉树
			enQueue(&Q, p->rchild);
		} else {
			flag = true; // 遇到叶子节点或只有左孩子的节点
		}
	}
	return true;
}

// 示例使用
int main() {
	// 构建一个二叉树示例
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

	// 判断是否为完全二叉树
	if (isComplete(root)) {
		printf("The binary tree is a complete binary tree.\n");

	} else {
		printf("The binary tree is not a complete binary tree.\n");
	}

	// 释放内存
	free(root->lchild);
	free(root->rchild);
	free(root);

	return 0;
}

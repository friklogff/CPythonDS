// 判断是否是完全二叉树
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 15

typedef struct TreeNode {
	char data; // 节点数据
	struct TreeNode *leftChild, *rightChild; // 左右孩子指针
} TreeNode, *Tree;

/**
 * @brief 构建二叉树
 * @param t 指向二叉树根节点的指针
 */
void BuildTree(Tree *t) {
	char ch;
	ch = getchar();

	if (ch == '#') {
		*t = NULL;
	} else {
		*t = (TreeNode *)malloc(sizeof(TreeNode));
		(*t)->data = ch;
		(*t)->leftChild = NULL;
		(*t)->rightChild = NULL;

		BuildTree(&(*t)->leftChild);
		BuildTree(&(*t)->rightChild);
	}
}

typedef struct Queue {
	TreeNode *data[MAX_SIZE]; // 队列数组存储树节点指针
	int front, rear, tag;     // 队列头、尾指针和标记
} Queue;

/**
 * @brief 判断队列是否为空
 * @param q 队列
 * @return 是否为空
 */
bool IsEmpty(Queue q) {
	return (q.front == q.rear && q.tag == 0);
}

/**
 * @brief 判断队列是否满
 * @param q 队列
 * @return 是否为满
 */
bool IsFull(Queue q) {
	return (q.front == q.rear && q.tag == 1);
}

/**
 * @brief 入队操作
 * @param q 队列
 * @param p 树节点指针
 * @return 是否成功入队
 */
bool Enqueue(Queue *q, TreeNode *p) {
	if (IsFull(*q))
		return false;

	q->data[q->rear] = p;
	q->rear = (q->rear + 1) % MAX_SIZE;
	q->tag = 1;

	return true;
}

/**
 * @brief 出队操作
 * @param q 队列
 * @param p 指向出队节点指针的指针
 * @return 是否成功出队
 */
bool Dequeue(Queue *q, TreeNode **p) {
	if (IsEmpty(*q))
		return false;

	*p = q->data[q->front];
	q->front = (q->front + 1) % MAX_SIZE;
	q->tag = 0;

	return true;
}

/**
 * @brief 判断二叉树是否为完全二叉树
 * @param t 二叉树根节点指针
 * @return 是否为完全二叉树
 */
bool IsCompleteBinaryTree(Tree t) {
	Queue q;
	q.front = q.rear = q.tag = 0;

	bool flag = true, result = true;

	if (!t)
		return true;
	if (!t->leftChild && !t->rightChild)
		return true;

	Enqueue(&q, t);
	TreeNode *currentNode;

	while (!IsEmpty(q)) {
		Dequeue(&q, &currentNode);

		// 当前节点没有左孩子
		if (!currentNode->leftChild) {
			flag = false;
			// 当前节点有右孩子
			if (currentNode->rightChild)
				result = false;
		} else { // 当前节点有左孩子
			// 之前不存在缺孩子的节点
			if (flag) {
				Enqueue(&q, currentNode->leftChild);
				// 当前节点有右孩子
				if (currentNode->rightChild) {
					Enqueue(&q, currentNode->rightChild);
				} else {
					flag = false;
				}
			} else { // 之前存在缺孩子的节点
				result = false;
			}
		}
	}

	return result;
}

int main() {
	Tree t;
	BuildTree(&t); // 构建二叉树

	if (IsCompleteBinaryTree(t)) {
		printf("yes\n");


	} else {
		printf("no\n");
	}

	return 0;
}

// 示例输入:
// ABD##E##CF##G##  完全二叉树
// ABD###CE##F##  非完全二叉树

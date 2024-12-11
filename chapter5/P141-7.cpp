// �ж��Ƿ�����ȫ������
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 15

typedef struct TreeNode {
	char data; // �ڵ�����
	struct TreeNode *leftChild, *rightChild; // ���Һ���ָ��
} TreeNode, *Tree;

/**
 * @brief ����������
 * @param t ָ����������ڵ��ָ��
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
	TreeNode *data[MAX_SIZE]; // ��������洢���ڵ�ָ��
	int front, rear, tag;     // ����ͷ��βָ��ͱ��
} Queue;

/**
 * @brief �ж϶����Ƿ�Ϊ��
 * @param q ����
 * @return �Ƿ�Ϊ��
 */
bool IsEmpty(Queue q) {
	return (q.front == q.rear && q.tag == 0);
}

/**
 * @brief �ж϶����Ƿ���
 * @param q ����
 * @return �Ƿ�Ϊ��
 */
bool IsFull(Queue q) {
	return (q.front == q.rear && q.tag == 1);
}

/**
 * @brief ��Ӳ���
 * @param q ����
 * @param p ���ڵ�ָ��
 * @return �Ƿ�ɹ����
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
 * @brief ���Ӳ���
 * @param q ����
 * @param p ָ����ӽڵ�ָ���ָ��
 * @return �Ƿ�ɹ�����
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
 * @brief �ж϶������Ƿ�Ϊ��ȫ������
 * @param t ���������ڵ�ָ��
 * @return �Ƿ�Ϊ��ȫ������
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

		// ��ǰ�ڵ�û������
		if (!currentNode->leftChild) {
			flag = false;
			// ��ǰ�ڵ����Һ���
			if (currentNode->rightChild)
				result = false;
		} else { // ��ǰ�ڵ�������
			// ֮ǰ������ȱ���ӵĽڵ�
			if (flag) {
				Enqueue(&q, currentNode->leftChild);
				// ��ǰ�ڵ����Һ���
				if (currentNode->rightChild) {
					Enqueue(&q, currentNode->rightChild);
				} else {
					flag = false;
				}
			} else { // ֮ǰ����ȱ���ӵĽڵ�
				result = false;
			}
		}
	}

	return result;
}

int main() {
	Tree t;
	BuildTree(&t); // ����������

	if (IsCompleteBinaryTree(t)) {
		printf("yes\n");


	} else {
		printf("no\n");
	}

	return 0;
}

// ʾ������:
// ABD##E##CF##G##  ��ȫ������
// ABD###CE##F##  ����ȫ������

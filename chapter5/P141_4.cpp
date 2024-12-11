#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10 // ����ջ�Ͷ��е��������

// ����������ڵ�ṹ��
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
	ch = getchar(); // �������ж�ȡһ���ַ�

	if (ch == '#') { // �����ȡ�� '#'�����λ��Ϊ�սڵ�
		*t = NULL;
	} else {
		*t = (TreeNode *)malloc(sizeof(TreeNode)); // �����½ڵ���ڴ�
		(*t)->data = ch; // ����ȡ�����ַ���ֵ���ڵ�����
		(*t)->leftChild = NULL;
		(*t)->rightChild = NULL;

		BuildTree(&((*t)->leftChild)); // �ݹ鹹��������
		BuildTree(&((*t)->rightChild)); // �ݹ鹹��������
	}
}

// ����ջ�ṹ��
typedef struct Stack {
	TreeNode *data[MAX_SIZE]; // ջ����洢���ڵ�ָ��
	int top; // ջ��ָ��
} Stack;

/**
 * @brief �ж�ջ�Ƿ�Ϊ��
 * @param s ջ
 * @return �Ƿ�Ϊ��
 */
int IsEmptyStack(Stack s) {
	return s.top == -1; // ջ��ָ��Ϊ -1 ʱ��ʾջΪ��
}

/**
 * @brief �ж�ջ�Ƿ���
 * @param s ջ
 * @return �Ƿ�Ϊ��
 */
int IsFullStack(Stack s) {
	return s.top == MAX_SIZE - 1; // ջ��ָ��ﵽ�������ʱ��ʾջΪ��
}

/**
 * @brief ��ջ����
 * @param s ջ
 * @param p ���ڵ�ָ��
 * @return �Ƿ�ɹ���ջ
 */
int PushStack(Stack *s, TreeNode *p) {
	if (IsFullStack(*s)) { // ���ջ��������ӡ��ʾ��Ϣ������ʧ��
		printf("ջ��\n");
		return 0;
	}
	s->data[++(s->top)] = p; // ���ڵ�ָ��ѹ��ջ��������ջ��ָ��
	return 1;
}

/**
 * @brief ��ջ����
 * @param s ջ
 * @param p ָ���ջ�ڵ�ָ���ָ��
 * @return �Ƿ�ɹ���ջ
 */
int PopStack(Stack *s, TreeNode **p) {
	if (IsEmptyStack(*s)) { // ���ջΪ�գ���ӡ��ʾ��Ϣ������ʧ��
		printf("ջ��\n");
		return 0;
	}
	*p = s->data[(s->top)--]; // ��ջ��ָ��ָ��Ľڵ㵯����������ջ��ָ��
	return 1;
}

// ������нṹ��
typedef struct Queue {
	TreeNode *data[MAX_SIZE]; // ��������洢���ڵ�ָ��
	int front, rear, tag; // ����ͷ��βָ��ͱ��
} Queue;

/**
 * @brief ��Ӳ���
 * @param q ����
 * @param x ���ڵ�ָ��
 * @return �Ƿ�ɹ����
 */
int Enqueue(Queue *q, TreeNode *x) {
	if ((q->front == q->rear) && (q->tag == 1)) { // ���������������ӡ��ʾ��Ϣ������ʧ��
		printf("������\n");
		return 0;
	}
	q->data[q->rear] = x; // ���ڵ�ָ��������β��
	q->rear = (q->rear + 1) % MAX_SIZE; // ���¶���βָ�루ѭ�����У�
	q->tag = 1; // ���±��
	return 1;
}

/**
 * @brief ���Ӳ���
 * @param q ����
 * @param x ָ����ӽڵ�ָ���ָ��
 * @return �Ƿ�ɹ�����
 */
int Dequeue(Queue *q, TreeNode **x) {
	if ((q->front == q->rear) && (q->tag == 0)) { // �������Ϊ�գ���ӡ��ʾ��Ϣ������ʧ��
		printf("���п�\n");
		return 0;
	}
	*x = q->data[q->front]; // ������ͷ���Ľڵ�ָ�뵯��
	q->front = (q->front + 1) % MAX_SIZE; // ���¶���ͷָ�루ѭ�����У�
	q->tag = 0; // ���±��
	return 1;
}

/**
 * @brief ʹ��ջ�Ͷ��н���ض�����
 * @param t ���������ڵ�ָ��
 */
void Solve(Tree t) {
	Stack stack; // ����һ��ջ
	Queue queue; // ����һ������
	TreeNode *p; // ��ʱ�ڵ�ָ��

	if (t) { // ������ǿ�
		stack.top = -1; // ��ʼ��ջ��ָ��
		queue.front = queue.rear = queue.tag = 0; // ��ʼ������ָ��ͱ��

		Enqueue(&queue, t); // ���ڵ����
		while (!((queue.front == queue.rear) && (queue.tag == 0))) { // ���зǿ�
			Dequeue(&queue, &p); // �ڵ����
			PushStack(&stack, p); // �ڵ���ջ

			if (p->leftChild) // ���ӷǿգ��������
				Enqueue(&queue, p->leftChild);

			if (p->rightChild) // �Һ��ӷǿգ��Һ������
				Enqueue(&queue, p->rightChild);
		}

		while (!IsEmptyStack(stack)) { // ջ�ǿ�
			PopStack(&stack, &p); // �ڵ��ջ
			printf("%c ", p->data); // ��ӡ�ڵ�����
		}
	}
}

int main() {
	Tree t; // ���������ڵ�ָ��
	BuildTree(&t); // ����������
	Solve(t); // ʹ��ջ�Ͷ��н���ض�����
	return 0;
}

// ʾ������: ABD##E##CF##G##

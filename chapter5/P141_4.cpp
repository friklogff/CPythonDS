#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10 // 定义栈和队列的最大容量

// 定义二叉树节点结构体
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
	ch = getchar(); // 从输入中读取一个字符

	if (ch == '#') { // 如果读取到 '#'，则该位置为空节点
		*t = NULL;
	} else {
		*t = (TreeNode *)malloc(sizeof(TreeNode)); // 分配新节点的内存
		(*t)->data = ch; // 将读取到的字符赋值给节点数据
		(*t)->leftChild = NULL;
		(*t)->rightChild = NULL;

		BuildTree(&((*t)->leftChild)); // 递归构建左子树
		BuildTree(&((*t)->rightChild)); // 递归构建右子树
	}
}

// 定义栈结构体
typedef struct Stack {
	TreeNode *data[MAX_SIZE]; // 栈数组存储树节点指针
	int top; // 栈顶指针
} Stack;

/**
 * @brief 判断栈是否为空
 * @param s 栈
 * @return 是否为空
 */
int IsEmptyStack(Stack s) {
	return s.top == -1; // 栈顶指针为 -1 时表示栈为空
}

/**
 * @brief 判断栈是否满
 * @param s 栈
 * @return 是否为满
 */
int IsFullStack(Stack s) {
	return s.top == MAX_SIZE - 1; // 栈顶指针达到最大容量时表示栈为满
}

/**
 * @brief 入栈操作
 * @param s 栈
 * @param p 树节点指针
 * @return 是否成功入栈
 */
int PushStack(Stack *s, TreeNode *p) {
	if (IsFullStack(*s)) { // 如果栈已满，打印提示信息并返回失败
		printf("栈满\n");
		return 0;
	}
	s->data[++(s->top)] = p; // 将节点指针压入栈，并更新栈顶指针
	return 1;
}

/**
 * @brief 出栈操作
 * @param s 栈
 * @param p 指向出栈节点指针的指针
 * @return 是否成功出栈
 */
int PopStack(Stack *s, TreeNode **p) {
	if (IsEmptyStack(*s)) { // 如果栈为空，打印提示信息并返回失败
		printf("栈空\n");
		return 0;
	}
	*p = s->data[(s->top)--]; // 将栈顶指针指向的节点弹出，并更新栈顶指针
	return 1;
}

// 定义队列结构体
typedef struct Queue {
	TreeNode *data[MAX_SIZE]; // 队列数组存储树节点指针
	int front, rear, tag; // 队列头、尾指针和标记
} Queue;

/**
 * @brief 入队操作
 * @param q 队列
 * @param x 树节点指针
 * @return 是否成功入队
 */
int Enqueue(Queue *q, TreeNode *x) {
	if ((q->front == q->rear) && (q->tag == 1)) { // 如果队列已满，打印提示信息并返回失败
		printf("队列满\n");
		return 0;
	}
	q->data[q->rear] = x; // 将节点指针加入队列尾部
	q->rear = (q->rear + 1) % MAX_SIZE; // 更新队列尾指针（循环队列）
	q->tag = 1; // 更新标记
	return 1;
}

/**
 * @brief 出队操作
 * @param q 队列
 * @param x 指向出队节点指针的指针
 * @return 是否成功出队
 */
int Dequeue(Queue *q, TreeNode **x) {
	if ((q->front == q->rear) && (q->tag == 0)) { // 如果队列为空，打印提示信息并返回失败
		printf("队列空\n");
		return 0;
	}
	*x = q->data[q->front]; // 将队列头部的节点指针弹出
	q->front = (q->front + 1) % MAX_SIZE; // 更新队列头指针（循环队列）
	q->tag = 0; // 更新标记
	return 1;
}

/**
 * @brief 使用栈和队列解决特定问题
 * @param t 二叉树根节点指针
 */
void Solve(Tree t) {
	Stack stack; // 定义一个栈
	Queue queue; // 定义一个队列
	TreeNode *p; // 临时节点指针

	if (t) { // 如果树非空
		stack.top = -1; // 初始化栈顶指针
		queue.front = queue.rear = queue.tag = 0; // 初始化队列指针和标记

		Enqueue(&queue, t); // 根节点入队
		while (!((queue.front == queue.rear) && (queue.tag == 0))) { // 队列非空
			Dequeue(&queue, &p); // 节点出队
			PushStack(&stack, p); // 节点入栈

			if (p->leftChild) // 左孩子非空，左孩子入队
				Enqueue(&queue, p->leftChild);

			if (p->rightChild) // 右孩子非空，右孩子入队
				Enqueue(&queue, p->rightChild);
		}

		while (!IsEmptyStack(stack)) { // 栈非空
			PopStack(&stack, &p); // 节点出栈
			printf("%c ", p->data); // 打印节点数据
		}
	}
}

int main() {
	Tree t; // 定义树根节点指针
	BuildTree(&t); // 构建二叉树
	Solve(t); // 使用栈和队列解决特定问题
	return 0;
}

// 示例输入: ABD##E##CF##G##

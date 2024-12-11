//假设二叉树采用二叉链表存储结构，设计一个算法，求非空二叉树b的宽度(即具有结点数最多的那一层的结点个数)。
#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构体
typedef struct TreeNode {
	char data; // 节点数据
	struct TreeNode *leftChild, *rightChild; // 左右孩子指针
} TreeNode, *Tree;

// 定义队列结构体，用于存储树节点和层次信息
typedef struct {
	TreeNode *data[10]; // 队列存储的树节点
	int level[10]; // 树节点对应的层次
	int front, rear; // 队列的头尾指针
} Queue;

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

/**
 * @brief 计算二叉树的最大宽度
 * @param root 二叉树根节点指针
 * @return 二叉树的最大宽度
 */
int GetWidth(Tree root) {
	Queue Q; // 定义一个队列
	TreeNode *currentNode;
	int currentLevel;

	Q.front = Q.rear = -1; // 初始化队列的头尾指针

	// 根节点入队并设置其层次为1
	Q.rear++;
	Q.data[Q.rear] = root;
	Q.level[Q.rear] = 1;

	while (Q.front < Q.rear) { // 队列非空
		Q.front++;
		currentNode = Q.data[Q.front]; // 当前节点出队
		currentLevel = Q.level[Q.front]; // 获取当前节点的层次

		// 左孩子入队并设置其层次
		if (currentNode->leftChild != NULL) {
			Q.rear++;
			Q.data[Q.rear] = currentNode->leftChild;
			Q.level[Q.rear] = currentLevel + 1;
		}

		// 右孩子入队并设置其层次
		if (currentNode->rightChild != NULL) {
			Q.rear++;
			Q.data[Q.rear] = currentNode->rightChild;
			Q.level[Q.rear] = currentLevel + 1;
		}
	}

	int maxWidth = 0, i = 0, nodeCount;
	currentLevel = 1;

	while (i <= Q.rear) { // 遍历所有节点，计算每一层的宽度
		nodeCount = 0;

		// 统计当前层的节点数量
		while (i <= Q.rear && Q.level[i] == currentLevel) {
			nodeCount++;
			i++;
		}

		currentLevel = Q.level[i]; // 更新到下一层

		// 更新最大宽度
		if (nodeCount > maxWidth)
			maxWidth = nodeCount;
	}

	return maxWidth; // 返回二叉树的最大宽度
}

int main() {
	Tree t; // 定义树根节点指针
	BuildTree(&t); // 构建二叉树
	printf("%d\n", GetWidth(t)); // 计算并打印二叉树的最大宽度
	return 0;
}

/*
示例输入:
ABD##E##CF##G##

原始二叉树:
             A
          B    C
        D  E  F  G
 p  q
*/

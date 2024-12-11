#include <stdio.h>
#include <stdlib.h>

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

/**
 * @brief 计算二叉树的高度（层次遍历）
 * @param t 二叉树根节点指针
 * @return 树的高度
 */
int Depth(Tree t) {
	if (!t) // 如果树为空，返回高度为0
		return 0;

	Tree queue[10]; // 定义一个固定大小的队列，用于层次遍历
	int front = -1, rear = -1; // 初始化队列头尾指针
	int currentLevelEnd = 0, height = 0; // 当前层结束位置和树的高度

	queue[++rear] = t; // 根节点入队
	Tree p;

	while (front < rear) { // 队列非空
		p = queue[++front]; // 节点出队

		if (p->leftChild) // 左孩子非空，左孩子入队
			queue[++rear] = p->leftChild;

		if (p->rightChild) // 右孩子非空，右孩子入队
			queue[++rear] = p->rightChild;

		if (front == currentLevelEnd) { // 当前层已遍历完
			height++; // 增加树的高度
			currentLevelEnd = rear; // 更新当前层结束位置
		}
	}

	return height; // 返回树的高度
}

int main() {
	Tree t; // 定义树根节点指针
	BuildTree(&t); // 构建二叉树
	printf("树的高度为: %d\n", Depth(t)); // 打印树的高度
	return 0;
}
// 示例输入: ABD##E##CF##G##

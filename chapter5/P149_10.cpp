//该代码实现了从前序遍历序列构建二叉树，并查找前序遍历中的第 k 个节点的值。
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

// 全局变量，用于记录当前访问的节点序号
int currentIndex = 1;

/**
 * @brief 在前序遍历中找到第 k 个节点的值
 * @param t 二叉树根节点指针
 * @param k 要查找的节点序号
 * @return 第 k 个节点的值，如果不存在则返回 '#'
 */
char PreOrderKthNode(Tree t, int k) {
	if (t == NULL) // 如果节点为空，则返回 '#'
		return '#';
	if (currentIndex == k) // 如果当前节点是第 k 个节点，返回其值
		return t->data;
	currentIndex++; // 更新当前访问的节点序号

	char ch = PreOrderKthNode(t->leftChild, k); // 递归查找左子树中的第 k 个节点
	if (ch != '#') // 如果在左子树中找到了第 k 个节点，直接返回其值
		return ch;

	ch = PreOrderKthNode(t->rightChild, k); // 递归查找右子树中的第 k 个节点
	return ch; // 返回找到的节点值或者 '#'
}

int main() {
	Tree t; // 定义树根节点指针
	BuildTree(&t); // 构建二叉树
	printf("%c\n", PreOrderKthNode(t, 7)); // 查找并打印前序遍历中的第 7 个节点的值
	return 0;
}

/*
示例输入:
ABD##E##CF##G##
*/

/*
原始二叉树:
             A
          B    C
        D  E  F  G

前序遍历序列: ABD##E##CF##G##
*/

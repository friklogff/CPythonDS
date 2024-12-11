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
 * @brief 交换二叉树的所有左右子树
 * @param t 指向二叉树根节点的指针
 */
void SwapChildren(Tree *t) {
	TreeNode *temp;
	if (*t) {
		SwapChildren(&((*t)->leftChild)); // 递归交换左子树
		SwapChildren(&((*t)->rightChild)); // 递归交换右子树

		// 交换当前节点的左右子树
		temp = (*t)->leftChild;
		(*t)->leftChild = (*t)->rightChild;
		(*t)->rightChild = temp;
	}
}

/**
 * @brief 前序遍历并打印二叉树
 * @param t 二叉树根节点指针
 */
void PreOrderDisplay(Tree t) {
	if (t) {
		printf("%c ", t->data); // 打印当前节点的数据
		PreOrderDisplay(t->leftChild); // 递归遍历左子树
		PreOrderDisplay(t->rightChild); // 递归遍历右子树
	}
}

int main() {
	Tree t; // 定义树根节点指针
	BuildTree(&t); // 构建二叉树
	printf("交换过后的二叉树为(前序序列):\n");
	SwapChildren(&t); // 交换二叉树的所有左右子树
	PreOrderDisplay(t); // 前序遍历并打印二叉树
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

交换后的二叉树:
             A
          C    B
        G  F  E  D
*/

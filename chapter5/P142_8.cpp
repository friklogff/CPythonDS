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
 * @brief 统计二叉树中双分支节点的数量
 * @param t 二叉树根节点指针
 * @return 双分支节点的数量
 */
int CountDoubleBranchNodes(Tree t) {
	if (!t)
		return 0; // 如果节点为空，返回 0
	else if (t->leftChild && t->rightChild) // 如果左右孩子均不为空
		return CountDoubleBranchNodes(t->leftChild) + CountDoubleBranchNodes(t->rightChild) +
		       1; // 递归计算左右子树中的双分支节点并加 1
	else
		return CountDoubleBranchNodes(t->leftChild) + CountDoubleBranchNodes(t->rightChild); // 递归计算左右子树中的双分支节点
}

int main() {
	Tree t; // 定义树根节点指针
	BuildTree(&t); // 构建二叉树
	printf("该二叉树中双分结点有 %d 个\n", CountDoubleBranchNodes(t)); // 打印二叉树中双分支节点的数量
	return 0;
}

/*
       A
     /  \
    B    C
   / \   / \
  D   E F   G
*/
// 示例输入: ABD##E##CF##G##

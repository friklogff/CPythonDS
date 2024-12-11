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
 * @brief 释放二叉树的所有节点
 * @param t 指向二叉树根节点的指针
 */
void Release(Tree *t) {
	if (!(*t))
		return; // 节点为空时返回
	Release(&((*t)->leftChild)); // 递归释放左子树
	Release(&((*t)->rightChild)); // 递归释放右子树
	free(*t); // 释放当前节点
}

/**
 * @brief 删除二叉树中所有值为 x 的节点
 * @param T 二叉树根节点的指针
 * @param x 要删除的节点值
 */
void DeleteNodesWithValueX(Tree *T, char x) {
	if (*T == NULL)
		return; // 树为空时返回

	if ((*T)->data == x) { // 找到值为 x 的节点
		Release(T); // 释放该节点及其子树
		*T = NULL; // 将该节点指针设为 NULL
	}

	if (*T != NULL) { // 若当前节点未被删除，则继续检查左右子树
		DeleteNodesWithValueX(&((*T)->leftChild), x); // 递归删除左子树中值为 x 的节点
		DeleteNodesWithValueX(&((*T)->rightChild), x); // 递归删除右子树中值为 x 的节点
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
	DeleteNodesWithValueX(&t, 'A'); // 删除值为 'A' 的节点及其子树
	PreOrderDisplay(t); // 前序遍历并打印剩余的二叉树
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

删除值为 'A' 的节点后，树为空
*/

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
	scanf("%c", &ch); // 从输入中读取一个字符

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
 * @brief 判断两个二叉树是否相似
 * @param t1 第一个二叉树的根节点指针
 * @param t2 第二个二叉树的根节点指针
 * @return 如果两个二叉树相似，返回1；否则返回0
 */
int Similar(Tree t1, Tree t2) {
	int left, right;

	if (t1 == NULL && t2 == NULL)
		return 1; // 两棵树都是空树，相似
	else if (t1 == NULL || t2 == NULL)
		return 0; // 一棵树为空，另一棵树非空，不相似
	else {
		// 递归判断左右子树是否相似
		left = Similar(t1->leftChild, t2->leftChild);
		right = Similar(t1->rightChild, t2->rightChild);
		return (left && right); // 左右子树都相似才认为两棵树相似
	}
}

int main() {
	Tree t1, t2; // 定义树根节点指针
	BuildTree(&t1); // 构建第一棵二叉树
	BuildTree(&t2); // 构建第二棵二叉树

	printf("%d\n", Similar(t1, t2)); // 判断两棵二叉树是否相似，并打印结果

	return 0;
}

/*
示例输入:
AB###C#E##
AB###C#E##

原始二叉树1:
             A
          B

原始二叉树2:
          C
              E
*/

#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构体
typedef struct TreeNode {
	char data; // 节点数据
	struct TreeNode *leftChild, *rightChild; // 左右孩子指针
} TreeNode, *Tree;

int pos = 0; // 全局变量，用于记录当前构建到前序遍历序列的位置

/**
 * @brief 通过前序和中序遍历序列构建二叉树
 * @param preOrder 前序遍历序列数组
 * @param inOrder 中序遍历序列数组
 * @param start 起始位置（在inOrder中的索引）
 * @param end 结束位置（在inOrder中的索引）
 * @return 构建的二叉树的根节点
 */
Tree BuildTree(char preOrder[], char inOrder[], int start, int end) {
	if (start <= end) { // 如果起始位置小于等于结束位置，继续构建树
		TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode)); // 分配新节点的内存
		root->data = preOrder[pos]; // 取当前前序遍历序列中的节点作为根节点
		int i;
		for (i = start; i <= end; i++) // 在中序遍历序列中找到根节点的位置
			if (inOrder[i] == root->data)
				break;
		pos++; // 更新前序遍历的位置
		root->leftChild = BuildTree(preOrder, inOrder, start, i - 1); // 构建左子树
		root->rightChild = BuildTree(preOrder, inOrder, i + 1, end); // 构建右子树
		return root;
	}
	return NULL; // 起始位置大于结束位置时返回NULL
}

/**
 * @brief 后序遍历并打印二叉树
 * @param t 二叉树根节点
 */
void PostOrderDisplay(Tree t) {
	if (t) {
		PostOrderDisplay(t->leftChild); // 递归遍历左子树
		PostOrderDisplay(t->rightChild); // 递归遍历右子树
		printf("%c ", t->data); // 打印当前节点的数据
	}
}

int main() {
	char preOrder[] = {'A', 'B', 'D', 'E', 'C', 'F'};  // 先序序列
	char inOrder[] = {'D', 'B', 'E', 'A', 'F', 'C'};  // 中序序列
	Tree root = BuildTree(preOrder, inOrder, 0, 5); // 根据前序和中序序列构建二叉树
	printf("后序序列为:\n");
	PostOrderDisplay(root); // 后序遍历并打印二叉树
	return 0;
}

/*
          A
         / \
        B   C
       / \  /
      D  E F
*/

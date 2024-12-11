// 遍历二叉树的一个后续遍历方式
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	char data; // 节点数据
	struct TreeNode *leftChild, *rightChild; // 左右孩子指针
	int tag; // 标记，用于后序遍历
} TreeNode, *Tree;

/**
 * @brief 构建二叉树
 * @param t 指向二叉树根节点的指针
 */
void CreateTree(Tree *t) {
	char ch;
	ch = getchar();

	if (ch == '#') {
		*t = NULL;
	} else {
		*t = (TreeNode *)malloc(sizeof(TreeNode));
		(*t)->data = ch;
		(*t)->tag = 0;
		(*t)->leftChild = NULL;
		(*t)->rightChild = NULL;

		CreateTree(&(*t)->leftChild);
		CreateTree(&(*t)->rightChild);
	}
}

/**
 * @brief 后序遍历二叉树（非递归）
 * @param t 二叉树根节点指针
 */
void PostOrderTraversal(Tree t) {
	TreeNode *stack[100];
	int top = -1;
	TreeNode *p = t;
	TreeNode *x;

	while (p || top != -1) {
		if (p) {
			top++;
			stack[top] = p;
			p = p->leftChild;
		} else {
			p = stack[top];
			if (p->rightChild && p->rightChild->tag == 0) {
				p = p->rightChild;
			} else {
				p = stack[top];
				top--;
				printf("%c ", p->data);
				p->tag = 1;
				p = NULL;
			}
		}
	}
}

int main() {
	Tree t;
	CreateTree(&t); // 构建二叉树
	PostOrderTraversal(t); // 后序遍历二叉树
	return 0;
}

// 示例输入:
// ABD##E##C##

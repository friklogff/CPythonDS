#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

// 二叉树结点定义
typedef struct BiTNode {
	int data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// 创建二叉树
BiTree createBinaryTree() {
	BiTree root = (BiTree)malloc(sizeof(BiTNode));
	root->data = 1;

	root->lchild = (BiTree)malloc(sizeof(BiTNode));
	root->lchild->data = 2;
	root->lchild->lchild = NULL;
	root->lchild->rchild = NULL;

	root->rchild = (BiTree)malloc(sizeof(BiTNode));
	root->rchild->data = 3;
	root->rchild->lchild = NULL;
	root->rchild->rchild = NULL;

	return root;
}

// 前序遍历
void preOrderTraversal(BiTree T) {
	if (T == NULL)
		return;

	printf("%d ", T->data);
	preOrderTraversal(T->lchild);
	preOrderTraversal(T->rchild);
}

// 中序遍历
void inOrderTraversal(BiTree T) {
	if (T == NULL)
		return;

	inOrderTraversal(T->lchild);
	printf("%d ", T->data);
	inOrderTraversal(T->rchild);
}

// 后序遍历
void postOrderTraversal(BiTree T) {
	if (T == NULL)
		return;

	postOrderTraversal(T->lchild);
	postOrderTraversal(T->rchild);
	printf("%d ", T->data);
}

// 层序遍历
void levelOrderTraversal(BiTree root) {
	if (root == NULL)
		return;

	BiTree queue[100];
	int front = 0, rear = 0;

	queue[rear++] = root;

	while (front < rear) {
		BiTree node = queue[front++];
		printf("%d ", node->data);

		if (node->lchild != NULL)
			queue[rear++] = node->lchild;

		if (node->rchild != NULL)
			queue[rear++] = node->rchild;
	}
}

// 求二叉树的高度
int getHeight(BiTree T) {
	if (T == NULL)
		return 0;

	int leftHeight = getHeight(T->lchild);
	int rightHeight = getHeight(T->rchild);

	return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// 计算二叉树的宽度
int getTreeWidth(BiTree root) {
	if (root == NULL)
		return 0;

	int maxWidth = 0;
	BiTree queue[100];
	int front = 0, rear = 0;

	queue[rear++] = root;

	while (front < rear) {
		int width = rear - front;  // 当前层的节点数量

		if (width > maxWidth) {
			maxWidth = width;
		}

		for (int i = 0; i < width; i++) {
			BiTree node = queue[front++];

			if (node->lchild != NULL) {
				queue[rear++] = node->lchild;
			}
			if (node->rchild != NULL) {
				queue[rear++] = node->rchild;
			}
		}
	}

	return maxWidth;
}

// 计算二叉树的带权路径长度（WPL）
int calculateWPL(BiTree root, int depth) {
	if (root == NULL)
		return 0;
	if (root->lchild == NULL && root->rchild == NULL) {
		// 叶子节点的带权路径长度为深度乘以节点值
		return depth * root->data;
	}
	// 递归计算左右子树的带权路径长度并相加
	return calculateWPL(root->lchild, depth + 1) + calculateWPL(root->rchild, depth + 1);
}

// 判定一棵二叉树是否为二叉排序树
bool isBSTUtil(BiTree root, int min, int max) {
	if (root == NULL)
		return true;

	if (root->data < min || root->data > max)
		return false;

	return isBSTUtil(root->lchild, min, root->data - 1) && isBSTUtil(root->rchild, root->data + 1, max);
}

bool isBST(BiTree root) {
	return isBSTUtil(root, INT_MIN, INT_MAX);
}

// 判定一棵二叉树是否平衡
int checkHeight(BiTree root) {
	if (root == NULL)
		return 0;

	int leftHeight = checkHeight(root->lchild);
	if (leftHeight == -1)
		return -1;

	int rightHeight = checkHeight(root->rchild);
	if (rightHeight == -1)
		return -1;

	int heightDiff = abs(leftHeight - rightHeight);
	if (heightDiff > 1)
		return -1;

	return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

bool isBalanced(BiTree root) {
	return checkHeight(root) != -1;
}

// 判定一棵二叉树是否为完全二叉树
bool isCompleteBinaryTree(BiTree root) {
	if (root == NULL)
		return true;

	BiTree queue[100];
	int front = 0, rear = 0;
	queue[rear++] = root;

	bool flag = false;

	while (front < rear) {
		BiTree node = queue[front++];

		if (node == NULL) {
			flag = true;
		} else {
			if (flag)
				return false;

			queue[rear++] = node->lchild;
			queue[rear++] = node->rchild;
		}
	}

	return true;
}

int main() {
	BiTree root = createBinaryTree();

	printf("前序遍历结果：");
	preOrderTraversal(root);
	printf("\n");

	printf("中序遍历结果：");
	inOrderTraversal(root);
	printf("\n");

	printf("后序遍历结果：");
	postOrderTraversal(root);
	printf("\n");

	printf("层序遍历结果：");
	levelOrderTraversal(root);
	printf("\n");

	printf("二叉树高度为：%d\n", getHeight(root));

	printf("二叉树的宽度为：%d\n", getTreeWidth(root));

	printf("二叉树的带权路径长度（WPL）为：%d\n", calculateWPL(root, 0));

	printf("该二叉树是否为二叉排序树？%s\n", isBST(root) ? "是" : "否");

	printf("该二叉树是否平衡？%s\n", isBalanced(root) ? "是" : "否");

	printf("该二叉树是否为完全二叉树？%s\n", isCompleteBinaryTree(root) ? "是" : "否");

	return 0;
}
#include <stdio.h>
#include <stdlib.h>

// 二叉树结点的定义
typedef struct BiTNode {
	int data;
	struct BiTNode *lchild;
	struct BiTNode *rchild;
} BiTNode, *BiTree;

// 创建二叉搜索树
void insertBSTNode(BiTree *root, int data) {
	if (*root == NULL) {
		*root = (BiTree)malloc(sizeof(BiTNode));
		(*root)->data = data;
		(*root)->lchild = NULL;
		(*root)->rchild = NULL;
	} else {
		if (data < (*root)->data) {
			insertBSTNode(&(*root)->lchild, data);
		} else {
			insertBSTNode(&(*root)->rchild, data);
		}
	}
}

// 创建平衡二叉树
BiTree createBalancedBinaryTree(int arr[], int start, int end) {
	if (start > end) {
		return NULL;
	}

	int mid = (start + end) / 2;
	BiTree root = (BiTree)malloc(sizeof(BiTNode));
	root->data = arr[mid];
	root->lchild = createBalancedBinaryTree(arr, start, mid - 1);
	root->rchild = createBalancedBinaryTree(arr, mid + 1, end);

	return root;
}

// 创建完全二叉树
BiTree createCompleteBinaryTree(int arr[], int index, int size) {
	if (index >= size) {
		return NULL;
	}

	BiTree root = (BiTree)malloc(sizeof(BiTNode));
	root->data = arr[index];
	root->lchild = createCompleteBinaryTree(arr, 2 * index + 1, size);
	root->rchild = createCompleteBinaryTree(arr, 2 * index + 2, size);

	return root;
}

// 前序遍历二叉树
void PreOrder(BiTree T) {
	if (T != NULL) {
		printf("%d ", T->data);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}

// 释放二叉树内存
void FreeBiTree(BiTree root) {
	if (root != NULL) {
		FreeBiTree(root->lchild);
		FreeBiTree(root->rchild);
		free(root);
	}
}

int main() {
	// 创建二叉搜索树
	BiTree bstRoot = NULL;
	insertBSTNode(&bstRoot, 5);
	insertBSTNode(&bstRoot, 3);
	insertBSTNode(&bstRoot, 7);
	insertBSTNode(&bstRoot, 2);
	insertBSTNode(&bstRoot, 4);

	// 创建平衡二叉树
	int arr[] = {1, 2, 3, 4, 5, 6, 7};
	BiTree balancedRoot = createBalancedBinaryTree(arr, 0, 6);

	// 创建完全二叉树
	int completeArr[] = {1, 2, 3, 4, 5, 6, 7};
	BiTree completeRoot = createCompleteBinaryTree(completeArr, 0, 7);

	// 遍历并释放二叉搜索树
	printf("二叉搜索树前序遍历：");
	PreOrder(bstRoot);
	printf("\n");
	FreeBiTree(bstRoot);

	// 遍历并释放平衡二叉树
	printf("平衡二叉树前序遍历：");
	PreOrder(balancedRoot);
	printf("\n");
	FreeBiTree(balancedRoot);

	// 遍历并释放完全二叉树
	printf("完全二叉树前序遍历：");
	PreOrder(completeRoot);
	printf("\n");
	FreeBiTree(completeRoot);

	return 0;
}

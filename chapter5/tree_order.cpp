#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

// ��������㶨��
typedef struct BiTNode {
	int data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// ����������
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

// ǰ�����
void preOrderTraversal(BiTree T) {
	if (T == NULL)
		return;

	printf("%d ", T->data);
	preOrderTraversal(T->lchild);
	preOrderTraversal(T->rchild);
}

// �������
void inOrderTraversal(BiTree T) {
	if (T == NULL)
		return;

	inOrderTraversal(T->lchild);
	printf("%d ", T->data);
	inOrderTraversal(T->rchild);
}

// �������
void postOrderTraversal(BiTree T) {
	if (T == NULL)
		return;

	postOrderTraversal(T->lchild);
	postOrderTraversal(T->rchild);
	printf("%d ", T->data);
}

// �������
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

// ��������ĸ߶�
int getHeight(BiTree T) {
	if (T == NULL)
		return 0;

	int leftHeight = getHeight(T->lchild);
	int rightHeight = getHeight(T->rchild);

	return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// ����������Ŀ��
int getTreeWidth(BiTree root) {
	if (root == NULL)
		return 0;

	int maxWidth = 0;
	BiTree queue[100];
	int front = 0, rear = 0;

	queue[rear++] = root;

	while (front < rear) {
		int width = rear - front;  // ��ǰ��Ľڵ�����

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

// ����������Ĵ�Ȩ·�����ȣ�WPL��
int calculateWPL(BiTree root, int depth) {
	if (root == NULL)
		return 0;
	if (root->lchild == NULL && root->rchild == NULL) {
		// Ҷ�ӽڵ�Ĵ�Ȩ·������Ϊ��ȳ��Խڵ�ֵ
		return depth * root->data;
	}
	// �ݹ�������������Ĵ�Ȩ·�����Ȳ����
	return calculateWPL(root->lchild, depth + 1) + calculateWPL(root->rchild, depth + 1);
}

// �ж�һ�ö������Ƿ�Ϊ����������
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

// �ж�һ�ö������Ƿ�ƽ��
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

// �ж�һ�ö������Ƿ�Ϊ��ȫ������
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

	printf("ǰ����������");
	preOrderTraversal(root);
	printf("\n");

	printf("������������");
	inOrderTraversal(root);
	printf("\n");

	printf("������������");
	postOrderTraversal(root);
	printf("\n");

	printf("������������");
	levelOrderTraversal(root);
	printf("\n");

	printf("�������߶�Ϊ��%d\n", getHeight(root));

	printf("�������Ŀ��Ϊ��%d\n", getTreeWidth(root));

	printf("�������Ĵ�Ȩ·�����ȣ�WPL��Ϊ��%d\n", calculateWPL(root, 0));

	printf("�ö������Ƿ�Ϊ������������%s\n", isBST(root) ? "��" : "��");

	printf("�ö������Ƿ�ƽ�⣿%s\n", isBalanced(root) ? "��" : "��");

	printf("�ö������Ƿ�Ϊ��ȫ��������%s\n", isCompleteBinaryTree(root) ? "��" : "��");

	return 0;
}
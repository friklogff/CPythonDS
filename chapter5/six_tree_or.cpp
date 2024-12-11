#include <stdio.h>
#include <stdlib.h>

// ���������Ķ���
typedef struct BiTNode {
	int data;
	struct BiTNode *lchild;
	struct BiTNode *rchild;
} BiTNode, *BiTree;

// ��������������
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

// ����ƽ�������
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

// ������ȫ������
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

// ǰ�����������
void PreOrder(BiTree T) {
	if (T != NULL) {
		printf("%d ", T->data);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}

// �ͷŶ������ڴ�
void FreeBiTree(BiTree root) {
	if (root != NULL) {
		FreeBiTree(root->lchild);
		FreeBiTree(root->rchild);
		free(root);
	}
}

int main() {
	// ��������������
	BiTree bstRoot = NULL;
	insertBSTNode(&bstRoot, 5);
	insertBSTNode(&bstRoot, 3);
	insertBSTNode(&bstRoot, 7);
	insertBSTNode(&bstRoot, 2);
	insertBSTNode(&bstRoot, 4);

	// ����ƽ�������
	int arr[] = {1, 2, 3, 4, 5, 6, 7};
	BiTree balancedRoot = createBalancedBinaryTree(arr, 0, 6);

	// ������ȫ������
	int completeArr[] = {1, 2, 3, 4, 5, 6, 7};
	BiTree completeRoot = createCompleteBinaryTree(completeArr, 0, 7);

	// �������ͷŶ���������
	printf("����������ǰ�������");
	PreOrder(bstRoot);
	printf("\n");
	FreeBiTree(bstRoot);

	// �������ͷ�ƽ�������
	printf("ƽ�������ǰ�������");
	PreOrder(balancedRoot);
	printf("\n");
	FreeBiTree(balancedRoot);

	// �������ͷ���ȫ������
	printf("��ȫ������ǰ�������");
	PreOrder(completeRoot);
	printf("\n");
	FreeBiTree(completeRoot);

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// ���������Ķ���
typedef struct BiTNode {
	int data;
	struct BiTNode *lchild;
	struct BiTNode *rchild;
} BiTNode, *BiTree;

// ��������������
void insertBSTNode(BiTree &root, int data) {
	if (root == NULL) {
		root = (BiTree)malloc(sizeof(BiTNode));
		root->data = data;
		root->lchild = NULL;
		root->rchild = NULL;
	} else {
		if (data < root->data) {
			insertBSTNode(root->lchild, data);
		} else {
			insertBSTNode(root->rchild, data);
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



// �ͷŶ������ڴ�
void FreeBiTree(BiTree root) {
	if (root != NULL) {
		FreeBiTree(root->lchild);
		FreeBiTree(root->rchild);
		free(root);
	}
}

// ǰ�����������
void PreOrder(BiTree T) {
	if (T != NULL) {
		printf("%d ", T->data);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}
// ��������ĸ߶�
int height = 0;

int getHeight_PreOrder(BiTree T, int n) {
	if (T == NULL)
		return 0;
	if (n > height)
		height = n;
	getHeight_PreOrder(T->lchild, n + 1);
	getHeight_PreOrder(T->rchild, n + 1);

}
// ��������Ŀ��

int width[100];

void getWidth_PreOrder(BiTree T, int n) {
	if (T == NULL)
		return ;
	width[n]++;
	getWidth_PreOrder(T->lchild, n + 1);
	getWidth_PreOrder(T->rchild, n + 1);
}

void treeVidth(BiTree T) {
	for (int i = 0; i < 100; i++)
		width[i] = 0;
	getWidth_PreOrder(T, 0);
	int maxWidth = 0;
	for (int i = 0; i < 100; i++)
		if (width[i] > maxWidth)
			maxWidth = width[i];
	printf("���Ŀ����%d", maxWidth);
}
// ���������wpl
int WPL = 0;

void wpl_PreOrder(BiTree T, int n) {
	if (T == NULL)
		return ;
	if (T->lchild == NULL && T->rchild == NULL)
		WPL += n * T->data;
	getWidth_PreOrder(T->lchild, n + 1);
	getWidth_PreOrder(T->rchild, n + 1);
}


void InOrder(BiTree T) {
	if (T == NULL)
		return ;
	InOrder(T->lchild);
	printf("%d ", T->data);
	InOrder(T->rchild);

}

//����������
int temp = INT_MIN;
bool isBST = true;
void PX_InOrder(BiTree T) {
	if (T == NULL)
		return ;
	PX_InOrder(T->lchild);
	if (T->data >= temp)
		temp = T->data;
	else
		isBST = false;

	PX_InOrder(T->rchild);

}

void PostOrder(BiTree T) {
	if (T == NULL)
		return ;
	PostOrder(T->lchild);
	PostOrder(T->rchild);
	printf("%d ", T->data);


}
//����ƽ����
bool isBalance = true;

int PH_PostOrder(BiTree T) {
	if (T == NULL)
		return 0;
	int left = PH_PostOrder(T->lchild);
	int right = PH_PostOrder(T->rchild);
	if ( left - right > 1)
		isBalance = false;
	if ( left - right < -1)
		isBalance = false;
	if ( left > right > 1)
		return left + 1;
	else
		return right + 1;


}


int getHeight_PostOrder(BiTree T, int n) {
	if (T == NULL)
		return 0;
	int left = getHeight_PostOrder(T->lchild, n + 1);
	int right = getHeight_PostOrder(T->rchild, n + 1);
	if (left > right)
		return left + 1;
	else
		return right + 1;
}


int main() {
	// ��������������
	BiTree bstRoot = NULL;
	insertBSTNode(bstRoot, 5);
	insertBSTNode(bstRoot, 3);
	insertBSTNode(bstRoot, 7);
	insertBSTNode(bstRoot, 2);
	insertBSTNode(bstRoot, 4);

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

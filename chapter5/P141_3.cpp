// ������������һ������������ʽ
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	char data; // �ڵ�����
	struct TreeNode *leftChild, *rightChild; // ���Һ���ָ��
	int tag; // ��ǣ����ں������
} TreeNode, *Tree;

/**
 * @brief ����������
 * @param t ָ����������ڵ��ָ��
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
 * @brief ����������������ǵݹ飩
 * @param t ���������ڵ�ָ��
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
	CreateTree(&t); // ����������
	PostOrderTraversal(t); // �������������
	return 0;
}

// ʾ������:
// ABD##E##C##

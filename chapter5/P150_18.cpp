#include <stdio.h>
#include <stdlib.h>

// �������������ṹ��
typedef struct TreeNode {
	char data; // ����ֵ
	struct TreeNode *leftChild, *rightChild; // ���Һ���ָ��
	int ltag, rtag; // ��־λ��1 ��ʾ������0 ��ʾ����
} TreeNode, *Tree;

/**
 * @brief ����������
 * @param t ָ����������ڵ��ָ��
 */
void BuildTree(Tree *t) {
	char ch;
	scanf("%c", &ch); // �������ж�ȡһ���ַ�

	if (ch == '#') { // �����ȡ�� '#'�����λ��Ϊ�սڵ�
		*t = NULL;
	} else {
		*t = (TreeNode *)malloc(sizeof(TreeNode)); // �����½ڵ���ڴ�
		(*t)->data = ch; // ����ȡ�����ַ���ֵ���ڵ�����
		(*t)->leftChild = NULL;
		(*t)->rightChild = NULL;
		(*t)->ltag = (*t)->rtag = 0; // ��ʼ����־λ

		BuildTree(&((*t)->leftChild)); // �ݹ鹹��������
		BuildTree(&((*t)->rightChild)); // �ݹ鹹��������
	}
}

TreeNode *pre = NULL; // ȫ�ֱ��������ڱ������������ǰһ������Ľڵ�

/**
 * @brief ���������������������
 * @param t ���������ڵ��ָ��
 */
void InorderThreading(Tree *t) {
	if (*t) { // �ݹ��������ȷ����ǰ�ڵ㲻Ϊ��
		InorderThreading(&((*t)->leftChild)); // �������죬��Ҷ�ӽ��

		if ((*t)->leftChild == NULL) { // ����Ϊ�գ���������
			(*t)->ltag = 1;
			(*t)->leftChild = pre;
		}

		if (pre != NULL && pre->rightChild == NULL) { // ǰ�����û���Һ��ӣ���������
			pre->rtag = 1; // ǰ�����ָ��ǰ���
			pre->rightChild = *t;
		}

		pre = *t; // ����ǰ�����
		InorderThreading(&((*t)->rightChild)); // ���ҵݹ�
	}
}

/**
 * @brief �����������������в���ָ������ں����ǰ�����
 * @param t ���������ڵ�ָ��
 * @param p ָ�����ָ��
 * @return ����ǰ�����ָ��
 */
TreeNode *FindPostOrderPredecessor(Tree t, TreeNode *p) {
	TreeNode *q;

	if (p->rtag == 0) { // ���ý�����Һ��ӣ������ǰ����Ϊ���Һ���
		q = p->rightChild;
	} else if (p->ltag == 0) { // ���ý�����Һ��ӵ������ӣ������ǰ����Ϊ������
		q = p->leftChild;
	} else if (p->leftChild == NULL) { // ���ý��Ϊ�����һ����㣬�޺���ǰ��
		q = NULL;
	} else {
		while (p->ltag == 1 && p->leftChild != NULL) { // �������ҵ����Ƚ��
			p = p->leftChild;
		}
		if (p->ltag == 0) { // ���ҵ����Ƚ���������ӣ������ǰ����Ϊ������
			q = p->leftChild;
		} else {
			q = NULL; // �����޺���ǰ��
		}
	}

	return q;
}

// ������ ����
int main() {
	Tree t;
	BuildTree(&t); // ����������
	InorderThreading(&t); // ���������������������

	// ����ָ���ڵ��ں�������е�ǰ����㣬����Ӹ����Һ��ӿ�ʼ�����ں����е�ǰ�����
	TreeNode *postPredecessor = FindPostOrderPredecessor(t, t->rightChild);
	if (postPredecessor != NULL) {
		printf("%c\n", postPredecessor->data); // ����ҵ���ǰ���ڵ������
	} else {
		printf("NULL\n"); // ���û���ҵ�ǰ���ڵ㣬���NULL
	}

	return 0;
}

/*
ʾ������:
ABD##E##CF##G##

ԭʼ������:
             A
          B    C
        D  E  F  G

ABD##E##CF##G##
*/

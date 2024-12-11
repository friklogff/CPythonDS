#include <stdio.h>
#include <stdlib.h>

// ����������ڵ�ṹ��
typedef struct TreeNode {
	char data; // �ڵ�����
	struct TreeNode *leftChild, *rightChild; // ���Һ���ָ��
} TreeNode, *Tree;

/**
 * @brief ����������
 * @param t ָ����������ڵ��ָ��
 */
void BuildTree(Tree *t) {
	char ch;
	ch = getchar(); // �������ж�ȡһ���ַ�

	if (ch == '#') { // �����ȡ�� '#'�����λ��Ϊ�սڵ�
		*t = NULL;
	} else {
		*t = (TreeNode *)malloc(sizeof(TreeNode)); // �����½ڵ���ڴ�
		(*t)->data = ch; // ����ȡ�����ַ���ֵ���ڵ�����
		(*t)->leftChild = NULL;
		(*t)->rightChild = NULL;

		BuildTree(&((*t)->leftChild)); // �ݹ鹹��������
		BuildTree(&((*t)->rightChild)); // �ݹ鹹��������
	}
}

/**
 * @brief ������������������������
 * @param t ָ����������ڵ��ָ��
 */
void SwapChildren(Tree *t) {
	TreeNode *temp;
	if (*t) {
		SwapChildren(&((*t)->leftChild)); // �ݹ齻��������
		SwapChildren(&((*t)->rightChild)); // �ݹ齻��������

		// ������ǰ�ڵ����������
		temp = (*t)->leftChild;
		(*t)->leftChild = (*t)->rightChild;
		(*t)->rightChild = temp;
	}
}

/**
 * @brief ǰ���������ӡ������
 * @param t ���������ڵ�ָ��
 */
void PreOrderDisplay(Tree t) {
	if (t) {
		printf("%c ", t->data); // ��ӡ��ǰ�ڵ������
		PreOrderDisplay(t->leftChild); // �ݹ����������
		PreOrderDisplay(t->rightChild); // �ݹ����������
	}
}

int main() {
	Tree t; // ���������ڵ�ָ��
	BuildTree(&t); // ����������
	printf("��������Ķ�����Ϊ(ǰ������):\n");
	SwapChildren(&t); // ������������������������
	PreOrderDisplay(t); // ǰ���������ӡ������
	return 0;
}

/*
ʾ������:
ABD##E##CF##G##
*/

/*
ԭʼ������:
             A
          B    C
        D  E  F  G

������Ķ�����:
             A
          C    B
        G  F  E  D
*/

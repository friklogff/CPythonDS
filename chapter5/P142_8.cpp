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
 * @brief ͳ�ƶ�������˫��֧�ڵ������
 * @param t ���������ڵ�ָ��
 * @return ˫��֧�ڵ������
 */
int CountDoubleBranchNodes(Tree t) {
	if (!t)
		return 0; // ����ڵ�Ϊ�գ����� 0
	else if (t->leftChild && t->rightChild) // ������Һ��Ӿ���Ϊ��
		return CountDoubleBranchNodes(t->leftChild) + CountDoubleBranchNodes(t->rightChild) +
		       1; // �ݹ�������������е�˫��֧�ڵ㲢�� 1
	else
		return CountDoubleBranchNodes(t->leftChild) + CountDoubleBranchNodes(t->rightChild); // �ݹ�������������е�˫��֧�ڵ�
}

int main() {
	Tree t; // ���������ڵ�ָ��
	BuildTree(&t); // ����������
	printf("�ö�������˫�ֽ���� %d ��\n", CountDoubleBranchNodes(t)); // ��ӡ��������˫��֧�ڵ������
	return 0;
}

/*
       A
     /  \
    B    C
   / \   / \
  D   E F   G
*/
// ʾ������: ABD##E##CF##G##

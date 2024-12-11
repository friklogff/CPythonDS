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
	scanf("%c", &ch); // �������ж�ȡһ���ַ�

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
 * @brief �ж������������Ƿ�����
 * @param t1 ��һ���������ĸ��ڵ�ָ��
 * @param t2 �ڶ����������ĸ��ڵ�ָ��
 * @return ����������������ƣ�����1�����򷵻�0
 */
int Similar(Tree t1, Tree t2) {
	int left, right;

	if (t1 == NULL && t2 == NULL)
		return 1; // ���������ǿ���������
	else if (t1 == NULL || t2 == NULL)
		return 0; // һ����Ϊ�գ���һ�����ǿգ�������
	else {
		// �ݹ��ж����������Ƿ�����
		left = Similar(t1->leftChild, t2->leftChild);
		right = Similar(t1->rightChild, t2->rightChild);
		return (left && right); // �������������Ʋ���Ϊ����������
	}
}

int main() {
	Tree t1, t2; // ���������ڵ�ָ��
	BuildTree(&t1); // ������һ�ö�����
	BuildTree(&t2); // �����ڶ��ö�����

	printf("%d\n", Similar(t1, t2)); // �ж����ö������Ƿ����ƣ�����ӡ���

	return 0;
}

/*
ʾ������:
AB###C#E##
AB###C#E##

ԭʼ������1:
             A
          B

ԭʼ������2:
          C
              E
*/

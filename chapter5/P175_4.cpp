#include <stdio.h>
#include <stdlib.h>

// �ṹ�嶨��
typedef struct TreeNode {
	// ���ֵ
	char data;
	// ����������ֵ���ָ��
	struct TreeNode *child, *rbro;
} TreeNode, *Tree;

/**
 * @brief ���������ֵܱ�ʾ����ɭ��
 * @param t ָ�������ڵ��ָ��
 */
void BuildTree(Tree *t) {
	char ch;
	scanf("%c", &ch); // �������ж�ȡһ���ַ�

	if (ch == '#') { // �����ȡ�� '#'�����λ��Ϊ�սڵ�
		*t = NULL;
	} else {
		// �����½ڵ���ڴ�
		*t = (TreeNode *)malloc(sizeof(TreeNode));
		// ����ȡ�����ַ���ֵ���ڵ�����
		(*t)->data = ch;
		// ��ʼ�����Һ���������ֵ���Ϊ��
		(*t)->child = NULL;
		(*t)->rbro = NULL;

		// �ݹ鹹�����Ӻ����ֵ�����
		BuildTree(&((*t)->child));
		BuildTree(&((*t)->rbro));
	}
}

/**
 * @brief �ݹ���㺢���ֵܱ�ʾ���洢�����е�Ҷ�ӽ����
 * @param t �����ڵ�ָ��
 * @return Ҷ�ӽ����
 */
int CountLeaves(Tree t) {
	if (t == NULL)
		return 0; // �սڵ㷵��0

	// �����ǰ�ڵ������Ϊ�գ�����Ҷ�ӽڵ�
	if (t->child == NULL)
		return 1 + CountLeaves(t->rbro); // �����1���������ֵ�������Ҷ�ӽ����

	// ���򣬽��Ϊ�������������ֵ�������Ҷ�ӽ����֮��
	return CountLeaves(t->child) + CountLeaves(t->rbro);
}

// ����������
int main() {
	Tree t;
	BuildTree(&t); // ���������ֵܱ�ʾ����ɭ��
	printf("%d\n", CountLeaves(t)); // ���Ҷ�ӽ����
	return 0;
}

/*
ʾ������:
ABD#E##C##FG###

ԭʼ��:
         A
     B        F
  D     C   G
   \
    E
*/


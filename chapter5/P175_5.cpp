#include <stdio.h>
#include <stdlib.h>

// �������ڵ�ṹ��
typedef struct TreeNode {
	// ���ֵ
	char data;
	// ����������ֵ���ָ��
	struct TreeNode *child, *rbro;
} TreeNode, *Tree;

/**
 * @brief ���������ֵܱ�ʾ������
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
 * @brief �ݹ���㺢���ֵܱ�ʾ���洢���������
 * @param t �����ڵ�ָ��
 * @return �������
 */
int CalculateDepth(Tree t) {
	if (t == NULL)
		return 0; // ��������0

	// �ݹ�������������߶�
	int lDepth = CalculateDepth(t->child);
	// �ݹ�������ֵ������߶�
	int rDepth = CalculateDepth(t->rbro);

	// ���ص�ǰ���������
	// ���������+1����ǰ�ڵ㣩�����ֵ��������֮��ȡ�ϴ�ֵ
	return (lDepth + 1 > rDepth) ? (lDepth + 1) : rDepth;
}

// ����������
int main() {
	Tree t;
	BuildTree(&t); // ���������ֵܱ�ʾ������
	printf("%d\n", CalculateDepth(t)); // ����������
	return 0;
}

/*
ʾ������:
ABD#E##CF####

ԭʼ��:
                 A
             B
         D       C
           E   F
*/


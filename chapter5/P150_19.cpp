#include <stdio.h>
#include <stdlib.h>

// �ṹ�嶨��
typedef struct TreeNode {
	// ����ֵ��Ȩ�أ�
	char weight;
	// ���Һ���ָ��
	struct TreeNode *leftChild, *rightChild;
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
		// �����½ڵ���ڴ�
		*t = (TreeNode *)malloc(sizeof(TreeNode));
		// ����ȡ�����ַ���ֵ�����Ȩ��
		(*t)->weight = ch;
		// ��ʼ�����Һ���ָ��Ϊ��
		(*t)->leftChild = NULL;
		(*t)->rightChild = NULL;

		// �ݹ鹹����������������
		BuildTree(&((*t)->leftChild));
		BuildTree(&((*t)->rightChild));
	}
}

/**
 * @brief �����Ȩ·������֮�ͣ�WPL��
 * @param t ���������ڵ�ָ��
 * @param depth ��ǰ�ڵ�����
 * @return ��Ȩ·������֮��
 */
int CalculateWPL(Tree t, int depth) {
	static int wpl = 0; // ��̬���������ڴ洢���ֵ���ں���ĩβ����

	if (t != NULL) {
		// ����Ҷ�ӽ�㣬�ۼ���Ȩ�س�����ȵ�ֵ
		if (t->leftChild == NULL && t->rightChild == NULL) {
			wpl += (depth * ((t->weight) - '0'));
		}

		// ������Ҷ�ӽ�㣬�ݹ������������Ҷ�ӽ�㣬�����ӵ�ǰ���
		CalculateWPL(t->leftChild, depth + 1);
		// �ݹ������������Ҷ�ӽ�㣬�����ӵ�ǰ���
		CalculateWPL(t->rightChild, depth + 1);
	}

	return wpl;
}

// ����������
int main() {
	Tree t;
	BuildTree(&t); // ����������
	printf("%d\n", CalculateWPL(t, 0)); // �����Ȩ·������֮��
	return 0;
}

/*
ʾ������:
124##5##36##7##

ԭʼ������:
             1
          2    3
        4  5  6  7

��Ȩ·������֮�� (WPL):
ans = (4*2 + 5*2 + 6*2 + 7*2) = 44
*/

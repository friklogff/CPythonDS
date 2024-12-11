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
 * @brief �ͷŶ����������нڵ�
 * @param t ָ����������ڵ��ָ��
 */
void Release(Tree *t) {
	if (!(*t))
		return; // �ڵ�Ϊ��ʱ����
	Release(&((*t)->leftChild)); // �ݹ��ͷ�������
	Release(&((*t)->rightChild)); // �ݹ��ͷ�������
	free(*t); // �ͷŵ�ǰ�ڵ�
}

/**
 * @brief ɾ��������������ֵΪ x �Ľڵ�
 * @param T ���������ڵ��ָ��
 * @param x Ҫɾ���Ľڵ�ֵ
 */
void DeleteNodesWithValueX(Tree *T, char x) {
	if (*T == NULL)
		return; // ��Ϊ��ʱ����

	if ((*T)->data == x) { // �ҵ�ֵΪ x �Ľڵ�
		Release(T); // �ͷŸýڵ㼰������
		*T = NULL; // ���ýڵ�ָ����Ϊ NULL
	}

	if (*T != NULL) { // ����ǰ�ڵ�δ��ɾ��������������������
		DeleteNodesWithValueX(&((*T)->leftChild), x); // �ݹ�ɾ����������ֵΪ x �Ľڵ�
		DeleteNodesWithValueX(&((*T)->rightChild), x); // �ݹ�ɾ����������ֵΪ x �Ľڵ�
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
	DeleteNodesWithValueX(&t, 'A'); // ɾ��ֵΪ 'A' �Ľڵ㼰������
	PreOrderDisplay(t); // ǰ���������ӡʣ��Ķ�����
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

ɾ��ֵΪ 'A' �Ľڵ����Ϊ��
*/

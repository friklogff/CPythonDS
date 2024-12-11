#include <stdio.h>
#include <stdlib.h>

// ����������ڵ�ṹ��
typedef struct TreeNode {
	char data; // �ڵ�ֵ
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

// ȫ�ֱ�����ͷ����ǰ�����
Tree head = NULL, pre = NULL;

/**
 * @brief �������������������Ҷ��㰴�����ҵ�˳������һ��������
 * @param t ���������ڵ�ָ��
 * @return ͷ���
 */
Tree Inorder(Tree t) {
	if (t) { // �����ǰ�ڵ㲻Ϊ��
		Inorder(t->leftChild); // �ݹ鴦��������

		// ����Ҷ�ӽڵ�
		if (t->leftChild == NULL && t->rightChild == NULL) {
			if (pre == NULL) { // ��һ��Ҷ�ӽڵ�
				head = t; // ͷ��㸳ֵΪ��ǰ�ڵ�
				pre = t; // ǰ��������Ϊ��ǰ�ڵ�
			} else { // �ǵ�һ��Ҷ�ӽڵ�
				pre->rightChild = t; // ǰ��������ָ��ָ��ǰ�ڵ�
				pre = t; // ����ǰ�����
			}
		}

		Inorder(t->rightChild); // �ݹ鴦��������
	}

	return head; // ����ͷ���
}

int main() {
	Tree t; // ���������ڵ�ָ��
	BuildTree(&t); // ����������

	Tree leafList = Inorder(t); // ����������Ҷ������ɵ�����
	while (leafList) { // ��������ӡ������
		printf("%c ", leafList->data);
		leafList = leafList->rightChild;
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

������:
D E F G
*/

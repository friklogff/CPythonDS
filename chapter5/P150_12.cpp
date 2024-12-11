#include <stdio.h>
#include <stdlib.h>

// ����������ڵ�ṹ��
typedef struct TreeNode {
	char data; // �ڵ�����
	struct TreeNode *leftChild, *rightChild; // ���Һ���ָ��
} TreeNode, *Tree;

// ����ջ�ṹ�壬���ڴ洢���ڵ�ͱ��
typedef struct {
	TreeNode *node; // ���ڵ�ָ��
	int tag; // ��ǣ���ʾ�Ƿ��ѷ���������
} StackElement;

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
 * @brief ���Ҹ����������������ڵ�������������
 * @param t ���������ڵ�
 * @param p ��һ�������ҵĽڵ�
 * @param q �ڶ��������ҵĽڵ�
 * @return ����������Ƚڵ��ָ�룬����������򷵻�NULL
 */
TreeNode *Ancestor(Tree t, TreeNode *p, TreeNode *q) {
	StackElement S1[10], S2[10]; // ���ڴ洢·����ջ
	int top1 = 0, top2 = 0;
	TreeNode *current = t;

	while (current != NULL || top1 > 0) {
		while (current != NULL) { // ����������
			S1[++top1].node = current;
			S1[top1].tag = 0;
			current = current->leftChild;
		}

		while (top1 != 0 && S1[top1].tag == 1) { // ���������������
			if (S1[top1].node == p) { // �ҵ���һ���ڵ�
				for (int i = 1; i <= top1; i++) {
					S2[i] = S1[i];
				}
				top2 = top1;
			}

			if (S1[top1].node == q) { // �ҵ��ڶ����ڵ�
				for (int i = top1; i > 0; i--) {
					for (int j = top2; j > 0; j--) {
						if (S2[j].node == S1[i].node)
							return S1[i].node; // ���������������
					}
				}
			}

			top1--;
		}

		if (top1 != 0) {
			S1[top1].tag = 1;
			current = S1[top1].node->rightChild; // ����������
		}
	}

	return NULL; // û���ҵ��������ȣ�����NULL
}

int main() {
	Tree t; // ���������ڵ�ָ��
	BuildTree(&t); // ����������
	TreeNode *p = t->rightChild->leftChild; // ָ��ڵ�F
	TreeNode *q = t->rightChild->rightChild; // ָ��ڵ�G

	TreeNode *ancestor = Ancestor(t, p, q); // ���������������
	if (ancestor != NULL) {
		printf("%c\n", ancestor->data); // ��ӡ����������Ƚڵ������
	} else {
		printf("�޹�������\n");
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
              p  q
*/

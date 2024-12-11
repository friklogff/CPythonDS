#include <stdio.h>
#include <stdlib.h>

// �ṹ�嶨��
typedef struct TreeNode {
	// ���ֵ
	char data;
	// ����ָ������ֵ�ָ��
	struct TreeNode *child, *rbro;
} TreeNode, *Tree;

/**
 * @brief ���캢��-�ֵ������ʾ����
 * @param t ָ�������ڵ��ָ��
 * @param elements ��α�����������
 * @param degrees ÿ�����Ķ�����
 * @param n ���鳤��
 */
void CreateTree(Tree *t, char elements[], int degrees[], int n) {
	// ��̬����������
	Tree *nodes = (TreeNode **)malloc(n * sizeof(TreeNode *));

	for (int i = 0; i < n; i++) {
		// ��ÿ����㶯̬�����ڴ�
		nodes[i] = (TreeNode *)malloc(sizeof(TreeNode));
		// ��ֵ����㲢��ʼ������ָ��Ϊ��
		nodes[i]->data = elements[i];
		nodes[i]->child = nodes[i]->rbro = NULL;
	}

	// ���ӽ�����
	int k = 0;

	// ���ո����Ľ��˳����ʽ��
	for (int i = 0; i < n; i++) {
		// ��ȡ�ý��Ķ�
		int d = degrees[i];

		// ����жȣ�˵���к��ӽ��
		if (d > 0) {
			// ������ŵ���
			k++;
			// ����һ��������Ϊ�Լ������ӽ��
			nodes[i]->child = nodes[k];

			// ʣ��ĺ��ӣ�ÿ���������Ϊǰһ�������ֵܽ��
			for (int j = 2; j <= d; j++) {
				// ������ŵ���
				k++;
				// ǰһ���������ֵ�ָ��ָ��ǰ���ӽ��
				nodes[k - 1]->rbro = nodes[k];
			}
		}
	}

	*t = nodes[0]; // ���ڵ�ָ���һ�����
	free(nodes); // �ͷŶ�̬������ڴ�
}

/**
 * @brief �������-�ֵ������ʾ����������������
 * @param t �����ڵ�ָ��
 */
void PrintPreOrder(Tree t) {
	if (t != NULL) {
		printf("%c ", t->data);
		PrintPreOrder(t->child);
		PrintPreOrder(t->rbro);
	}
}

// ����������
int main() {
	// �����ڵ�ָ��
	Tree t;
	// ��α�������
	char elements[8] = "ABCDEFG";
	// ÿ�����Ķ�����
	int degrees[8] = {3, 2, 1, 0, 0, 0, 0};

	// ���캢��-�ֵ������ʾ����
	CreateTree(&t, elements, degrees, 7);

	// �������������������֤
	PrintPreOrder(t);
	return 0;
}

/*
ʾ������:
elements: ABCDEFG
degrees: 3210000

ԭʼ��:
                   A
             B     C     D
           E   F   G

����ĺ���-�ֵ������ʾ����:
                   A
                B
            E      C
               F  G  D

����������:
A B E C F G D
*/


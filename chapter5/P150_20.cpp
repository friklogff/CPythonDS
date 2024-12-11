#include <stdio.h>
#include <stdlib.h>

// �������ڵ�ṹ��
typedef struct TreeNode {
	char data; // ���ֵ
	struct TreeNode *leftChild, *rightChild; // ���Һ��ӵ�ָ��
} TreeNode, *Tree;

// �������ʽ��
/**
 * brief   �������ʽ��
 * param   t   ���ĸ��ڵ�ָ��
 */
void buildTree(Tree *t) {
	char ch;
	// ��ȡһ���ַ�����
	scanf(" %c", &ch);
	// �ж��Ƿ�Ϊ������־
	if (ch == '#') {
		*t = NULL; // ����ǽ�����־����ǰ��Ϊ��
	} else {
		// �����ڴ�ռ����ǰ�ڵ�
		*t = (TreeNode *)malloc(sizeof(TreeNode));
		// ����ȡ���ַ���ֵ���ڵ��������
		(*t)->data = ch;
		// ��ʼ�����Һ���ָ��Ϊ��
		(*t)->leftChild = NULL;
		(*t)->rightChild = NULL;
		// �ݹ鹹��������
		buildTree(&((*t)->leftChild));
		// �ݹ鹹��������
		buildTree(&((*t)->rightChild));
	}
}

// �����ʽ��ת������׺���ʽ
/**
 * brief   �����ʽ��ת������׺���ʽ���
 * param   t     ���ĸ��ڵ�
 * param   depth ��ǰ������
 */
void treeToInfixExpr(Tree t, int depth) {
	// �����Ϊ�գ�ֱ�ӷ���
	if (t == NULL)
		return;

	// �����Ҷ�ӽڵ㣬ֱ���������
	else if (t->leftChild == NULL && t->rightChild == NULL) {
		printf("%c", t->data);
	} else {
		// �����ǰ��ȴ���1�����������
		if (depth > 1)
			printf("(");

		// �ݹ鴦������������ȼ�1
		treeToInfixExpr(t->leftChild, depth + 1);
		// �����ǰ�ڵ�����
		printf("%c", t->data);
		// �ݹ鴦������������ȼ�1
		treeToInfixExpr(t->rightChild, depth + 1);

		// �����ǰ��ȴ���1�����������
		if (depth > 1)
			printf(")");
	}
}

// �����������Ա��ʽ���Ĺ�������׺���ʽ���
int main() {
	Tree t; // �������ĸ��ڵ�
	// �������ʽ��
	buildTree(&t);
	// �����ʽ��ת������׺���ʽ�����
	treeToInfixExpr(t, 1);
	return 0;
}

/*

        *
    +       *
  a   b   c   -
  *+a##b##*c##-#d##

            +
        *      -
    a    b         -
                c     d

  +*a##b##-#-c##d##

   +
 a   b
  +a##b##

*/

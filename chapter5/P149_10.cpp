//�ô���ʵ���˴�ǰ��������й�����������������ǰ������еĵ� k ���ڵ��ֵ��
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

// ȫ�ֱ��������ڼ�¼��ǰ���ʵĽڵ����
int currentIndex = 1;

/**
 * @brief ��ǰ��������ҵ��� k ���ڵ��ֵ
 * @param t ���������ڵ�ָ��
 * @param k Ҫ���ҵĽڵ����
 * @return �� k ���ڵ��ֵ������������򷵻� '#'
 */
char PreOrderKthNode(Tree t, int k) {
	if (t == NULL) // ����ڵ�Ϊ�գ��򷵻� '#'
		return '#';
	if (currentIndex == k) // �����ǰ�ڵ��ǵ� k ���ڵ㣬������ֵ
		return t->data;
	currentIndex++; // ���µ�ǰ���ʵĽڵ����

	char ch = PreOrderKthNode(t->leftChild, k); // �ݹ�����������еĵ� k ���ڵ�
	if (ch != '#') // ��������������ҵ��˵� k ���ڵ㣬ֱ�ӷ�����ֵ
		return ch;

	ch = PreOrderKthNode(t->rightChild, k); // �ݹ�����������еĵ� k ���ڵ�
	return ch; // �����ҵ��Ľڵ�ֵ���� '#'
}

int main() {
	Tree t; // ���������ڵ�ָ��
	BuildTree(&t); // ����������
	printf("%c\n", PreOrderKthNode(t, 7)); // ���Ҳ���ӡǰ������еĵ� 7 ���ڵ��ֵ
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

ǰ���������: ABD##E##CF##G##
*/

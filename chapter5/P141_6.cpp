#include <stdio.h>
#include <stdlib.h>

// ����������ڵ�ṹ��
typedef struct TreeNode {
	char data; // �ڵ�����
	struct TreeNode *leftChild, *rightChild; // ���Һ���ָ��
} TreeNode, *Tree;

int pos = 0; // ȫ�ֱ��������ڼ�¼��ǰ������ǰ��������е�λ��

/**
 * @brief ͨ��ǰ�������������й���������
 * @param preOrder ǰ�������������
 * @param inOrder ���������������
 * @param start ��ʼλ�ã���inOrder�е�������
 * @param end ����λ�ã���inOrder�е�������
 * @return �����Ķ������ĸ��ڵ�
 */
Tree BuildTree(char preOrder[], char inOrder[], int start, int end) {
	if (start <= end) { // �����ʼλ��С�ڵ��ڽ���λ�ã�����������
		TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode)); // �����½ڵ���ڴ�
		root->data = preOrder[pos]; // ȡ��ǰǰ����������еĽڵ���Ϊ���ڵ�
		int i;
		for (i = start; i <= end; i++) // ����������������ҵ����ڵ��λ��
			if (inOrder[i] == root->data)
				break;
		pos++; // ����ǰ�������λ��
		root->leftChild = BuildTree(preOrder, inOrder, start, i - 1); // ����������
		root->rightChild = BuildTree(preOrder, inOrder, i + 1, end); // ����������
		return root;
	}
	return NULL; // ��ʼλ�ô��ڽ���λ��ʱ����NULL
}

/**
 * @brief �����������ӡ������
 * @param t ���������ڵ�
 */
void PostOrderDisplay(Tree t) {
	if (t) {
		PostOrderDisplay(t->leftChild); // �ݹ����������
		PostOrderDisplay(t->rightChild); // �ݹ����������
		printf("%c ", t->data); // ��ӡ��ǰ�ڵ������
	}
}

int main() {
	char preOrder[] = {'A', 'B', 'D', 'E', 'C', 'F'};  // ��������
	char inOrder[] = {'D', 'B', 'E', 'A', 'F', 'C'};  // ��������
	Tree root = BuildTree(preOrder, inOrder, 0, 5); // ����ǰ����������й���������
	printf("��������Ϊ:\n");
	PostOrderDisplay(root); // �����������ӡ������
	return 0;
}

/*
          A
         / \
        B   C
       / \  /
      D  E F
*/
